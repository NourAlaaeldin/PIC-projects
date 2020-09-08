/**
 * @file    PORT.h
 * @brief   PORT Module Header File for this program 
 * @author  Nour
 * @date    27/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef PORT_H
#define	PORT_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"
#include "PORT_config.h"
#include "PIN_config.h"

// ------------------  function prototypes -------------------------------

/**
 * \b Brief: This is a function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to set the direction (INPUT , OUTPUT)
 * @param port uint8 port to select port
 * @param pin uint8 pin to select pin 
 * @param  direction uint8 direction to select direction 
 * @return void 
 */
void set_pin_direction(uint8 port,uint8 pin,uint8 direction);

/**
 * \b Brief: This is a function to select certain port of ports (A,B,C,D,E) to set the direction (INPUT , OUTPUT)
 * @param port uint8 port to select port
 * @param  direction uint8 direction to select direction 
 * @return void 
 */
void set_port_direction(uint8 port,uint8 direction);

/**
 * \b Brief: This is a function to select certain group of groups (FIRST_GROUP , SECOND_GROUP) of port of ports (A,B,C,D,E) to set the direction (INPUT , OUTPUT)
 * @param port uint8 port to select port
 * @param group uint8 group to select group 
 * @param  direction uint8 direction to select direction
 * @return void 
 */
void set_group_direction(uint8 port,uint8 group,uint8 direction);

#endif /* PORT_H */
