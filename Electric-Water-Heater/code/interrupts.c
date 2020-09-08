/**
 * @file    interrupts.c
 * @brief   interrupts Module Source File for this program 
 * @author  Nour
 * @date    29/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "std_types.h"

//--------------------- Private Data Types --------------------------

static uint8 time0_count = 0; /**< counter for 100 msec */

static uint8 time1_count_1 = 0; /**< counter for 1 sec */

//--------------------- Public Data Types --------------------------

uint8 time1_count_5 = 0; /**< counter for 5 sec */

uint8 read_mode = 0; /**< flag that indicates when to read the sensor */

uint8 exit_mode = 0; /**< flag that indicates when to exit the setting mode */

uint8 display_mode = 0; /**< flag that indicates when to enter the display mode */

//--------------------- Interrupt Service Routine ----------------

void interrupt ISR()
{    
    /* check if timer0 flag is set */
    if(INTCON & 0x04)
    {
        /* reset timer0 flag */
        INTCON &= ~0x04;
                
        /* Timer initial value -> dependant on the application -> 10ms */
		TMR0 = 60;
        
        time0_count++;
        
        /* counted 100 msec */
        if(time0_count == 2)
        {
            time0_count = 0;
            read_mode = 1;
        }
    }
    
    /* check if timer1 flag is set */
    if(PIR1 & 0x01)
    {
        /* reset timer1 flag */
        PIR1 &= ~0x01;
        
        /* Timer initial value -> dependant on the application -> 10ms */
		TMR1L = 3035;
        TMR1H = (3035 - 256) << 8;
        
        time1_count_1++;
        time1_count_5++;
        
        /* counted 1 sec */
        if(time1_count_1 == 2)
        {
            time1_count_1 = 0;
            display_mode = 1;
        }
        /* counted 5 sec */
        if(time1_count_5 == 10)
        {
            time1_count_5 = 0;
            exit_mode = 1;
        }
    }
}
