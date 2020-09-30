/**
 * @file    RX.c
 * @brief   RX Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "UART.h"
#include "PORT.h"
#include "DIO.h"
#include "interrupts.h"

void main(void) 
{
    /* global interrupt enable */
    INTCON |= 0xC0;
    
    /* initialize PORTD as output and set value to low */
    set_port_direction(PORTD_CONFIG,OUTPUT);
    write_port(PORTD_CONFIG,LOW);
    
    /* UART initialization */
    UART_ConfigType uart_config = {RX,25};
    UART_init(&uart_config);
    
    while(1)
    {
        /* write the received value to PORTD */
        write_port_value(PORTD_CONFIG,receive_data);
    }
}
