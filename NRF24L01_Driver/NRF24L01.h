/*
 * NRF24L01.h
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#ifndef NRF24L01_H_
#define NRF24L01_H_

#include "main.h"
#include "GPIO.h"
#include "SPI.h"
#include "DMA.h"
#include "NRF24L01_Defs.h"



typedef struct NRF24L01_Config
{
	SPI_Config NRF24L01_SPI_Driver;

	uint8_t Address_Length;

	uint8_t Data_Rate;
	uint8_t RF_Power;

	uint8_t Interrupt_Enable;
	uint8_t Interrupt_Type;
	GPIO_TypeDef *Interrupt_Port;
	uint8_t Interrupt_Pin;

	uint8_t CRC_type;

	uint8_t Auto_Retransmit_delay;
	uint8_t Auto_Retransmit_Count;

}NRF24L01_Config;


int8_t NRF24L01_Init(NRF24L01_Config *config);
void NRF24L01_DeInit(NRF24L01_Config *config);

void NRF24L01_Set_Slave_Address(NRF24L01_Config *config, uint8_t slave_no, uint8_t *slave_Address);
void NRF24L01_Set_RX_Power(NRF24L01_Config *config, uint8_t rx_power);

void NRF24L01_Send_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);
void NRF24L01_Broadcast_Data(NRF24L01_Config *config, uint8_t *data, uint8_t len);
void NRF24L01_Receive_Data(NRF24L01_Config *config,uint8_t slave_no, uint8_t *data, uint8_t len);





#endif /* NRF24L01_H_ */
