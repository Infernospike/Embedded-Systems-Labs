/***********************************************************************************************************************
 * Copyright [2015-2024] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

#include "hal_data.h"
#define PWPR        (*((volatile uint8_t*)  0x40040D03))  // Write Protection Register
#define P107PFS     (*((volatile uint32_t*) 0x4004085C))  // Pin Function Select Register
#define MSTPCRD     (*((volatile uint32_t*) 0x40047008))  // Module Stop Control Register
#define GTUDDTYC    (*((volatile uint32_t*) 0x40078830))  // Count Direction and Duty Setting Register
#define GTIOR       (*((volatile uint32_t*) 0x40078834))  // GPT I/O Control Register
#define GTCCRA      (*((volatile uint32_t*) 0x4007884C))  // GPT Compare Capture A Register
#define GTPR        (*((volatile uint32_t*) 0x40078864))  // GPT Period Register
#define GTCR        (*((volatile uint32_t*) 0x4007882C))  // GPT Control Register





void hal_entry(void) {

    // 1. Enable write access for P107PFS
    PWPR = 0x00;   // Disable write protection
    PWPR = 0x40;   // Enable writing

        // 2. Set P107 as GTIOCA8 (PSEL=3, PMR=
    //P107PFS &= ~((0b11111 << 8) | (1 << 16));  // Clear PSEL and PMR bits
    P107PFS |= (0b00011 << 24) | (1 << 16);  // Set PSEL=3, PMR=1 (GTIOCA mode)

        // 3. Enable GPT channel 8 (clear bit 6 of MSTPCRD)
    MSTPCRD &= ~(1 << 6);

        // 4. Set GTUDDTYC - Increment mode, duty cycle depends on GTCCRA match
    GTUDDTYC |= 1;

          // 5. Configure GTIOR - Initial high, low at GTCCRA match
    //GTIOR &= ~0b11111;  // Clear previous settings
    GTIOR |= (0b11001) | (1 << 8);   // Initial high, toggle low on GTCCRA match
     // Enable GTIOCA output

          // 6. Configure GTCCRA (25% duty cycle)
    GTCCRA = 0x493DF;   // 25% of 1.2M cycles = 300,000 cycles

          // 7. Configure GTPR (100 Hz cycle period)
    GTPR = 0x124F7F;  // 1.2M - 1 (for 100 Hz)

          // 8. Start GPT in saw-wave mode with PCLKD/1

    GTCR |= (0b000 << 16);   // Set MD = 000 (saw-wave PWM)

    //GTCR &= ~(0b111 << 24);  // Clear TPCS (prescaler)
    GTCR |= (0b000 << 24);   // Set TPCS = 000 (PCLKD/1)

    GTCR |= (1 << 0);  // Start counter


}
