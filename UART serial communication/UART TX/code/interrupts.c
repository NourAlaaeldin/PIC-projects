/**
 * @file    interrupts.c
 * @brief   interrupts Module Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "std_types.h"

uint8 receive_data;

void interrupt ISR (void)
{
    if(PIR1 & 0x20)
    {
        PIR1 &= ~0x20;
        
        receive_data = RCREG;
    }
}
