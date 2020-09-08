/**
 * @file    EEPROM.h
 * @brief   EEPROM Module header file for this program 
 * @author  Nour
 * @date    10/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef EEPROM_H
#define EEPROM_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

// ------------------ function prototypes ---------------------------

/**
 * \b Brief:  This is the Initialization of EEPROM function to Intialize ECU as Maseter 
 * @param  void 
 * @return void 
 */
void EEPROM_Init(void);

/**
 * \b Brief: This is the External EEPROM Write function to write a certain data at certain address of external EEPROM
 * @param address uint8 address to select a certain address 
 * @param data uint8 data to set data   
 * @return void 
 */
void EEPROM_Write(uint8 address, uint8 data);

/**
 * \b Brief: This is the External EEPROM Read function to read a certain data at certain address of external EEPROM
 * @param address uint8 address to select a certain address 
 * @return uint8 to read data  
 */
uint8 EEPROM_Read(uint8 address);

#endif /* EEPROM_H */