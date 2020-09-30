/**
 * @file    DIO.c
 * @brief   DIO Module Source File for this program 
 * @author  Nour
 * @date    27/7/2020
 * @version 1.0
 */

/* NOTE: use RA4 as input or output in case of negative logic only */

// ------------------ File Inclusions -------------------------------

#include "DIO.h"
#include <pic16f877a.h>

//--------------------- Public Function Definitions ----------------

void write_pin(uint8 port,uint8 pin,uint8 value)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        if(value == HIGH)
        {
            PORTA |= pin;
        }
        else if(value == LOW)
        {
            PORTA &= ~pin;
        }
    }
    else if(port == PORTB_CONFIG)
    {
        if(value == HIGH)
        {
            PORTB |= pin;
        }
        else if(value == LOW)
        {
            PORTB &= ~pin;
        }
    }
    else if(port == PORTC_CONFIG)
    {
        if(value == HIGH)
        {
            PORTC |= pin;
        }
        else if(value == LOW)
        {
            PORTC &= ~pin;
        }
    }
    else if(port == PORTD_CONFIG)
    {
        if(value == HIGH)
        {
            PORTD |= pin;
        }
        else if(value == LOW)
        {
            PORTD &= ~pin;
        }
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        if(value == HIGH)
        {
            PORTE |= pin;
        }
        else if(value == LOW)
        {
            PORTE &= ~pin;
        }
    }
}

void toggle_pin(uint8 port,uint8 pin)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        PORTA ^= pin;
    }
    else if(port == PORTB_CONFIG)
    {
        PORTB ^= pin;
    }
    else if(port == PORTC_CONFIG)
    {
        PORTC ^= pin;
    }
    else if(port == PORTD_CONFIG)
    {
        PORTD ^= pin;
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        PORTE ^= pin;
    }
}

uint8 read_pin(uint8 port,uint8 pin)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        return PORTA & pin;
    }
    else if(port == PORTB_CONFIG)
    {
        return PORTB & pin;
    }
    else if(port == PORTC_CONFIG)
    {
        return PORTC & pin;
    }
    else if(port == PORTD_CONFIG)
    {
        return PORTD & pin;
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        return PORTE & pin;
    }
}

void write_group_value(uint8 port,uint8 group,uint8 value)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        PORTA  = value | (PORTA & ~group);
    }
    else if(port == PORTB_CONFIG)
    {
        PORTB  = value | (PORTB & ~group);
    }
    else if(port == PORTC_CONFIG)
    {
        PORTC  = value | (PORTC & ~group);
    }
    else if(port == PORTD_CONFIG)
    {
        PORTD  = value | (PORTD & ~group);
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        PORTE  = value | (PORTE & ~group);
    }
}

void write_port_value(uint8 port,uint8 value)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;   
        
        PORTA = value;
    }
    else if(port == PORTB_CONFIG)
    {
         PORTB = value;   
    }
    else if(port == PORTC_CONFIG)
    {
         PORTC = value;   
    }
    else if(port == PORTD_CONFIG)
    {
         PORTD = value;   
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        PORTE = value;
    }
}

void write_port(uint8 port,uint8 value)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        if(value == HIGH)
        {
            /* Set first 6 pins */
            PORTA |= 0x3F;
        }
        else if(value == LOW)
        {
            /* Clear first 6 pins */
            PORTA &= ~0x3F;
        }
    }
    else if(port == PORTB_CONFIG)
    {
        if(value == HIGH)
        {
            PORTB = 0xFF;
        }
        else if(value == LOW)
        {
            PORTB = 0x00;
        }
    }
    else if(port == PORTC_CONFIG)
    {
        if(value == HIGH)
        {
            PORTC = 0xFF;
        }
        else if(value == LOW)
        {
            PORTC = 0x00;
        }
    }
    else if(port == PORTD_CONFIG)
    {
        if(value == HIGH)
        {
            PORTD = 0xFF;
        }
        else if(value == LOW)
        {
            PORTD = 0x00;
        }
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        
        if(value == HIGH)
        {
            /* Set first 3 pins */
            PORTE |= 0x07;
        }
        else if(value == LOW)
        {
            /* Clear first 3 pins */
            PORTE &= ~0x07;
        }
        else
        {
            PORTE = value;
        }
    }
}

void toggle_port(uint8 port)
{
    if(port == PORTA_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        PORTA ^= 0x3F;
    }
    else if(port == PORTB_CONFIG)
    {
        PORTB ^= 0xFF;
    }
    else if(port == PORTC_CONFIG)
    {
        PORTC ^= 0xFF;
    }
    else if(port == PORTD_CONFIG)
    {
        PORTD ^= 0xFF;
    }
    else if(port == PORTE_CONFIG)
    {
        /* Disable analog mode */
        ADCON1 |= 0x06;
        PORTE ^= 0x07;
    }
}

void write_group(uint8 port,uint8 group,uint8 value)
{
    if(port == PORTB_CONFIG)
    {
        if(value == HIGH)
        {
            PORTB |= group;
        }
        else if(value == LOW)
        {
            PORTB &= ~group;
        }
    }
    else if(port == PORTC_CONFIG)
    {
        if(value == HIGH)
        {
            PORTC |= group;
        }
        else if(value == LOW)
        {
            PORTC &= ~group;
        }
    }
    else if(port == PORTD_CONFIG)
    {
        if(value == HIGH)
        {
            PORTD |= group;
        }
        else if(value == LOW)
        {
            PORTD &= ~group;
        }
    }
}
void toggle_group(uint8 port,uint8 group)
{
    if(port == PORTB_CONFIG)
    {
        PORTB ^= group;
    }
    else if(port == PORTC_CONFIG)
    {
        PORTC ^= group;
    }
    else if(port == PORTD_CONFIG)
    {
        PORTD ^= group;
    }
}

