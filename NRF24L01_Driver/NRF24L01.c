/*
 * NRF24L01.c
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#define NRF24L01_LIB

#include "NRF24L01.h"

uint8_t temp = 0;


static const struct NRF24L01_Command
{
    uint8_t R_REGISTER;
    uint8_t W_REGISTER;
    uint8_t R_RX_PAYLOAD;
    uint8_t W_TX_PAYLOAD;
    uint8_t FLUSH_TX;
    uint8_t FLUSH_RX;
    uint8_t REUSE_TX_PL;
    uint8_t R_RX_PL_WID;
    const struct {
        uint8_t BASE;
        uint8_t PIPE0;
        uint8_t PIPE1;
        uint8_t PIPE2;
        uint8_t PIPE3;
        uint8_t PIPE4;
        uint8_t PIPE5;
    } W_ACK_PAYLOAD;
    uint8_t W_TX_PAYLOAD_NOACK;
    uint8_t NOP;
} NRF24L01_Command = {
    .R_REGISTER =   0x00,
    .W_REGISTER = 0x20,
    .R_RX_PAYLOAD = 0x61,
    .W_TX_PAYLOAD =  0xA0,
    .FLUSH_TX =  0xE1,
    .FLUSH_RX = 0xE2,
    .REUSE_TX_PL =  0xE3,
    .R_RX_PL_WID = 0x60,
    .W_ACK_PAYLOAD = {.BASE = 0xA8, .PIPE0 = 0xA8, .PIPE1 = 0xA9, .PIPE2 = 0xAA, .PIPE3 = 0xAB, .PIPE4 = 0xAC, .PIPE5 = 0xAD},
    .W_TX_PAYLOAD_NOACK =  0xB0,
    .NOP  = 0xFF,
};



static const struct NRF24L01_Reg
{
    // Configuration Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t Disable; // 1: Interrupt not reflected on the IRQ pin
            uint8_t Enable;  // 0: Reflect RX_DR as active low interrupt on the IRQ pin
        } MASK_RX_DR;

        struct {
            uint8_t Disable; // 1: Interrupt not reflected on the IRQ pin
            uint8_t Enable;  // 0: Reflect TX_DS as active low interrupt on the IRQ pin
        } MASK_TX_DS;

        struct {
            uint8_t Disable; // 1: Interrupt not reflected on the IRQ pin
            uint8_t Enable;  // 0: Reflect MAX_RT as active low interrupt on the IRQ pin
        } MASK_MAX_RT;

        struct {
            uint8_t Enable;  // 1: Enable CRC
            uint8_t Disable; // 0: Disable CRC (Forced high if one of the bits in the EN_AA is high)
        } EN_CRC;

        struct {
            uint8_t ONE_BYTE;  // 0: 1 byte
            uint8_t TWO_BYTES; // 1: 2 bytes
        } CRCO;

        struct {
            uint8_t POWER_UP;   // 1: POWER UP
            uint8_t POWER_DOWN; // 0: POWER DOWN
        } PWR_UP;

        struct {
            uint8_t PRX; // 1: PRX (Primary RX)
            uint8_t PTX; // 0: PTX (Primary TX)
        } PRIM_RX;

    } CONFIG;

    // Enable Auto Acknowledgment Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t ADDR_0; // 1: Enable data pipe 0
            uint8_t ADDR_1; // 1: Enable data pipe 1
            uint8_t ADDR_2; // 1: Enable data pipe 2
            uint8_t ADDR_3; // 1: Enable data pipe 3
            uint8_t ADDR_4; // 1: Enable data pipe 4
            uint8_t ADDR_5; // 1: Enable data pipe 5
            uint8_t Reserved; // Reserved
            uint8_t ADDR_ALL; // 1: Enable RX address on all data pipes
        } ENAA;

    } EN_AA;

    // Enable RX Addresses Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t ADDR_0; // 1: Enable data pipe 0
            uint8_t ADDR_1; // 1: Enable data pipe 1
            uint8_t ADDR_2; // 1: Enable data pipe 2
            uint8_t ADDR_3; // 1: Enable data pipe 3
            uint8_t ADDR_4; // 1: Enable data pipe 4
            uint8_t ADDR_5; // 1: Enable data pipe 5
            uint8_t Reserved; // Reserved
            uint8_t ADDR_ALL; // 1: Enable RX address on all data pipes
        } EN_RXADDR;

    } EN_RXADDR;

    // Setup of Automatic Retransmission Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t ARC; // Automatic Retransmission Count (0-15)
        } SETUP_RTR;

    } SETUP_RETR;

    // RF Setup Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t RATE_1MBPS;   // 00: 1Mbps
            uint8_t RATE_2MBPS;   // 01: 2Mbps
            uint8_t RATE_250KBPS; // 10: 250kbps
            uint8_t Reserved;     // Reserved
        } RF_DR_HIGH;

        struct {
            uint8_t Reserved; // Reserved
            uint8_t PLL_LOCK; // Force PLL lock signal. Only used in test
        } RF_DR_LOW;

        struct {
            uint8_t POWER_NEG18DBM; // 00: -18dBm
            uint8_t POWER_NEG12DBM; // 01: -12dBm
            uint8_t POWER_NEG6DBM;  // 10: -6dBm
            uint8_t POWER_0DBM;     // 11: 0dBm
        } RF_PWR;

        struct {
            uint8_t CONT_WAVE_ON;  // 1: Continuous carrier transmit
            uint8_t CONT_WAVE_OFF; // 0: No carrier
        } CONT_WAVE;

        struct {
            uint8_t RF_DR_LOW_LOW; // Reserved
            uint8_t PLL_LOCK_RDY;  // 1: PLL lock is ready
        } Reserved;

        struct {
            uint8_t ARC_0; // Automatic Retransmission Count 0 (no retransmissions)
            uint8_t ARC_1; // Automatic Retransmission Count 1 (1 retransmission)
            uint8_t ARC_2; // Automatic Retransmission Count 2 (2 retransmissions)
            uint8_t ARC_3; // Automatic Retransmission Count 3 (3 retransmissions)
        } ARC;

    } RF_SETUP;

    // Receiver Address Data Pipe Registers (0 to 5)
    const struct {
        uint8_t REGISTER;
        uint64_t ADDRESS;
    } RX_ADDR_P0, RX_ADDR_P1, RX_ADDR_P2, RX_ADDR_P3, RX_ADDR_P4, RX_ADDR_P5;

    // Transmit Address Register
    const struct {
        uint8_t REGISTER;
        uint64_t ADDRESS;
    } TX_ADDR;

    // Payload Width Register (Pipe 0 to 5)
    const struct {
        uint8_t REGISTER;
        uint8_t WIDTH;
    } RX_PW_P0, RX_PW_P1, RX_PW_P2, RX_PW_P3, RX_PW_P4, RX_PW_P5;


    // Status Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t TX_FULL;   // 1: TX FIFO full
            uint8_t RX_P_NO;   // Data Pipe Number for the payload available for reading
            uint8_t MAX_RT;    // 1: MAX_RT reached
            uint8_t TX_DS;     // 1: Data sent TX_DS
            uint8_t RX_DR;     // 1: Data ready RX_DR
            uint8_t Reserved2;
        } STATUS;


    } STATUS;



    // FIFO Status Register
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t RX_EMPTY; // 1: RX FIFO empty
            uint8_t RX_FULL;  // 1: RX FIFO full
            uint8_t Reserved1;
            uint8_t TX_EMPTY; // 1: TX FIFO empty
            uint8_t TX_FULL;  // 1: TX FIFO full
            uint8_t TX_REUSE; // 1: TX_REUSE flag
        } FIFOSTATUS;

    } FIFO_STATUS;

    // Enable Dynamic Payload Length
    const struct {
        uint8_t REGISTER;
        uint8_t DPL_P0 : 1;
        uint8_t DPL_P1 : 1;
        uint8_t DPL_P2 : 1;
        uint8_t DPL_P3 : 1;
        uint8_t DPL_P4 : 1;
        uint8_t DPL_P5 : 1;
        uint8_t Reserved : 2;
    } DYNPD;

    // Feature Register
    const struct {
        uint8_t REGISTER;
        uint8_t EN_DPL : 1;  // Enable dynamic payload length
        uint8_t EN_ACK_PAY : 1; // Enable payload with ACK
        uint8_t EN_DYN_ACK : 1; // Enable W_TX_PAYLOAD_NOACK command
        uint8_t Reserved : 5;
    } FEATURE;


    // Setup of Address Widths
    const struct {
        uint8_t REGISTER;

        struct {
            uint8_t Illegal; // 1: RX FIFO empty
            uint8_t Byte_3;  // 1: RX FIFO full
            uint8_t Byte_4;
            uint8_t Byte_5; // 1: TX FIFO empty
        } AW;

    } SETUP_AW;

    } NRF24L01_Reg = {
        .CONFIG = {
            .REGISTER = 0x00,
            .MASK_RX_DR = {.Disable = 1 << 6, .Enable = 0 << 6},
            .MASK_TX_DS = {.Disable = 1 << 5, .Enable = 0 << 5},
            .MASK_MAX_RT = {.Disable = 1 << 4, .Enable = 0 << 4},
            .EN_CRC = {.Disable = 0 << 3, .Enable = 1 << 3},
            .CRCO = {.ONE_BYTE = 0 << 2, .TWO_BYTES = 1 << 2},
            .PWR_UP = {.POWER_UP = 1 << 1, .POWER_DOWN = 0 << 1},
            .PRIM_RX = {.PRX = 1 << 0, .PTX = 0 << 0},
        },

        .EN_AA = {
            .REGISTER = 0x01,
            .ENAA = {.ADDR_0 = 1 << 0, .ADDR_1 = 1 << 1, .ADDR_2 = 1 << 2, .ADDR_3 = 1 << 3,
                     .ADDR_4 = 1 << 4, .ADDR_5 = 1 << 5, .Reserved = 0 << 6, .ADDR_ALL = 1 << 7},
        },

        .EN_RXADDR = {
            .REGISTER = 0x02,
            .EN_RXADDR = {.ADDR_0 = 1 << 0, .ADDR_1 = 1 << 1, .ADDR_2 = 1 << 2, .ADDR_3 = 1 << 3,
                          .ADDR_4 = 1 << 4, .ADDR_5 = 1 << 5, .Reserved = 0 << 6, .ADDR_ALL = 1 << 7},
        },

        .SETUP_RETR = {
            .REGISTER = 0x04,
            .SETUP_RTR = {.ARC = 0x03}, // Default Automatic Retransmission Count (3)
        },

        .RF_SETUP = {
            .REGISTER = 0x06,
            .RF_DR_HIGH = {.RATE_1MBPS = 0 << 3, .RATE_2MBPS = 1 << 3, .RATE_250KBPS = 2 << 3, .Reserved = 3 << 3},
            .RF_DR_LOW = {.Reserved = 0 << 5, .PLL_LOCK = 1 << 4},
            .RF_PWR = {.POWER_NEG18DBM = 0 << 1, .POWER_NEG12DBM = 1 << 1, .POWER_NEG6DBM = 2 << 1, .POWER_0DBM = 3 << 1},
            .CONT_WAVE = {.CONT_WAVE_ON = 1 << 7, .CONT_WAVE_OFF = 0 << 7},
            .Reserved = {.RF_DR_LOW_LOW = 0 << 6, .PLL_LOCK_RDY = 1 << 4},
            .ARC = {.ARC_0 = 0 << 4, .ARC_1 = 1 << 4, .ARC_2 = 2 << 4, .ARC_3 = 3 << 4},
        },

        .RX_ADDR_P0 = {.REGISTER = 0x0A, .ADDRESS = 0x0000000000},
        .RX_ADDR_P1 = {.REGISTER = 0x0B, .ADDRESS = 0x0000000000},
        .RX_ADDR_P2 = {.REGISTER = 0x0C, .ADDRESS = 0x00},
        .RX_ADDR_P3 = {.REGISTER = 0x0D, .ADDRESS = 0x00},
        .RX_ADDR_P4 = {.REGISTER = 0x0E, .ADDRESS = 0x00},
        .RX_ADDR_P5 = {.REGISTER = 0x0F, .ADDRESS = 0x00},

        .TX_ADDR = {.REGISTER = 0x10, .ADDRESS = 0x0000000000},

        .RX_PW_P0 = {.REGISTER = 0x11, .WIDTH = 0x00},
        .RX_PW_P1 = {.REGISTER = 0x12, .WIDTH = 0x00},
        .RX_PW_P2 = {.REGISTER = 0x13, .WIDTH = 0x00},
        .RX_PW_P3 = {.REGISTER = 0x14, .WIDTH = 0x00},
        .RX_PW_P4 = {.REGISTER = 0x15, .WIDTH = 0x00},
        .RX_PW_P5 = {.REGISTER = 0x16, .WIDTH = 0x00},

        .FIFO_STATUS = {.REGISTER = 0x17,
                        .FIFOSTATUS = {.RX_EMPTY = 1 << 0, .RX_FULL = 1 << 1, .Reserved1 = 0 << 2,
            		                    .TX_EMPTY = 1 << 4, .TX_FULL = 1 << 5, .TX_REUSE = 1 << 6},
            		    },

        .STATUS = {.REGISTER = 0x07,
            	   .STATUS = {.TX_FULL = 1 << 0,
            			      .RX_P_NO = 0 << 1,
							  .MAX_RT = 1 << 4,
            		          .TX_DS = 1 << 5,
							  .RX_DR = 1 << 6,
							  .Reserved2 = 0 << 7},
            	   },

		.DYNPD = {
			.REGISTER = 0x1C,
			.DPL_P0 = 0,
			.DPL_P1 = 0,
			.DPL_P2 = 0,
			.DPL_P3 = 0,
			.DPL_P4 = 0,
			.DPL_P5 = 0,
			.Reserved = 0,
		},


		.FEATURE = {
			.REGISTER = 0x1D,
			.EN_DPL = 0,
			.EN_ACK_PAY = 0,
			.EN_DYN_ACK = 0,
			.Reserved = 0,
		},

        .SETUP_AW = {.REGISTER = 0x07,
            	     .AW = {.Illegal = 0 << 0,
            			     .Byte_3 = 1 << 1,
							 .Byte_4 = 2 << 4,
            		         .Byte_5 = 3 << 5,
        					},
            	   },
  };



SPI_Config nrf24_spi;

#define READ_COMMAND 0x1F
#define WRITE_COMMAND 0x20

/*******************************************************************************************************/
static uint8_t read_register(NRF24L01_Config *config,uint8_t reg)
{

	SPI_NSS_Low(&config->NRF24L01_SPI_Driver);
	temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, reg & READ_COMMAND);
	SPI_NSS_High(&config->NRF24L01_SPI_Driver);
	return temp;
}

