#include "blinky_thread.h"
#include "hal_data.h"
#include <stdio.h>
#include <string.h>

void initialise_monitor_handles(void);

void blinky_thread_entry(void)
{
    // Initialize debug console for printf
    initialise_monitor_handles();
    printf("Debug Console Initialized.\n");

    // Open UART communications driver
    g_uart0.p_api->open(g_uart0.p_ctrl, g_uart0.p_cfg);

    uint8_t count = 0;  // Counter for messages
    char message[] = "Lab4: Serial Comm over RS-232. Count:";   // Buffer for transmitting
    char received_message[50];  // Buffer for receiving

    char * send;
    char * receive;



    while (1)
    {
       snprintf(received_message, sizeof(received_message),"%s%d", message,count);

      send = received_message;
       g_uart0.p_api->write(g_uart0.p_ctrl, &send, sizeof(send));

       printf("sent string %d: %s\n", count, send);

       g_uart0.p_api->read(g_uart0.p_ctrl, &receive,sizeof(send));

       printf("Received string %d: %s\n", count, receive);

       count++;
    }

    // Close UART communications driver (not reached, but good practice)

}
