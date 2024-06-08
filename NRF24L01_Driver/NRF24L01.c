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


	write_register(NRF24L01_Registers.CONFIG.REGISTER, 0 << NRF24L01_Registers.CONFIG.PWR_UP);








	return 1;


}

void NRF24L01_DeInit(NRF24L01_Config *config);





