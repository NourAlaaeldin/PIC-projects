/**
 * @file    PORT.c
 * @brief   PORT Module Source File for this program 
 * @author  Nour
 * @date    27/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include "PORT.h"
#include <pic16f877a.h>

//--------------------- Public Function Definitions ----------------

void set_pin_direction(uint8 port,uint8 pin,uint8 direction)
{
    if(port == PORTA_CONFIG)
    {
            if(direction == OUTPUT)
            {
                TRISA &= ~pin;
            }
            else if(direction == INPUT)
            {
                TRISA |= pin;
            }
    }
    else if(port == PORTB_CONFIG)
    {
            if(direction == OUTPUT)
            {
                TRISB &= ~pin;
            }
            else if(direction == INPUT)
            {
                TRISB |= pin;
            }
    }
    else if(port == PORTC_CONFIG)
    {
            if(direction == OUTPUT)
            {
                TRISC &= ~pin;
            }
            else if(direction == INPUT)
            {
                TRISC |= pin;
            }
    }
    else if(port == PORTD_CONFIG)
    {
            if(direction == OUTPUT)
            {
                TRISD &= ~pin;
            }
            else if(direction == INPUT)
            {
                TRISD |= pin;
            }
    }
    else if(port == PORTE_CONFIG)
    {
            if(direction == OUTPUT)
            {
                TRISE &= ~pin;
            }
            else if(direction == INPUT)
            {
                TRISE |= pin;
            }
    }
}

void set_port_direction(uint8 port,uint8 direction)
{
    if(port == PORTA_CONFIG)
    {
        if(direction == OUTPUT)
        {
            /* Clear first 6 pins */
            TRISA &= ~0x3F;
        }
        else if(direction == INPUT)
        {
            /* Set first 6 pins */
            TRISA |= 0x3F;
        }
    }
    else if(port == PORTB_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISB = 0x00;
        }
        else if(direction == INPUT)
        {
            TRISB = 0xFF;
        }
    }
    else if(port == PORTC_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISC = 0x00;
        }
        else if(direction == INPUT)
        {
            TRISC = 0xFF;
        }
    }
    else if(port == PORTD_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISD = 0x00;
        }
        else if(direction == INPUT)
        {
            TRISD = 0xFF;
        }
    }
    if(port == PORTE_CONFIG)
    {
        if(direction == OUTPUT)
        {
            /* Clear first 3 pins */
            TRISE &= ~0x07;
        }
        else if(direction == INPUT)
        {
            /* Set first 3 pins */
            TRISE |= 0x07;
        }
    }
}

void set_group_direction(uint8 port,uint8 group,uint8 direction)
{
    if(port == PORTB_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISB &= ~group;
        }
        else if(direction == INPUT)
        {
            TRISB |= group;
        }
    }
    if(port == PORTC_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISC &= ~group;
        }
        else if(direction == INPUT)
        {
            TRISC |= group;
        }
    }
    if(port == PORTD_CONFIG)
    {
        if(direction == OUTPUT)
        {
            TRISD &= ~group;
        }
        else if(direction == INPUT)
        {
            TRISD |= group;
        }
    }
}
