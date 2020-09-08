/**
 * @file    Buttons.h
 * @brief   Buttons Module Header File for this program 
 * @author  Nour
 * @date    16/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef BUTTONS_H
#define BUTTONS_H

//--------------------- File Inclusions ----------------------------

#include "std_types.h" 

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

typedef enum
{
	Up_Button,Down_Button,On_Off_Button
}Buttons;

//------------------- function prototypes --------------------------

/**
 * \b Brief: This is The Buttons Module Initialization Function 
 * @param void 
 * @return void 
 */
void Buttons_init(void);

/**
 * \b Brief: This is function to read the button
 * @param button Buttons button to select button
 * @return uint8 to get value of button  
 */
uint8 read_button(Buttons button);

#endif /* BUTTONS_H */
