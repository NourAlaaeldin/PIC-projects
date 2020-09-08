/**
 * @file    Timer.h
 * @brief   Timer Module Header File for this program 
 * @author  Nour
 * @date    29/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef TIMER_H
#define TIMER_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

typedef enum
{
	Timer0,Timer1,Timer2
}Timer;

typedef enum
{
	PRS_2_0,PRS_4_0,PRS_8_0,PRS_16_0,PRS_32_0,PRS_64_0,PRS_128_0,PRS_256_0
}Timer0_Prescalar;

typedef enum
{
	PRS_1_1,PRS_2_1,PRS_4_1,PRS_8_1
}Timer1_Prescalar;

typedef enum
{
	PRS_1_2,PRS_4_2,PRS_16_2
}Timer2_Prescalar;

typedef enum
{
	Internal,T0CKI
}Timer0_CLK;

typedef enum
{
	internal,T1CKI
}Timer1_CLK;

//--------------------- Structures ----------------------------------

/**
 * @name    Timer_ConfigType
 * @brief   Timer_ConfigType responsible for dynamic configuration of timer module
 */
typedef struct
{
	Timer                       Timer; /**< a user defined datatype to select the timer */
	Timer0_Prescalar            Timer0_prescalar; /**< a user defined datatype to select the timer0 prescalar */
	Timer1_Prescalar            Timer1_prescalar; /**< a user defined datatype to select the timer1 prescalar */
	Timer2_Prescalar            Timer2_prescalar; /**< a user defined datatype to select the timer2 prescalar */
    Timer0_CLK                  Timer0_clk; /**< a user defined datatype to select the timer0 clk */
	Timer1_CLK                  Timer1_clk; /**< a user defined datatype to select the timer1 clk */
    uint8                       Timer0_value; /**< a user defined datatype to select the timer0 initial value */
    uint16                      Timer1_value; /**< a user defined datatype to select the timer1 initial value */
    uint8                       Timer2_value; /**< a user defined datatype to select the timer2 initial value */
}Timer_ConfigType;

//------------------- function prototypes --------------------------

/**
 * \b Brief: This is Timer Module Initialization Function 
 * @param Config_Ptr Timer_ConfigType * Config_Ptr to select Config_Ptr
 * @return void 
 */
void Timer_init(Timer_ConfigType * Config_Ptr);

/**
 * \b Brief: This is function to turn on the timer
 * @param timer Timer timer to select timer
 * @return void 
 */
void Turn_on_timer(Timer timer);

/**
 * \b Brief: This is function to turn off the timer
 * @param timer Timer timer to select timer
 * @return void 
 */
void Turn_off_timer(Timer timer);

#endif /* TIMER_H */
