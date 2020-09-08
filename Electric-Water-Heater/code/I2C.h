/**
 * @file    I2C.h
 * @brief   I2C Module Header File for this program 
 * @author  Nour
 * @date    10/8/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef I2C_H
#define I2C_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

// ------------------ function prototypes ---------------------------

/**
 * \b Brief: This is the function to initialize ECU as Master Mode
 * @param void 
 * @return void 
 */
void I2C_Master_Init(void);

/**
 * \b Brief: This is the function to Start I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Start(void);

/**
 * \b Brief: This is the function to Stop I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Stop(void);

/**
 * \b Brief: This is the function to Restart I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Restart(void);

/**
 * \b Brief: This is the I2C wait function
 * @param void 
 * @return void 
 */
void I2C_Wait(void);

/**
 * \b Brief: This is the I2C not Ack function
 * @param void 
 * @return void 
 */
void I2C_NAck(void);

/**
 * \b Brief: This is function to Master write address byte with write request
 * @param address uint8 address to select a certain address 
 * @return uint8 true when finished 
 */
uint8 I2C_Master_write_slave_address_with_write_req(uint8 address);

/**
 * \b Brief: This is function to Master write address byte with read request
 * @param address uint8 address to select a certain address
 * @return uint8 true when finished
 */
uint8 I2C_Master_write_slave_address_with_read_req(uint8 address);

/**
 * \b Brief: This is function to Master write data byte
 * @param data uint8 data to write data  
 * @return uint8 true when finished
 */
uint8 I2C_Master_write_byte(uint8 data);

/**
 * \b Brief: This is function to Master read data byte
 * @param void 
 * @return uint8 to get value of data 
 */
uint8 I2C_Master_read_byte(void);

#endif /* I2C_H */
