/*
 * NRF24L01_Defs.h
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#ifndef NRF24L01_DEFS_H_
#define NRF24L01_DEFS_H_

#ifndef NRF24L01_H
#define NRF24L01_H

#include <main.h>

// Define the NRF24L01 register values and their relevant bits in a structured format
static const struct NRF24L01_Registers
{
    // Configuration Register
    struct {
        uint8_t REGISTER;
        uint8_t MASK_RX_DR;    // Mask interrupt caused by RX_DR
        uint8_t MASK_TX_DS;    // Mask interrupt caused by TX_DS
        uint8_t MASK_MAX_RT;   // Mask interrupt caused by MAX_RT
        uint8_t EN_CRC;        // Enable CRC
        uint8_t CRCO;          // CRC encoding scheme
        uint8_t PWR_UP;        // Power up
        uint8_t PRIM_RX;       // RX/TX control
    } CONFIG;

    // Enable 'Auto Acknowledgment' Function
    struct {
        uint8_t REGISTER;
        uint8_t ENAA_P5;       // Enable Auto-ACK on data pipe 5
        uint8_t ENAA_P4;       // Enable Auto-ACK on data pipe 4
        uint8_t ENAA_P3;       // Enable Auto-ACK on data pipe 3
        uint8_t ENAA_P2;       // Enable Auto-ACK on data pipe 2
        uint8_t ENAA_P1;       // Enable Auto-ACK on data pipe 1
        uint8_t ENAA_P0;       // Enable Auto-ACK on data pipe 0
    } EN_AA;

    // Enable RX Addresses
    struct {
        uint8_t REGISTER;
        uint8_t ERX_P5;        // Enable data pipe 5
        uint8_t ERX_P4;        // Enable data pipe 4
        uint8_t ERX_P3;        // Enable data pipe 3
        uint8_t ERX_P2;        // Enable data pipe 2
        uint8_t ERX_P1;        // Enable data pipe 1
        uint8_t ERX_P0;        // Enable data pipe 0
    } EN_RXADDR;

    // Setup of Address Widths
    struct {
        uint8_t REGISTER;
        uint8_t AW;            // Address width
    } SETUP_AW;

    // Setup of Automatic Retransmission
    struct {
        uint8_t REGISTER;
        uint8_t ARD;           // Auto retransmit delay
        uint8_t ARC;           // Auto retransmit count
    } SETUP_RETR;

    // RF Channel
    struct {
        uint8_t REGISTER;
        uint8_t RF_CH;         // RF channel
    } RF_CH;

    // RF Setup Register
    struct {
        uint8_t REGISTER;
        uint8_t CONT_WAVE;     // Continuous carrier transmit
        uint8_t RF_DR_LOW;     // Set RF Data Rate to 250kbps
        uint8_t PLL_LOCK;      // Force PLL lock signal
        uint8_t RF_DR_HIGH;    // Select between 1Mbps or 2Mbps
        uint8_t RF_PWR;        // Set RF output power in TX mode
    } RF_SETUP;

    // Status Register
    struct {
        uint8_t REGISTER;
        uint8_t RX_DR;         // Data ready RX FIFO interrupt
        uint8_t TX_DS;         // Data sent TX FIFO interrupt
        uint8_t MAX_RT;        // Maximum number of TX retransmits interrupt
        uint8_t RX_P_NO;       // Data pipe number for the payload available for reading from RX_FIFO
        uint8_t TX_FULL;       // TX FIFO full flag
    } STATUS;

    // Transmit observe register
    struct {
        uint8_t REGISTER;
        uint8_t PLOS_CNT;      // Packet loss counter
        uint8_t ARC_CNT;       // Retransmitted packet counter
    } OBSERVE_TX;

    // Received Power Detector
    struct {
        uint8_t REGISTER;
        uint8_t RPD;           // Received Power Detector
    } RPD;

    // Receive address data pipe 0
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS[5];    // 5-byte receive address
    } RX_ADDR_P0;

    // Receive address data pipe 1
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS[5];    // 5-byte receive address
    } RX_ADDR_P1;

    // Receive address data pipe 2
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS;       // 1-byte receive address
    } RX_ADDR_P2;

    // Receive address data pipe 3
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS;       // 1-byte receive address
    } RX_ADDR_P3;

    // Receive address data pipe 4
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS;       // 1-byte receive address
    } RX_ADDR_P4;

    // Receive address data pipe 5
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS;       // 1-byte receive address
    } RX_ADDR_P5;

    // Transmit address
    struct {
        uint8_t REGISTER;
        uint8_t ADDRESS[5];    // 5-byte transmit address
    } TX_ADDR;

    // Number of bytes in RX payload in data pipe 0
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P0;

    // Number of bytes in RX payload in data pipe 1
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P1;

    // Number of bytes in RX payload in data pipe 2
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P2;

    // Number of bytes in RX payload in data pipe 3
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P3;

    // Number of bytes in RX payload in data pipe 4
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P4;

    // Number of bytes in RX payload in data pipe 5
    struct {
        uint8_t REGISTER;
        uint8_t RX_PW;         // Number of bytes in RX payload
    } RX_PW_P5;

    // FIFO Status Register
    struct {
        uint8_t REGISTER;
        uint8_t RX_EMPTY;      // RX FIFO empty flag
        uint8_t RX_FULL;       // RX FIFO full flag
        uint8_t TX_EMPTY;      // TX FIFO empty flag
        uint8_t TX_FULL;       // TX FIFO full flag
        uint8_t TX_REUSE;      // Reuse last transmitted payload
    } FIFO_STATUS;

    // Dynamic length of data pipes
    struct {
        uint8_t REGISTER;
        uint8_t DPL_P5;        // Enable dynamic payload length for data pipe 5
        uint8_t DPL_P4;        // Enable dynamic payload length for data pipe 4
        uint8_t DPL_P3;        // Enable dynamic payload length for data pipe 3
        uint8_t DPL_P2;        // Enable dynamic payload length for data pipe 2
        uint8_t DPL_P1;        // Enable dynamic payload length for data pipe 1
        uint8_t DPL_P0;        // Enable dynamic payload length for data pipe 0
    } DYNPD;

    // Feature Register
    struct {
        uint8_t REGISTER;
        uint8_t EN_DPL;        // Enable dynamic payload length
        uint8_t EN_ACK_PAY;    // Enable payload with ACK
        uint8_t EN_DYN_ACK;    // Enable W_TX_PAYLOAD_NOACK command
    } FEATURE;

} NRF24L01_Registers = {
    .CONFIG = { .REGISTER = 0x00, .MASK_RX_DR = 0x40, .MASK_TX_DS = 0x20, .MASK_MAX_RT = 0x10, .EN_CRC = 0x08, .CRCO = 0x04, .PWR_UP = 0x02, .PRIM_RX = 0x01 },
    .EN_AA = { .REGISTER = 0x01, .ENAA_P5 = 0x20, .ENAA_P4 = 0x10, .ENAA_P3 = 0x08, .ENAA_P2 = 0x04, .ENAA_P1 = 0x02, .ENAA_P0 = 0x01 },
    .EN_RXADDR = { .REGISTER = 0x02, .ERX_P5 = 0x20, .ERX_P4 = 0x10, .ERX_P3 = 0x08, .ERX_P2 = 0x04, .ERX_P1 = 0x02, .ERX_P0 = 0x01 },
    .SETUP_AW = { .REGISTER = 0x03, .AW = 0x03 },
    .SETUP_RETR = { .REGISTER = 0x04, .ARD = 0xF0, .ARC = 0x0F },
    .RF_CH = { .REGISTER = 0x05, .RF_CH = 0x7F },
    .RF_SETUP = { .REGISTER = 0x06, .CONT_WAVE = 0x80, .RF_DR_LOW = 0x20, .PLL_LOCK = 0x10, .RF_DR_HIGH = 0x08, .RF_PWR = 0x06 },
    .STATUS = { .REGISTER = 0x07, .RX_DR = 0x40, .TX_DS = 0x20, .MAX_RT = 0x10, .RX_P_NO = 0x0E, .TX_FULL = 0x01 },
    .OBSERVE_TX = { .REGISTER = 0x08, .PLOS_CNT = 0xF0, .ARC_CNT = 0x0F },
    .RPD = { .REGISTER = 0x09, .RPD = 0x01 },
    .RX_ADDR_P0 = { .REGISTER = 0x0A, .ADDRESS = {0x00, 0x00, 0x00, 0x00, 0x00} },
    .RX_ADDR_P1 = { .REGISTER = 0x0B, .ADDRESS = {0x00, 0x00, 0x00, 0x00, 0x00} },
    .RX_ADDR_P2 = { .REGISTER = 0x0C, .ADDRESS = 0x00 },
    .RX_ADDR_P3 = { .REGISTER = 0x0D, .ADDRESS = 0x00 },
    .RX_ADDR_P4 = { .REGISTER = 0x0E, .ADDRESS = 0x00 },
    .RX_ADDR_P5 = { .REGISTER = 0x0F, .ADDRESS = 0x00 },
    .TX_ADDR = { .REGISTER = 0x10, .ADDRESS = {0x00, 0x00, 0x00, 0x00, 0x00} },
    .RX_PW_P0 = { .REGISTER = 0x11, .RX_PW = 0x3F },
    .RX_PW_P1 = { .REGISTER = 0x12, .RX_PW = 0x3F },
    .RX_PW_P2 = { .REGISTER = 0x13, .RX_PW = 0x3F },
    .RX_PW_P3 = { .REGISTER = 0x14, .RX_PW = 0x3F },
    .RX_PW_P4 = { .REGISTER = 0x15, .RX_PW = 0x3F },
    .RX_PW_P5 = { .REGISTER = 0x16, .RX_PW = 0x3F },
    .FIFO_STATUS = { .REGISTER = 0x17, .RX_EMPTY = 0x01, .RX_FULL = 0x02, .TX_EMPTY = 0x10, .TX_FULL = 0x20, .TX_REUSE = 0x40 },
    .DYNPD = { .REGISTER = 0x1C, .DPL_P5 = 0x20, .DPL_P4 = 0x10, .DPL_P3 = 0x08, .DPL_P2 = 0x04, .DPL_P1 = 0x02, .DPL_P0 = 0x01 },
    .FEATURE = { .REGISTER = 0x1D, .EN_DPL = 0x04, .EN_ACK_PAY = 0x02, .EN_DYN_ACK = 0x01 },
};

#endif // NRF24L01_H


#endif /* NRF24L01_DEFS_H_ */
