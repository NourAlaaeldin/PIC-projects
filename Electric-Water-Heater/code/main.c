/**
 * @file    main.c
 * @brief   main Module Source File for this program 
 * @author  Nour
 * @date    27/8/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "App.h"
#include "Buttons.h"

void main(void) 
{     
    initialize_all();
    while(1)
    {
        while(read_button(On_Off_Button))
        {
            on_state();
        }
        off_state();
    }
}
