#include "hal_data.h"
#include <stdio.h>

// Flags for interrupt signals
volatile bool timer_flag = false;  // Indicates when the timer expires
volatile bool switch_flag = false; // Indicates when the switch is pressed

// Timer interrupt callback function
void cb0(timer_callback_args_t *args) {
    if (args->event == TIMER_EVENT_EXPIRED) {
        timer_flag = true;
    }
}

// External switch interrupt callback function
void switch_callback(external_irq_callback_args_t *args) {
    switch_flag = true;
}

void hal_entry(void) {
    /* Define timing parameters */
    const bsp_delay_units_t time_unit = BSP_DELAY_UNITS_MILLISECONDS;
    const uint32_t blink_rate = 2;
    const uint32_t delay_time = time_unit / blink_rate;

    /* LED Configuration */
    bsp_leds_t led_info;
    ioport_level_t led_state = IOPORT_LEVEL_HIGH;
    R_BSP_LedsGet(&led_info);

    // Initialize LEDs to the default state
    for (uint32_t idx = 0; idx < led_info.led_count; idx++) {
        g_ioport.p_api->pinWrite(led_info.p_leds[idx], led_state);
    }

    /* Timer values */
    timer_size_t recorded_time;

    /* Initialize timer */
    g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->start(g_timer0.p_ctrl);

    /* Initialize external interrupt (switch) */
    g_external_irq0.p_api->open(g_external_irq0.p_ctrl, g_external_irq0.p_cfg);
    g_external_irq0.p_api->enable(g_external_irq0.p_ctrl);

    while (1) {
        timer_flag = false;
        while (!timer_flag) { /* Wait for timer event */ }
        timer_flag = false;

        /* Turn LEDs ON */
        led_state = IOPORT_LEVEL_LOW;
        for (uint32_t idx = 0; idx < led_info.led_count; idx++) {
            g_ioport.p_api->pinWrite(led_info.p_leds[idx], led_state);
        }

        /* Restart timer with new duration */
        g_timer0.p_api->reset(g_timer0.p_ctrl);
        g_timer0.p_api->periodSet(g_timer0.p_ctrl, 3000, TIMER_UNIT_PERIOD_MSEC);
        g_timer0.p_api->start(g_timer0.p_ctrl);

        /* Wait for switch or timer interrupt */
        switch_flag = false;
        timer_flag = false;
        while (!switch_flag && !timer_flag) { /* Wait for an event */ }

        if (switch_flag) {
            g_timer0.p_api->counterGet(g_timer0.p_ctrl, &recorded_time);
        }
        switch_flag = false;
        timer_flag = false;

        /* Reset timer for new cycle */
        g_timer0.p_api->reset(g_timer0.p_ctrl);
        g_timer0.p_api->periodSet(g_timer0.p_ctrl, 1000, TIMER_UNIT_PERIOD_MSEC);
        g_timer0.p_api->start(g_timer0.p_ctrl);

        /* Turn LEDs OFF */
        led_state = IOPORT_LEVEL_HIGH;
        for (uint32_t idx = 0; idx < led_info.led_count; idx++) {
            g_ioport.p_api->pinWrite(led_info.p_leds[idx], led_state);
        }
    }
}
