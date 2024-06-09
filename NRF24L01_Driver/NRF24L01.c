/*
 * NRF24L01.c
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#include "NRF24L01.h"
#include "NRF24L01_Defs.h"





SPI_Config nrf24_spi;

#define READ_COMMAND 0x1F
#define WRITE_COMMAND 0x20

/**************************************************************************/
static uint8_t read_register(uint8_t reg)
{
	uint8_t temp = 0;
	SPI_NSS_Low(&nrf24_spi);
	temp = SPI_TRX_Byte(&nrf24_spi, reg & READ_COMMAND);
	SPI_NSS_High(&nrf24_spi);
	return temp;
}

static void write_register(uint8_t reg, uint8_t data)
{
	uint8_t temp = 0;
	SPI_NSS_Low(&nrf24_spi);
	temp = SPI_TRX_Byte(&nrf24_spi, reg & WRITE_COMMAND);
	temp = SPI_TRX_Byte(&nrf24_spi, data);
	SPI_NSS_High(&nrf24_spi);
}

static uint8_t cmd(uint8_t command)
{
	uint8_t temp = 0;
	SPI_NSS_Low(&nrf24_spi);
	temp = SPI_TRX_Byte(&nrf24_spi, command);
	SPI_NSS_High(&nrf24_spi);
	return temp;
}



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



	write_register(NRF24L01_Reg.CONFIG.REGISTER, NRF24L01_Reg.CONFIG.PWR_UP.POWER_DOWN);
	write_register(NRF24L01_Reg.RF_SETUP.REGISTER, NRF24L01_Reg.RF_SETUP.RF_PWR.POWER_NEG18DBM);
	write_register(NRF24L01_Reg.RF_SETUP.REGISTER, NRF24L01_Reg.RF_SETUP.RF_DR_LOW.PLL_LOCK);
	write_register(NRF24L01_Reg.SETUP_RETR.REGISTER, NRF24L01_Reg.SETUP_RETR.SETUP_RTR.ARC);

	switch (config->Address_Length) {
		case 3:
		{
			write_register(NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_3);
		}
			break;

		case 4:
		{
			write_register(NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_4);
		}
			break;
		case 5:
		{
			write_register(NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_5);
		}
			break;
		default:
		{
			write_register(NRF24L01_Reg.SETUP_AW.REGISTER, NRF24L01_Reg.SETUP_AW.AW.Byte_5);
		}
			break;
	}


	write_register(NRF24L01_Reg.FEATURE.REGISTER, NRF24L01_Reg.FEATURE.EN_DPL);
	write_register(NRF24L01_Reg.DYNPD.REGISTER, NRF24L01_Reg.DYNPD.DPL_P0);

	return 1;

}


void NRF24L01_Set_Slave_Address(NRF24L01_Config *config, uint8_t slave_no, uint8_t *slave_Address)
{
	uint8_t temp = 0;
	SPI_NSS_Low(&nrf24_spi);
	temp = SPI_TRX_Byte(&nrf24_spi, NRF24L01_Reg.RX_ADDR_P0.REGISTER + slave_no & WRITE_COMMAND);
	for(int i = 0; i<config->Address_Length; i++)
	{
		temp = SPI_TRX_Byte(&nrf24_spi, slave_Address[i]);
	}
	SPI_NSS_High(&nrf24_spi);

}
void NRF24L01_Set_RX_Power(NRF24L01_Config *config, uint8_t rx_power);

void NRF24L01_Send_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);
void NRF24L01_Broadcast_Data(NRF24L01_Config *config, uint8_t *data, uint8_t len);
void NRF24L01_Receive_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);