static void write_register(NRF24L01_Config *config,uint8_t reg, uint8_t data)
{

	SPI_NSS_Low(&config->NRF24L01_SPI_Driver);
	temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, reg & WRITE_COMMAND);
	temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, data);
	SPI_NSS_High(&config->NRF24L01_SPI_Driver);
}

static uint8_t cmd(NRF24L01_Config *config,uint8_t command)
{

	SPI_NSS_Low(&config->NRF24L01_SPI_Driver);
	temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, command);
	SPI_NSS_High(&config->NRF24L01_SPI_Driver);
	return temp;
}
/*******************************************************************************************************/


int8_t NRF24L01_Init(NRF24L01_Config *config)
{


	nrf24_spi = config->NRF24L01_SPI_Driver;

	SPI_Init(&config->NRF24L01_SPI_Driver);
	SPI_Enable(&config->NRF24L01_SPI_Driver);

	if(config->Interrupt_Enable)
	{
		GPIO_Pin_Init(config->Interrupt_Port, config->Interrupt_Pin, MODE.Input, Output_Type.Open_Drain, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.None);
		GPIO_Interrupt_Setup(config->Interrupt_Pin, Interrupt_Edge.RISING_EDGE , 0);
	}



	write_register(config,NRF24L01_Reg.CONFIG.REGISTER, NRF24L01_Reg.CONFIG.PWR_UP.POWER_DOWN);

	NRF24L01_Set_RX_Power(config);

	write_register(config,NRF24L01_Reg.RF_SETUP.REGISTER, NRF24L01_Reg.RF_SETUP.RF_DR_LOW.PLL_LOCK);

	write_register(config,NRF24L01_Reg.SETUP_RETR.REGISTER, NRF24L01_Reg.SETUP_RETR.SETUP_RTR.ARC);

	switch (config->Address_Length) {
		case 3:
		{
			write_register(config,NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_3);
		}
			break;

		case 4:
		{
			write_register(config,NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_4);
		}
			break;
		case 5:
		{
			write_register(config,NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_5);
		}
			break;
		default:
		{
			write_register(config,NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_5);
		}
			break;
	}


	write_register(config,NRF24L01_Reg.FEATURE.REGISTER, NRF24L01_Reg.FEATURE.EN_DPL);
	write_register(config,NRF24L01_Reg.DYNPD.REGISTER, NRF24L01_Reg.DYNPD.DPL_P0);

	cmd(config,NRF24L01_Command.FLUSH_TX);
	cmd(config,NRF24L01_Command.FLUSH_RX);


	return 1;

}

