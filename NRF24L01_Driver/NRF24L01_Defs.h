/*
 * NRF24L01_Defs.h
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#ifndef NRF24L01_DEFS_H_
#define NRF24L01_DEFS_H_



#include "main.h"

static const struct NRF24L01_Power
{
	uint8_t  PWR_0dBm   ; // 0 dBm
	uint8_t  PWR_N6dBm  ; // -6 dBm
	uint8_t  PWR_N12dBm ; // -12 dBm
	uint8_t  PWR_N18dBm ; // -18 dBm

}NRF24L01_Power =
{
        .PWR_0dBm   = 0b11 << 1,
        .PWR_N6dBm  = 0b10 << 1,
        .PWR_N12dBm = 0b01 << 1,
        .PWR_N18dBm = 0b00 << 1,
};

static const struct NRF24L01_Address_Length
{
    uint8_t Illegal;
    uint8_t Byte_3;
    uint8_t Byte_4;
    uint8_t Byte_5;

}NRF24L01_Address_Length =
{
		.Illegal = 0 << 0,
		.Byte_3 = 1 << 1,
		.Byte_4 = 2 << 4,
		.Byte_5 = 3 << 5,
};




#endif /* NRF24L01_DEFS_H_ */
