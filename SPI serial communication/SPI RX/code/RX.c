/**
 * @file    RX.c
 * @brief   RX Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "SPI.h"
#include "PORT.h"
#include "DIO.h"
#include "interrupts.h"

void main(void) 
{
    /* global interrupt enable */
    INTCON |= 0xC0;
    
    /* set PORTD as output and its value is low */
    set_port_direction(PORTD_CONFIG,OUTPUT);
    write_port(PORTD_CONFIG,LOW);
    
    /* SPI Initialization */
    SPI_ConfigType spi_config = {_0,__0,___4,RX};
    SPI_init(&spi_config);
    while(1)
    {
        /* write the value of received data to PORTD */
        write_port_value(PORTD_CONFIG,receive_data);     
    }
}
