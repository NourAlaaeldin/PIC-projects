/*
 * File:   main.c
 * Author: Eng-Nour
 *
 * Created on 17 ??????, 2020, 10:58 ?
 */
/**
 * @file    TX.c
 * @brief   TX Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "UART.h"
#include "DIO.h"
#include "PORT.h"

void main(void)
{    
    uint8 value[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    int i = 0;
    
    /* set pin0 at PORTD as input pin */
    set_pin_direction(PORTD_CONFIG,PIN0,INPUT);    
    
    /* UART Initialization */
    UART_ConfigType uart_config = {TX,25};
    UART_init(&uart_config);
   
    while(1)
    {
        /* check if button is pressed */
        if(read_pin(PORTD_CONFIG,PIN0))
        {
            /* transmit data when button is pressed */
            UART_Transmit(value[i++]);
            while(read_pin(PORTD_CONFIG,PIN0));
        }
        if(i == 8)
            i = 0;
    }
}
