/**
 * @file    App.c
 * @brief   App Module Source File for this program 
 * @author  Nour
 * @date    27/8/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include "App.h"
#include "seven_segments.h"
#include "LM35_temp_sensor.h"
#include "LEDs.h"
#include "Buttons.h"
#include "EEPROM.h"
#include "Timer.h"
#include "interrupts.h"
#include <xc.h>

//--------------------- Preprocessor Defines -----------------------

#define _XTAL_FREQ              4000000

//--------------------- Private Data Types --------------------------

static uint8 sensor_reading; /**< a variable to store temperature sensor reading */

static uint8 sensor_readings[10] = {0}; /**< array that consists of 10 sensor readings */

static uint8 avg; /**< a variable that stores the average of sensor readings */
 
static uint16 sum = 0; /**< a variable to store the sum of sensor readings */

static uint8 initial_temp = 60; /**< temperature initial value is 60 degree */

static uint8 temp; /**< temperature value, change through the program */

static uint8 set_flag = 0; /**< a flag that indicates setting mode operation */

static uint8 running_flag = 0; /**< a flag that indicates running mode operation */

static uint8 EEPROM_reading; /**< a variable to get the value stored in external EEPROM */

static uint8 count = 0; /**< a variable to count form 0 to 9 */

//--------------------- Private Function Definitions ----------------

static void running_mode(void)
{
    /* ADC sensor reads temp every 100 ms */
    Turn_on_timer(Timer0);
    
    /* heating element led blink every 1 sec */
    Turn_on_timer(Timer1);
    
    turn_off_2_7_seg();

     /* check if timer counted 100 ms */
    if(read_mode == 1)
    {
        read_mode = 0;
        
        /* stop timer operation */
        Turn_off_timer(Timer0);
            
        /* get sensor reading */
        sensor_reading = LM35_sensor_reading();
        
        /* put sensor readings in the array */
        sensor_readings[count] = sensor_reading;        
        
        /* get the sum of the sensor readings */
        sum = sum + sensor_readings[count];
        
        count++;
        
        if(count == 10)
        {
            count = 0;
            
            /* calculate the average of the sensor readings */
            avg = sum / 10;
            sum = 0;
            
            /* display the average */
            for(uint8 i = 0;i < 50;i++)
            {
                display_num_2_7_seg(avg);
            }
        }
    }
    
    /* check if the average less than the set temperature by 5 degrees */
    if(avg == (EEPROM_reading - 5))
    {
        Turn_on_LED(Heating_Element);
        Turn_off_LED(Cooling_Element);
        
        /* check if timer counted 1 s */
        if(display_mode == 1)
        {
            display_mode = 0;
            
            /* stop timer operation */
            Turn_off_timer(Timer1);
            
            /* blink heating element led every one second */
            blink_LED();
        }
    }
    
    /* check if the average more than the set temperature by 5 degrees */
    else if(avg == (EEPROM_reading + 5))
    {
        Turn_off_LED(Heating_Element);
        Turn_on_LED(Cooling_Element);
        Turn_on_LED(Heating_Element_LED);
    }
}

static void setting_mode(void)
{
    /* blink seven segment every one second */
    if(running_flag == 0)
    {
        /* start counting for 1 sec and 5 sec */
        Turn_on_timer(Timer1);
        
        /* 7 seg is off then on for specific interval */
        turn_off_2_7_seg();
        
        /* check if up button is pressed */
        if((read_button(Up_Button)))
        {
            /* reset counter for 5 sec */
            time1_count_5 = 0;

            /* increase temperature by 5 degrees */
            temp = temp + 5;
            
            while(read_button(Up_Button));
        }
        
        /* check if down button is pressed */
        else if(read_button(Down_Button))
        {
            /* reset counter for 5 sec */
            time1_count_5 = 0;
            
            /* decrease temperature by 5 degrees */
            temp = temp - 5;
            
            while(read_button(Down_Button));
        }
        else
        {
            /*
             * check if timer counted 5 sec
             * if flag is on, display temp and go to running state
             */
            if(exit_mode == 1)
            {
                exit_mode = 0;
                
                /* stop timer operation */
                Turn_off_timer(Timer1);
                
                /* display the set temperature */
                for(uint8 i = 0;i < 50;i++)
                {
                    display_num_2_7_seg(EEPROM_reading);
                }
                
                /* set running flag to go to running mode */
                running_flag = 1;
            }
        }

        /* check if timer counted 1 sec */
        if(display_mode == 1)
        {   
            display_mode = 0;
            
            /* stop timer operation */
            Turn_off_timer(Timer1);
            
            /* display the set temperature */
            for(uint8 i = 0;i < 50;i++)
            {
                display_num_2_7_seg(EEPROM_reading);    
            }
        }

        /*
         * temperature is between 35 and 75 degrees
         * we check if the temperature exceeds the limits 
         */
        if(temp > 75)
        {
            temp = 75;
        }
        if(temp < 35)
        {
            temp = 35;
        }
        
        /* store the set temp using external EEPROM then retrieve it */
        EEPROM_Write(0x00,temp);
        __delay_ms(100);
        EEPROM_reading = EEPROM_Read(0x00);
    }
    if(running_flag == 1)
    {
        running_mode(); 
    }
}

//--------------------- Public Function Definitions ----------------

void off_state(void)
{  
    /* reset modes */
    exit_mode = 0;
    display_mode = 0;
    read_mode = 0;
            
    /* reset flags */
    set_flag = 0;
    running_flag = 0;
    
    /* stop timers */
    Turn_off_timer(Timer0);
    Turn_off_timer(Timer1);
    
    /* stop display */
    Turn_off_LED(Heating_Element);
    Turn_off_LED(Cooling_Element);
    Turn_off_LED(Heating_Element_LED);
    
    turn_off_2_7_seg();
}

void on_state(void)
{   
    /* check if up button or down button are pressed */
    if((read_button(Up_Button) || read_button(Down_Button)) && set_flag == 0)
    {
        /* display the initial temperature */
        for(uint8 i = 0;i < 50;i++)
        {
            display_num_2_7_seg(initial_temp);
        }
        
        temp = initial_temp;
        set_flag = 1;
    }
    
    /* go to setting mode */
    if(set_flag == 1)
    {
        setting_mode();
    }
}

void initialize_all(void)
{
    /* call all initialization functions */
    LEDs_init();
    Buttons_init();
    seven_segment_init();
    LM35_sensor_init();
    EEPROM_Init();
    
    /* Timer0 operates for 100ms */
    Timer_ConfigType Timer_Config1 = {Timer0,PRS_256_0,0,0,Internal,0,60,0,0};
    
    /* Timer1 operates for 1s & 5s */
    Timer_ConfigType Timer_Config2 = {Timer1,0,PRS_8_1,0,0,internal,0,3035,0};
    
    Timer_init(&Timer_Config1);
    Timer_init(&Timer_Config2);
    
    /* global interrupt enable */
    INTCON |= 0xC0;
}