int8_t NRF24L01_Reset(NRF24L01_Config *config)
{
	SPI_Config_Reset(&config->NRF24L01_SPI_Driver);
	return 1;
}

void NRF24L01_Set_Slave_Address(NRF24L01_Config *config, uint8_t slave_no, uint8_t *slave_Address)
{

	SPI_NSS_Low(&config->NRF24L01_SPI_Driver);
	temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, (NRF24L01_Reg.RX_ADDR_P0.REGISTER + slave_no) & WRITE_COMMAND);
	for(int i = 0; i<config->Address_Length; i++)
	{
		temp = SPI_TRX_Byte(&config->NRF24L01_SPI_Driver, slave_Address[i]);
	}
	SPI_NSS_High(&config->NRF24L01_SPI_Driver);

}

void NRF24L01_Set_RX_Power(NRF24L01_Config *config)
{
	uint8_t temp = 0;

	temp = read_register(config, NRF24L01_Reg.RF_SETUP.REGISTER);

	if(config->RF_Power == NRF24L01_Power.PWR_0dBm)
	{
		write_register(config, NRF24L01_Reg.RF_SETUP.REGISTER, temp | NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_0DBM);
	}
	else if(config->RF_Power == NRF24L01_Power.PWR_N6dBm)
	{
		write_register(config, NRF24L01_Reg.RF_SETUP.REGISTER, temp |NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_NEG6DBM);
	}
	else if(config->RF_Power == NRF24L01_Power.PWR_N12dBm)
	{
		write_register(config, NRF24L01_Reg.RF_SETUP.REGISTER,temp | NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_NEG12DBM);
	}
	else if(config->RF_Power == NRF24L01_Power.PWR_N18dBm)
	{
		write_register(config, NRF24L01_Reg.RF_SETUP.REGISTER,temp | NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_NEG18DBM);
	}
	else
	{
		write_register(config, NRF24L01_Reg.RF_SETUP.REGISTER, temp |NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_0DBM);
	}
}

void NRF24L01_Send_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);
void NRF24L01_Broadcast_Data(NRF24L01_Config *config, uint8_t *data, uint8_t len);
void NRF24L01_Receive_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);






