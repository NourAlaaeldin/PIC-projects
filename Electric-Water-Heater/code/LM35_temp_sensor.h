/**
 * @file    LM35_temp_sensor.h
 * @brief   LM35_temp_sensor Module Header File for this program 
 * @author  Nour
 * @date    17/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef LM35_TEMP_SENSOR_H
#define LM35_TEMP_SENSOR_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//------------------- function prototypes --------------------------

/**
 * \b Brief: This is LM35_temp_sensor Module Initialization Function 
 * @param void
 * @return void 
 */
void LM35_sensor_init(void);

/**
 * \b Brief: This is function to read the LM35 sensor
 * @param void
 * @return uint8 to get value of LM35 sensor  
 */
uint8 LM35_sensor_reading(void);

#endif /* LM35_TEMP_SENSOR_H */
