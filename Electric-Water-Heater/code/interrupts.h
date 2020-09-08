/**
 * @file    interrupts.h
 * @brief   interrupts Module Header File for this program 
 * @author  Nour
 * @date    29/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//--------------------- Public Data Types --------------------------

extern uint8 time1_count_5; /**< counter for 5 sec */

extern uint8 read_mode; /**< flag that indicates when to read the sensor */

extern uint8 exit_mode; /**< flag that indicates when to exit the setting mode */

extern uint8 display_mode; /**< flag that indicates when to enter the display mode */

#endif /* INTERRUPTS_H */