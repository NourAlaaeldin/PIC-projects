/**
 * @file    ADC.h
 * @brief   ADC Module Header File for this program 
 * @author  Nour
 * @date    12/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef ADC_H
#define ADC_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

/*
 * 0 -> Vref = Vdd, all analog
 * 1 -> Vref =  An3, all analog
 * 2 -> Vref = Vdd, AN0 -> AN4 : Analog, AN5 -> AN7 : Digital
 * 3 -> Vref =  An3, AN0 -> AN4 : Analog, AN5 -> AN7 : Digital
 * 4 -> Vref = Vdd, AN0, AN1, AN3 -> Analog, The rest is Digital
 * 5 -> Vref =  An3, AN0, AN1 -> Analog, The rest is Digital
 * 6 or 7 -> All Digital
 * 8 -> Vref+ =  An3,Vref- = An2, All Analog
 * 9 -> Vref = Vdd, An6, AN7 -> Digital, The rest is Analog
 * 10 -> Vref =  An3, An6, AN7 -> Digital, The rest is Analog
 * 11 -> Vref+ =  An3,Vref- = An2, An6, AN7 -> Digital, The rest is Analog
 * 12 -> Vref+ =  An3,Vref- = An2, AN5, An6, AN7 -> Digital, The rest is Analog
 * 13 -> Vref+ =  An3,Vref- = An2, AN0, AN1 : Analog, The rest is Digital
 * 14 -> Vref = Vdd, AN0 -> Analog, The rest is Digital
 * 15 -> Vref+ =  An3,Vref- = An2, AN0 -> Analog, The rest is Digital
 */
typedef enum
{
	_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15
}ADC_Port_Config;

typedef enum
{
	Fosc_2,Fosc_8,Fosc_32,Frc,Fosc_4,Fosc_16,Fosc_64,_Frc
}ADC_Prescalar;

//--------------------- Structures ----------------------------------

/**
 * @name    ADC_ConfigType
 * @brief   ADC_ConfigType responsible for dynamic configuration of ADC module
 */
typedef struct
{
	ADC_Port_Config     port_config; /**< a user defined datatype to select the ADC port configuration */
	ADC_Prescalar       prescalar; /**< a user defined datatype to select the ADC prescalar */
}ADC_ConfigType;

//------------------- function prototypes --------------------------

/**
 * \b Brief: This is ADC Module Initialization Function 
 * @param Config_Ptr ADC_ConfigType * Config_Ptr to select Config_Ptr
 * @return void 
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/**
 * \b Brief: This is function to read the ADC channel
 * @param channel_num uint8 channel_num to select channel_num
 * @param Config_Ptr ADC_ConfigType * Config_Ptr to select Config_Ptr
 * @return uint16 to get value of ADC channel  
 */
uint16 ADC_readChannel(uint8 channel_num,const ADC_ConfigType * Config_Ptr);

#endif /* ADC_H */
