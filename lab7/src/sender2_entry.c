#include "sender2.h"
#include "blinky_thread.h"
/* Sender2 entry function */
void sender2_entry(void)
{
    /* TODO: add your own code here */

    char msg[] = "Message from Sender2";

    while (1)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);

        tx_mutex_get(&g_mutex0, TX_WAIT_FOREVER);


        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_LOW);

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);

        tx_thread_sleep(60);

        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_LOW);

        tx_mutex_put(&g_mutex0);

        tx_queue_send(&g_queue0, strl(msg), TX_NO_WAIT);
    }
}
