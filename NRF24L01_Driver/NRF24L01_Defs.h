/*
 * NRF24L01_Defs.h
 *
 *  Created on: Jun 4, 2024
 *      Author: kunal
 */

#ifndef NRF24L01_DEFS_H_
#define NRF24L01_DEFS_H_



#include "main.h"

static const struct NRF24L01_Data_Rate{

    uint8_t _1MBPS;   // 00: 1Mbps
    uint8_t _2MBPS;   // 01: 2Mbps
    uint8_t _250KBPS; // 10: 250kbps
}NRF24L01_Data_Rate = {
		._1MBPS = 0 << 3,
		._2MBPS = 1 << 3,
		._250KBPS = 2 << 3,
};


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

static const struct NRF24L01_CRC
{
    uint8_t ONE_BYTE;  // 0: 1 byte
    uint8_t TWO_BYTES; // 1: 2 bytes

}NRF24L01_CRC =
{
		.ONE_BYTE = 1,
		.TWO_BYTES = 2,
};

static const struct NRF24L01_RF_Channel
{
	const struct{
		uint16_t CH_MHz_2400;
		uint16_t CH_MHz_2402;
		uint16_t CH_MHz_2404;
		uint16_t CH_MHz_2406;
		uint16_t CH_MHz_2408;
		uint16_t CH_MHz_2410;
		uint16_t CH_MHz_2412;
		uint16_t CH_MHz_2414;
		uint16_t CH_MHz_2416;
		uint16_t CH_MHz_2418;
		uint16_t CH_MHz_2420;
		uint16_t CH_MHz_2422;
		uint16_t CH_MHz_2424;
		uint16_t CH_MHz_2426;
		uint16_t CH_MHz_2428;
		uint16_t CH_MHz_2430;
		uint16_t CH_MHz_2432;
		uint16_t CH_MHz_2434;
		uint16_t CH_MHz_2436;
		uint16_t CH_MHz_2438;
		uint16_t CH_MHz_2440;
		uint16_t CH_MHz_2442;
		uint16_t CH_MHz_2444;
		uint16_t CH_MHz_2446;
		uint16_t CH_MHz_2448;
		uint16_t CH_MHz_2450;
		uint16_t CH_MHz_2452;
		uint16_t CH_MHz_2454;
		uint16_t CH_MHz_2456;
		uint16_t CH_MHz_2458;
		uint16_t CH_MHz_2460;
		uint16_t CH_MHz_2462;
		uint16_t CH_MHz_2464;
		uint16_t CH_MHz_2466;
		uint16_t CH_MHz_2468;
		uint16_t CH_MHz_2470;
		uint16_t CH_MHz_2472;
		uint16_t CH_MHz_2474;
		uint16_t CH_MHz_2476;
		uint16_t CH_MHz_2478;
		uint16_t CH_MHz_2480;
		uint16_t CH_MHz_2482;
		uint16_t CH_MHz_2484;
		uint16_t CH_MHz_2486;
		uint16_t CH_MHz_2488;
		uint16_t CH_MHz_2490;
		uint16_t CH_MHz_2492;
		uint16_t CH_MHz_2494;
		uint16_t CH_MHz_2496;
		uint16_t CH_MHz_2498;
		uint16_t CH_MHz_2500;
		uint16_t CH_MHz_2502;
		uint16_t CH_MHz_2504;
		uint16_t CH_MHz_2506;
		uint16_t CH_MHz_2508;
		uint16_t CH_MHz_2510;
		uint16_t CH_MHz_2512;
		uint16_t CH_MHz_2514;
		uint16_t CH_MHz_2516;
		uint16_t CH_MHz_2518;
		uint16_t CH_MHz_2520;
		uint16_t CH_MHz_2522;
		uint16_t CH_MHz_2524;
	}Speed_2Mbps;

	const struct{
		uint16_t CH_MHz_2400 ;
		uint16_t CH_MHz_2401 ;
		uint16_t CH_MHz_2402 ;
		uint16_t CH_MHz_2403 ;
		uint16_t CH_MHz_2404 ;
		uint16_t CH_MHz_2405 ;
		uint16_t CH_MHz_2406 ;
		uint16_t CH_MHz_2407 ;
		uint16_t CH_MHz_2408 ;
		uint16_t CH_MHz_2409 ;
		uint16_t CH_MHz_2410 ;
		uint16_t CH_MHz_2411 ;
		uint16_t CH_MHz_2412 ;
		uint16_t CH_MHz_2413 ;
		uint16_t CH_MHz_2414 ;
		uint16_t CH_MHz_2415 ;
		uint16_t CH_MHz_2416 ;
		uint16_t CH_MHz_2417 ;
		uint16_t CH_MHz_2418 ;
		uint16_t CH_MHz_2419 ;
		uint16_t CH_MHz_2420 ;
		uint16_t CH_MHz_2421 ;
		uint16_t CH_MHz_2422 ;
		uint16_t CH_MHz_2423 ;
		uint16_t CH_MHz_2424 ;
		uint16_t CH_MHz_2425 ;
		uint16_t CH_MHz_2426 ;
		uint16_t CH_MHz_2427 ;
		uint16_t CH_MHz_2428 ;
		uint16_t CH_MHz_2429 ;
		uint16_t CH_MHz_2430 ;
		uint16_t CH_MHz_2431 ;
		uint16_t CH_MHz_2432 ;
		uint16_t CH_MHz_2433 ;
		uint16_t CH_MHz_2434 ;
		uint16_t CH_MHz_2435 ;
		uint16_t CH_MHz_2436 ;
		uint16_t CH_MHz_2437 ;
		uint16_t CH_MHz_2438 ;
		uint16_t CH_MHz_2439 ;
		uint16_t CH_MHz_2440 ;
		uint16_t CH_MHz_2441 ;
		uint16_t CH_MHz_2442 ;
		uint16_t CH_MHz_2443 ;
		uint16_t CH_MHz_2444 ;
		uint16_t CH_MHz_2445 ;
		uint16_t CH_MHz_2446 ;
		uint16_t CH_MHz_2447 ;
		uint16_t CH_MHz_2448 ;
		uint16_t CH_MHz_2449 ;
		uint16_t CH_MHz_2450 ;
		uint16_t CH_MHz_2451 ;
		uint16_t CH_MHz_2452 ;
		uint16_t CH_MHz_2453 ;
		uint16_t CH_MHz_2454 ;
		uint16_t CH_MHz_2455 ;
		uint16_t CH_MHz_2456 ;
		uint16_t CH_MHz_2457 ;
		uint16_t CH_MHz_2458 ;
		uint16_t CH_MHz_2459 ;
		uint16_t CH_MHz_2460 ;
		uint16_t CH_MHz_2461 ;
		uint16_t CH_MHz_2462 ;
		uint16_t CH_MHz_2463 ;
		uint16_t CH_MHz_2464 ;
		uint16_t CH_MHz_2465 ;
		uint16_t CH_MHz_2466 ;
		uint16_t CH_MHz_2467 ;
		uint16_t CH_MHz_2468 ;
		uint16_t CH_MHz_2469 ;
		uint16_t CH_MHz_2470 ;
		uint16_t CH_MHz_2471 ;
		uint16_t CH_MHz_2472 ;
		uint16_t CH_MHz_2473 ;
		uint16_t CH_MHz_2474 ;
		uint16_t CH_MHz_2475 ;
		uint16_t CH_MHz_2476 ;
		uint16_t CH_MHz_2477 ;
		uint16_t CH_MHz_2478 ;
		uint16_t CH_MHz_2479 ;
		uint16_t CH_MHz_2480 ;
		uint16_t CH_MHz_2481 ;
		uint16_t CH_MHz_2482 ;
		uint16_t CH_MHz_2483 ;
		uint16_t CH_MHz_2484 ;
		uint16_t CH_MHz_2485 ;
		uint16_t CH_MHz_2486 ;
		uint16_t CH_MHz_2487 ;
		uint16_t CH_MHz_2488 ;
		uint16_t CH_MHz_2489 ;
		uint16_t CH_MHz_2490 ;
		uint16_t CH_MHz_2491 ;
		uint16_t CH_MHz_2492 ;
		uint16_t CH_MHz_2493 ;
		uint16_t CH_MHz_2494 ;
		uint16_t CH_MHz_2495 ;
		uint16_t CH_MHz_2496 ;
		uint16_t CH_MHz_2497 ;
		uint16_t CH_MHz_2498 ;
		uint16_t CH_MHz_2499 ;
		uint16_t CH_MHz_2500 ;
		uint16_t CH_MHz_2501 ;
		uint16_t CH_MHz_2502 ;
		uint16_t CH_MHz_2503 ;
		uint16_t CH_MHz_2504 ;
		uint16_t CH_MHz_2505 ;
		uint16_t CH_MHz_2506 ;
		uint16_t CH_MHz_2507 ;
		uint16_t CH_MHz_2508 ;
		uint16_t CH_MHz_2509 ;
		uint16_t CH_MHz_2510 ;
		uint16_t CH_MHz_2511 ;
		uint16_t CH_MHz_2512 ;
		uint16_t CH_MHz_2513 ;
		uint16_t CH_MHz_2514 ;
		uint16_t CH_MHz_2515 ;
		uint16_t CH_MHz_2516 ;
		uint16_t CH_MHz_2517 ;
		uint16_t CH_MHz_2518 ;
		uint16_t CH_MHz_2519 ;
		uint16_t CH_MHz_2520 ;
		uint16_t CH_MHz_2521 ;
		uint16_t CH_MHz_2522 ;
		uint16_t CH_MHz_2523 ;
		uint16_t CH_MHz_2524 ;
		uint16_t CH_MHz_2525 ;


	}Speed_250kbps_to_1Mbps;

}NRF24L01_RF_Channel = {

		.Speed_2Mbps =
		{
				.CH_MHz_2400 = 2400,
				.CH_MHz_2402 = 2402,
				.CH_MHz_2404 = 2404,
				.CH_MHz_2406 = 2406,
				.CH_MHz_2408 = 2408,
				.CH_MHz_2410 = 2410,
				.CH_MHz_2412 = 2412,
				.CH_MHz_2414 = 2414,
				.CH_MHz_2416 = 2416,
				.CH_MHz_2418 = 2418,
				.CH_MHz_2420 = 2420,
				.CH_MHz_2422 = 2422,
				.CH_MHz_2424 = 2424,
				.CH_MHz_2426 = 2426,
				.CH_MHz_2428 = 2428,
				.CH_MHz_2430 = 2430,
				.CH_MHz_2432 = 2432,
				.CH_MHz_2434 = 2434,
				.CH_MHz_2436 = 2436,
				.CH_MHz_2438 = 2438,
				.CH_MHz_2440 = 2440,
				.CH_MHz_2442 = 2442,
				.CH_MHz_2444 = 2444,
				.CH_MHz_2446 = 2446,
				.CH_MHz_2448 = 2448,
				.CH_MHz_2450 = 2450,
				.CH_MHz_2452 = 2452,
				.CH_MHz_2454 = 2454,
				.CH_MHz_2456 = 2456,
				.CH_MHz_2458 = 2458,
				.CH_MHz_2460 = 2460,
				.CH_MHz_2462 = 2462,
				.CH_MHz_2464 = 2464,
				.CH_MHz_2466 = 2466,
				.CH_MHz_2468 = 2468,
				.CH_MHz_2470 = 2470,
				.CH_MHz_2472 = 2472,
				.CH_MHz_2474 = 2474,
				.CH_MHz_2476 = 2476,
				.CH_MHz_2478 = 2478,
				.CH_MHz_2480 = 2480,
				.CH_MHz_2482 = 2482,
				.CH_MHz_2484 = 2484,
				.CH_MHz_2486 = 2486,
				.CH_MHz_2488 = 2488,
				.CH_MHz_2490 = 2490,
				.CH_MHz_2492 = 2492,
				.CH_MHz_2494 = 2494,
				.CH_MHz_2496 = 2496,
				.CH_MHz_2498 = 2498,
				.CH_MHz_2500 = 2500,
				.CH_MHz_2502 = 2502,
				.CH_MHz_2504 = 2504,
				.CH_MHz_2506 = 2506,
				.CH_MHz_2508 = 2508,
				.CH_MHz_2510 = 2510,
				.CH_MHz_2512 = 2512,
				.CH_MHz_2514 = 2514,
				.CH_MHz_2516 = 2516,
				.CH_MHz_2518 = 2518,
				.CH_MHz_2520 = 2520,
				.CH_MHz_2522 = 2522,
				.CH_MHz_2524 = 2524,
		},

		.Speed_250kbps_to_1Mbps = {
			.CH_MHz_2400 = 2400,
			.CH_MHz_2401 = 2401,
			.CH_MHz_2402 = 2402,
			.CH_MHz_2403 = 2403,
			.CH_MHz_2404 = 2404,
			.CH_MHz_2405 = 2405,
			.CH_MHz_2406 = 2406,
			.CH_MHz_2407 = 2407,
			.CH_MHz_2408 = 2408,
			.CH_MHz_2409 = 2409,
			.CH_MHz_2410 = 2410,
			.CH_MHz_2411 = 2411,
			.CH_MHz_2412 = 2412,
			.CH_MHz_2413 = 2413,
			.CH_MHz_2414 = 2414,
			.CH_MHz_2415 = 2415,
			.CH_MHz_2416 = 2416,
			.CH_MHz_2417 = 2417,
			.CH_MHz_2418 = 2418,
			.CH_MHz_2419 = 2419,
			.CH_MHz_2420 = 2420,
			.CH_MHz_2421 = 2421,
			.CH_MHz_2422 = 2422,
			.CH_MHz_2423 = 2423,
			.CH_MHz_2424 = 2424,
			.CH_MHz_2425 = 2425,
			.CH_MHz_2426 = 2426,
			.CH_MHz_2427 = 2427,
			.CH_MHz_2428 = 2428,
			.CH_MHz_2429 = 2429,
			.CH_MHz_2430 = 2430,
			.CH_MHz_2431 = 2431,
			.CH_MHz_2432 = 2432,
			.CH_MHz_2433 = 2433,
			.CH_MHz_2434 = 2434,
			.CH_MHz_2435 = 2435,
			.CH_MHz_2436 = 2436,
			.CH_MHz_2437 = 2437,
			.CH_MHz_2438 = 2438,
			.CH_MHz_2439 = 2439,
			.CH_MHz_2440 = 2440,
			.CH_MHz_2441 = 2441,
			.CH_MHz_2442 = 2442,
			.CH_MHz_2443 = 2443,
			.CH_MHz_2444 = 2444,
			.CH_MHz_2445 = 2445,
			.CH_MHz_2446 = 2446,
			.CH_MHz_2447 = 2447,
			.CH_MHz_2448 = 2448,
			.CH_MHz_2449 = 2449,
			.CH_MHz_2450 = 2450,
			.CH_MHz_2451 = 2451,
			.CH_MHz_2452 = 2452,
			.CH_MHz_2453 = 2453,
			.CH_MHz_2454 = 2454,
			.CH_MHz_2455 = 2455,
			.CH_MHz_2456 = 2456,
			.CH_MHz_2457 = 2457,
			.CH_MHz_2458 = 2458,
			.CH_MHz_2459 = 2459,
			.CH_MHz_2460 = 2460,
			.CH_MHz_2461 = 2461,
			.CH_MHz_2462 = 2462,
			.CH_MHz_2463 = 2463,
			.CH_MHz_2464 = 2464,
			.CH_MHz_2465 = 2465,
			.CH_MHz_2466 = 2466,
			.CH_MHz_2467 = 2467,
			.CH_MHz_2468 = 2468,
			.CH_MHz_2469 = 2469,
			.CH_MHz_2470 = 2470,
			.CH_MHz_2471 = 2471,
			.CH_MHz_2472 = 2472,
			.CH_MHz_2473 = 2473,
			.CH_MHz_2474 = 2474,
			.CH_MHz_2475 = 2475,
			.CH_MHz_2476 = 2476,
			.CH_MHz_2477 = 2477,
			.CH_MHz_2478 = 2478,
			.CH_MHz_2479 = 2479,
			.CH_MHz_2480 = 2480,
			.CH_MHz_2481 = 2481,
			.CH_MHz_2482 = 2482,
			.CH_MHz_2483 = 2483,
			.CH_MHz_2484 = 2484,
			.CH_MHz_2485 = 2485,
			.CH_MHz_2486 = 2486,
			.CH_MHz_2487 = 2487,
			.CH_MHz_2488 = 2488,
			.CH_MHz_2489 = 2489,
			.CH_MHz_2490 = 2490,
			.CH_MHz_2491 = 2491,
			.CH_MHz_2492 = 2492,
			.CH_MHz_2493 = 2493,
			.CH_MHz_2494 = 2494,
			.CH_MHz_2495 = 2495,
			.CH_MHz_2496 = 2496,
			.CH_MHz_2497 = 2497,
			.CH_MHz_2498 = 2498,
			.CH_MHz_2499 = 2499,
			.CH_MHz_2500 = 2500,
			.CH_MHz_2501 = 2501,
			.CH_MHz_2502 = 2502,
			.CH_MHz_2503 = 2503,
			.CH_MHz_2504 = 2504,
			.CH_MHz_2505 = 2505,
			.CH_MHz_2506 = 2506,
			.CH_MHz_2507 = 2507,
			.CH_MHz_2508 = 2508,
			.CH_MHz_2509 = 2509,
			.CH_MHz_2510 = 2510,
			.CH_MHz_2511 = 2511,
			.CH_MHz_2512 = 2512,
			.CH_MHz_2513 = 2513,
			.CH_MHz_2514 = 2514,
			.CH_MHz_2515 = 2515,
			.CH_MHz_2516 = 2516,
			.CH_MHz_2517 = 2517,
			.CH_MHz_2518 = 2518,
			.CH_MHz_2519 = 2519,
			.CH_MHz_2520 = 2520,
			.CH_MHz_2521 = 2521,
			.CH_MHz_2522 = 2522,
			.CH_MHz_2523 = 2523,
			.CH_MHz_2524 = 2524,
			.CH_MHz_2525 = 2525,
		}
};



#endif /* NRF24L01_DEFS_H_ */
