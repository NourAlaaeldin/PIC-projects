/**
 * @file    LEDs.c
 * @brief   LEDs Module Source File for this program 
 * @author  Nour
 * @date    16/8/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include "PORT.h"
#include "DIO.h"
#include "LEDs.h"

//--------------------- Preprocessor Defines -----------------------

#define HEATING_ELEMENT_LED_PORT    PORTD_CONFIG /**< a preprocessor to define heating element led port */
#define HEATING_ELEMENT_PORT        PORTD_CONFIG /**< a preprocessor to define heating element port */
#define COOLING_ELEMENT_PORT        PORTD_CONFIG /**< a preprocessor to define cooling element port */
#define HEATING_ELEMENT_LED_PIN     PIN3         /**< a preprocessor to define heating element led pin */
#define HEATING_ELEMENT_PIN         PIN4         /**< a preprocessor to define heating element pin */
#define COOLING_ELEMENT_PIN         PIN5         /**< a preprocessor to define cooling element pin */

//--------------------- Public Function Definitions ----------------

void LEDs_init(void)
{
    /* set LEDs as output */
    set_pin_direction(HEATING_ELEMENT_LED_PORT,HEATING_ELEMENT_LED_PIN,OUTPUT);
    set_pin_direction(HEATING_ELEMENT_PORT,HEATING_ELEMENT_PIN,OUTPUT);
    set_pin_direction(COOLING_ELEMENT_PORT,COOLING_ELEMENT_PIN,OUTPUT);
    
    /* initial value is low */
    write_pin(HEATING_ELEMENT_LED_PORT,HEATING_ELEMENT_LED_PIN,LOW);
    write_pin(HEATING_ELEMENT_PORT,HEATING_ELEMENT_PIN,LOW);
    write_pin(COOLING_ELEMENT_PORT,COOLING_ELEMENT_PIN,LOW);
}

void Turn_on_LED(LEDs led)
{
    if(led == Heating_Element_LED)
    {
        /* turn on heating element led */
        write_pin(HEATING_ELEMENT_LED_PORT,HEATING_ELEMENT_LED_PIN,HIGH);
    }
    else if(led == Heating_Element)
    {
        /* turn on heating element */
        write_pin(HEATING_ELEMENT_PORT,HEATING_ELEMENT_PIN,HIGH);
    }
    else if(led == Cooling_Element)
    {
        /* turn on cooling element */
        write_pin(COOLING_ELEMENT_PORT,COOLING_ELEMENT_PIN,HIGH);
    }
}

void Turn_off_LED(LEDs led)
{
    if(led == Heating_Element_LED)
    {
        /* turn off heating element led */
        write_pin(HEATING_ELEMENT_LED_PORT,HEATING_ELEMENT_LED_PIN,LOW);
    }
    else if(led == Heating_Element)
    {
        /* turn off heating element */
        write_pin(HEATING_ELEMENT_PORT,HEATING_ELEMENT_PIN,LOW);
    }
    else if(led == Cooling_Element)
    {
        /* turn off cooling element */
        write_pin(COOLING_ELEMENT_PORT,COOLING_ELEMENT_PIN,LOW);
    }
}
void blink_LED(void)
{
    /* blink heating element led */
    toggle_pin(HEATING_ELEMENT_LED_PORT,HEATING_ELEMENT_LED_PIN);
}
