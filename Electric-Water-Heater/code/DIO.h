/**
 * @file    DIO.h
 * @brief   DIO Module Header File for this program 
 * @author  Nour
 * @date    27/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef DIO_H
#define DIO_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"
#include "PORT_config.h"
#include "PIN_config.h"

// ------------------ function prototypes ---------------------------

/**
 * \b Brief: This is a function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to set the value (LOW , HIGH)
 * @param port uint8 port to select port
 * @param pin uint8 pin to select pin 
 * @param  value uint8 value to select value 
 * @return void 
 */
void write_pin(uint8 port,uint8 pin,uint8 value);

/**
 * \b Brief: This is a function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to toggle it
 * @param port uint8 port to select port
 * @param pin uint8 pin to select pin 
 * @return void 
 */
void toggle_pin(uint8 port,uint8 pin);


/**
 * \b Brief: This is function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to get the value
 * @param port uint8 port to select port
 * @param pin uint8 pin to select pin 
 * @return uint8 to get value of pin  
 */
uint8 read_pin(uint8 port,uint8 pin);

/**
 * \b Brief: This is a function to select certain group of groups (FIRST_GROUP , SECOND_GROUP) of port of ports (A,B,C,D,E) to set a certain value 
 * @param port uint8 port to select port
 * @param group uint8 group to select group 
 * @param  value uint8 value to select value 
 * @return void 
 */
void write_group_value(uint8 port,uint8 group,uint8 value);

/**
 * \b Brief: This is a function to select certain port of ports (A,B,C,D,E) to set the value (LOW , HIGH , any value)
 * @param port uint8 port to select port
 * @param  value uint8 value to select value 
 * @return void 
 */
void write_port(uint8 port,uint8 value);

/**
 * \b Brief: This is a function to select certain port of ports (A,B,C,D,E) to toggle it
 * @param port uint8 port to select port
 * @return void 
 */
void toggle_port(uint8 port);

/**
 * \b Brief: This is a function to select certain group of groups (FIRST_GROUP , SECOND_GROUP) of port of ports (A,B,C,D,E) to set the value (LOW , HIGH)
 * @param port uint8 port to select port
 * @param group uint8 group to select group 
 * @param  value uint8 value to select value 
 * @return void 
 */
void write_group(uint8 port,uint8 group,uint8 value);

/**
 * \b Brief: This is a function to select certain group of groups (FIRST_GROUP , SECOND_GROUP) of port of ports (A,B,C,D,E) to toggle it
 * @param port uint8 port to select port
 * @param group uint8 group to select group 
 * @return void 
 */
void toggle_group(uint8 port,uint8 group);

#endif /* DIO_H */
