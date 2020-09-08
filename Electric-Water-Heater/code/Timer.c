/**
 * @file    Timer.c
 * @brief   Timer Module Source File for this program 
 * @author  Nour
 * @date    29/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "Timer.h"
#include "LEDs.h"

//--------------------- Public Function Definitions ----------------

void Timer_init(Timer_ConfigType * Config_Ptr)
{   
	if(Config_Ptr -> Timer == Timer0)
	{
		/* Timer initial value */
		TMR0 = Config_Ptr -> Timer0_value;
        
        /* 
         * 1. set prescalar 
         * 2. assign prescalar to Timer0
         * 3. increment on low to high transmission
         * 4. set clock source 
         */
        OPTION_REG &= ~0x18;
        OPTION_REG = (OPTION_REG & ~0x20) | (Config_Ptr -> Timer0_clk);
        OPTION_REG = (OPTION_REG & ~0x07) | (Config_Ptr -> Timer0_prescalar);
    }
    else if(Config_Ptr -> Timer == Timer1)
    {
        /* Timer initial value */
		TMR1L = Config_Ptr -> Timer1_value;
        
        if(Config_Ptr -> Timer1_value > 255)
        {
            TMR1H = (Config_Ptr -> Timer1_value - 256) << 8;
        }
        else
        {
            TMR1H = Config_Ptr -> Timer1_value << 8;
        }
        
        /* 
         * 1. enable Timer1
         * 2. assign prescalar to Timer1 
         * 3. set clock source 
         */
        T1CON = (Config_Ptr -> Timer1_clk << 1) | (Config_Ptr -> Timer1_prescalar << 4);        
    }
    else if(Config_Ptr -> Timer == Timer2)
    {
        /* Timer initial value */
		TMR2 = Config_Ptr -> Timer2_value;
        
        /*
         * 1. set prescalar
         * 2. enable timer2
         */
        T2CON |= Config_Ptr ->Timer2_prescalar | 0x04;        
    }
}

void Turn_on_timer(Timer timer)
{
    if(timer == Timer0)
    {
        /* enable timer0 interrupt */
        INTCON |= 0x20;        
    }
    else if(timer == Timer1)
    {
        /* enable timer1 */
        T1CON |= 0x01; 
        
        /* enable timer1 interrupt */
        PIE1 |= 0x01;        
    }
    else if(timer == Timer2)
    {
        /* enable timer2 interrupt */
        PIE1 |= 0x02;
    }
}

void Turn_off_timer(Timer timer)
{    
    if(timer == Timer0)
    {
        /* Timer initial value -> dependant on the application -> 10ms */
		TMR0 = 60;
        
        /* disable timer0 */
        OPTION_REG = 0;
        
        /* disable timer0 interrupt */
        INTCON &= ~0x20;        
    }
    else if(timer == Timer1)
    {
        /* Timer initial value -> dependant on the application -> 10ms */
		TMR1L = 3035;
        TMR1H = (3035 - 256) << 8;
        
        /* disable timer1 */
        T1CON &= ~0x01; 
        
        /* disable timer1 interrupt */
        PIE1 &= ~0x01;        
    }
    else if(timer == Timer2)
    {
        /* disable timer2 interrupt */
        PIE1 &= ~0x02;
    }
}
