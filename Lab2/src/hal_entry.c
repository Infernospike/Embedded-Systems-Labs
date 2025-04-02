#include "hal_data.h"

volatile bool timer_flag = false;
volatile bool button_flag = false;
volatile uint32_t response_time = 0;
volatile bool button_pressed = false;
void switch_callback(external_irq_callback_args_t *p_args);
void cb0(timer_callback_args_t *p_args);


void cb0(timer_callback_args_t *p_args) {
    if (p_args->event == TIMER_EVENT_EXPIRED) {
        timer_flag = true;
    }
}

void switch_callback(external_irq_callback_args_t *p_args) {
    if (p_args->channel == 11) {  // Adjust the channel number based on your setup
           button_pressed = true;
       }
}

void hal_entry(void) {
    // Open the Timer
    g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
    // Open the External IRQ
    g_external_irq0.p_api->open(g_external_irq0.p_ctrl, g_external_irq0.p_cfg);

    // Turn off all LEDs initially
    g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
    g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
    g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);

    while (1) {
        // Start the timer for 1 second
        g_timer0.p_api->start(g_timer0.p_ctrl);

        // Wait for the timer flag
        while (!timer_flag);
        timer_flag = false;

        // Turn LEDs on to indicate timer has expired
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW); // Example for one LED

        // Reset the timer for a 3-second measure
        g_timer0.p_api->reset(g_timer0.p_ctrl);
        g_timer0.p_api->periodSet(g_timer0.p_ctrl, 3000000, TIMER_UNIT_PERIOD_USEC);
        g_timer0.p_api->start(g_timer0.p_ctrl);

        // Wait for the button press
        while (!button_flag);
        button_flag = false;

        // Stop the timer and read the count
        g_timer0.p_api->counterGet(g_timer0.p_ctrl, &response_time);

        // Prepare for the next round
        g_timer0.p_api->reset(g_timer0.p_ctrl);

        // Debug breakpoint here for testing
    }
}
