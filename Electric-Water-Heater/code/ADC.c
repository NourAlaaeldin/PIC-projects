/**
 * @file    ADC.c
 * @brief   ADC Module Source File for this program 
 * @author  Nour
 * @date    12/8/2020
 * @version 1.0
 */


// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "PORT.h" 
#include "ADC.h"

//--------------------- Public Function Definitions ----------------

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
    /* 
     * right justified
     * set prescalar
     * set port_config 
     */
    ADCON1 = (Config_Ptr -> port_config) | ((Config_Ptr -> prescalar & 0b0100) << 6) | (0x80);
    
    /*
     * enable ADC 
     * set prescalar
     */
    ADCON0 = 0x01 | ((Config_Ptr -> prescalar & 0b0011) << 6);
    
}

uint16 ADC_readChannel(uint8 channel_num)
{
    uint8 pins[8] = {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7};
    
    /* channel number maps to portA */
    if(channel_num >= 0 || channel_num <= 5)  
    {
        set_pin_direction(PORTA_CONFIG,pins[channel_num],INPUT);
    }
    /* channel number maps to portE */
    else
    {
        set_pin_direction(PORTE_CONFIG,pins[channel_num],INPUT);
    }
    
    /* set channel number */
    ADCON0 |= (channel_num << 3);
    
    /* start conversion */
    ADCON0 |= 0x04;
    
    /* wait until conversion is completed */
    while(ADCON0 & 0x04);
    
    /* return ADC value */
    return (ADRESL + (ADRESH << 8));
}
