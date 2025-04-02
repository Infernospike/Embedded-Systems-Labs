#include "sender1.h"
#include "blinky_thread.h"
#include <stdio.h>

/* Sender1 entry function */
void sender1_entry(void)
{
    /* TODO: add your own code here */
    char msg[] = "Message from Sender1";
    while (1)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);

        tx_mutex_get(&g_mutex0, TX_WAIT_FOREVER);

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_LOW);

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);

        tx_thread_sleep(40);

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);

        tx_mutex_put(&g_mutex0);

        tx_queue_send(&g_queue0, strlen(msg), TX_NO_WAIT);



    }
}
