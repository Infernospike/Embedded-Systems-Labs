#include "Rx_thread.h"
#include "blinky_thread.h"
#include <stdio.h>

/* Rx_thread entry function */

extern void initialise_monitor_handles(void);
void Rx_thread_entry(void)
{
    initialise_monitor_handles();

    /* TODO: add your own code here */
    char msg_buffer[];

    while (1)
    {
        memset(msg_buffer, 0, sizeof(msg_buffer));
        tx_queue_receive(&g_queue0, msg_buffer, TX_WAIT_FOREVER);

        printf("%s\n", msg_buffer);
        tx_thread_sleep(1);




    }
}
