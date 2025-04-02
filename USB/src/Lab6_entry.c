#include "Lab6.h"
#include <stdio.h>
#include <string.h>

/* Lab6 entry function */
void Lab6_entry(void) {
    /* Define LED structure */
    uint8_t counter = 1;  // Start from 1 to 16
    bsp_leds_t leds;
    uint8_t user_input;
    uint32_t sleep_interval = 500; // Start with 500ms delay

    /* Get LED information */
    R_BSP_LedsGet(&leds);

    if (0 == leds.led_count){
        while(1); // Trap execution if no LEDs are found
    }

    /* Open USB communication */
    g_sf_comms0.p_api->open(g_sf_comms0.p_ctrl, g_sf_comms0.p_cfg);

    while(1){
        for (int i = 0; i < 16; i++){
            /* Set LEDs in binary pattern */
            for(uint32_t j = 0; j < leds.led_count; j++ ){
                uint32_t led_state = (counter >> j) & 1;
                g_ioport.p_api->pinWrite(leds.p_leds[j], led_state);
            }

            /* Convert counter to string manually */
            char message[6];  // Buffer for 2-digit number + newline
            int temp = counter;
            int index = 0;

            if (temp >= 10) {
                message[index++] = '0' + (temp / 10);  // Extract tens place
            }
            message[index++] = '0' + (temp % 10);  // Extract ones place
            message[index++] = '\n';
            message[index++] = '\r';  // Add newline
            message[index] = '\0';  // Null-terminate

            /* Write counter to terminal */
            g_sf_comms0.p_api->write(g_sf_comms0.p_ctrl, (uint8_t *)message, index, TX_WAIT_FOREVER);

            counter = (counter % 16) + 1; // Cycle from 1 to 16

            /* Sleep for N ticks */
            R_BSP_SoftwareDelay(sleep_interval, BSP_DELAY_UNITS_MILLISECONDS);
        }

        /* Prompt user every 16 iterations */
        char prompt[] = "Press 'a' to decrease, 's' to increase speed\n\r";
        g_sf_comms0.p_api->write(g_sf_comms0.p_ctrl, (uint8_t *)prompt, strlen(prompt), TX_WAIT_FOREVER);

        /* Check for user input */
        if (g_sf_comms0.p_api->read(g_sf_comms0.p_ctrl, &user_input, 1, TX_WAIT_FOREVER) == SSP_SUCCESS) {
            if (user_input == 'a' && sleep_interval < 2000) {
                sleep_interval *= 2; // Decrease speed
            } else if (user_input == 's' && sleep_interval > 100) {
                sleep_interval /= 2; // Increase speed
            }
        }
    }
}
