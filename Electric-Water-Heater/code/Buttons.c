/**
 * @file    Buttons.c
 * @brief   Buttons Module Source File for this program 
 * @author  Nour
 * @date    16/8/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include "PORT.h"
#include "DIO.h"
#include "Buttons.h"

//--------------------- Preprocessor Defines -----------------------

#define UP_BUTTON_PORT      PORTD_CONFIG /**< a preprocessor to define up button port */
#define DOWN_BUTTON_PORT    PORTD_CONFIG /**< a preprocessor to define down button port */
#define ON_OFF_BUTTON_PORT  PORTD_CONFIG /**< a preprocessor to define on/off button port */
#define UP_BUTTON_PIN       PIN0         /**< a preprocessor to define up button pin */
#define DOWN_BUTTON_PIN     PIN1         /**< a preprocessor to define down button pin */
#define ON_OFF_BUTTON_PIN   PIN2         /**< a preprocessor to define on/off button pin */

//--------------------- Public Function Definitions ----------------

void Buttons_init(void)
{
    /* set buttons as input */
    set_pin_direction(UP_BUTTON_PORT,UP_BUTTON_PIN,INPUT);
    set_pin_direction(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN,INPUT);
    set_pin_direction(ON_OFF_BUTTON_PORT,ON_OFF_BUTTON_PIN,INPUT);
}

uint8 read_button(Buttons button)
{
    if(button == Up_Button)
    {
        /* return up button reading */
        return read_pin(UP_BUTTON_PORT,UP_BUTTON_PIN);
    }
    else if(button == Down_Button)
    {
        /* return down button reading */
        return read_pin(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN);
    }
    else if(button == On_Off_Button)
    {
        /* return on/off button reading */
        return read_pin(ON_OFF_BUTTON_PORT,ON_OFF_BUTTON_PIN);
    }
}
