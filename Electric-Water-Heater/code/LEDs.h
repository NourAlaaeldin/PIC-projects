/**
 * @file    LEDs.h
 * @brief   LEDs Module Header File for this program 
 * @author  Nour
 * @date    16/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef LEDS_H
#define LEDS_H

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

typedef enum
{
	Heating_Element_LED,Heating_Element,Cooling_Element
}LEDs;

//------------------- function prototypes --------------------------

/**
 * \b Brief: This is The LEDs Module Initialization Function 
 * @param void 
 * @return void 
 */
void LEDs_init(void);

/**
 * \b Brief: This is the Function to turn on the LED
 * @param led LEDs led to select led 
 * @return void 
 */
void Turn_on_LED(LEDs led);

/**
 * \b Brief: This is the Function to turn off the LED
 * @param led LEDs led to select led 
 * @return void 
 */
void Turn_off_LED(LEDs led);

/**
 * \b Brief: This is the Function to blink the LED
 * @param void
 * @return void 
 */
void blink_LED(void);

#endif /* LEDS_H */
