/**
 * @file    LM35_temp_sensor.c
 * @brief   LM35_temp_sensor Module Source File for this program 
 * @author  Nour
 * @date    17/8/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include "ADC.h"
#include "LM35_temp_sensor.h"

//--------------------- Public Function Definitions ----------------

void LM35_sensor_init(void)
{
    /* initialize ADC module */
    ADC_ConfigType ADC_Config = {_0,Fosc_2};
    ADC_init(&ADC_Config);
}

uint8 LM35_sensor_reading(void)
{
    uint16 ADC_value;
    ADC_value = ADC_readChannel(0);
    
    /* return temperature sensor reading */
    return ((0.0048828 * ADC_value) / 0.01);
}
