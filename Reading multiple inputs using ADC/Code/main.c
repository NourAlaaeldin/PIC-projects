/**
 * @file    main.c
 * @brief   main Module Source File for this program 
 * @author  Nour
 * @date    21/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <xc.h>
#include "ADC.h"
#include "PORT.h"
#include "DIO.h"

void main(void) 
{
    uint16 ADC_value;
    ADC_ConfigType ADC_Config = {_0,Fosc_2};
    ADC_init(&ADC_Config);
    
    set_group_direction(PORTC_CONFIG,FIRST_GROUP,OUTPUT);
    write_group(PORTC_CONFIG,FIRST_GROUP,LOW);
    
    while(1)
    {
        ADC_value = ADC_readChannel(0,&ADC_Config);
        
        /* Input 1 */
        if(ADC_value >= 490 && ADC_value <= 530)
        {
            write_pin(PORTC_CONFIG,PIN0,HIGH);
        }
        
        /* Input 2 */
        else if(ADC_value >= 660 && ADC_value <= 700)
        {
            write_pin(PORTC_CONFIG,PIN1,HIGH);            
        }
        
        /* Input 3 */
        else if(ADC_value >= 830 && ADC_value <= 870)
        {
            write_pin(PORTC_CONFIG,PIN2,HIGH); 
        }
        
        /* Input 4 */
        else if(ADC_value >= 910 && ADC_value <= 950)
        {
            write_pin(PORTC_CONFIG,PIN3,HIGH); 
        }
        else
        {
            write_group(PORTC_CONFIG,FIRST_GROUP,LOW);
        }
    }
}
