/**
 * @file    TX.c
 * @brief   TX Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "SPI.h"
#include "DIO.h"
#include "PORT.h"

void main(void)
{    
    uint8 value[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    uint8 i = 0;
    
    /* set pin0 at PORTD as input pin */
    set_pin_direction(PORTD_CONFIG,PIN0,INPUT);
    
    /* SPI Initialization */
    SPI_ConfigType spi_config = {_0,__0,___0,TX};
    SPI_init(&spi_config); 
    
    while(1)
    {
        /* check if button is pressed */
        if(read_pin(PORTD_CONFIG,PIN0))
        {
            /* transmit data when button is pressed */
            SPI_Transmit(value[i++]);
            while(read_pin(PORTD_CONFIG,PIN0));
        }
        if(i == 8)
            i = 0;
    }
}
