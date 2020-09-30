/**
 * @file    UART.h
 * @brief   UART Module Header File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef UART_H
#define UART_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

typedef enum
{
	TX,RX
}Mode;

//--------------------- Structures ----------------------------------

/*
 * ------ At high speed --------
 * 1200 baud_rate -> SPBRG = 207
 * 2400 baud_rate -> SPBRG = 103
 * 9600 baud_rate -> SPBRG = 25
 * 19200 baud_rate -> SPBRG = 12
 * 28800 baud_rate -> SPBRG = 8
 * 33600 baud_rate -> SPBRG = 6
 * 57600 baud_rate -> SPBRG = 3
 */

/**
 * @name    UART_ConfigType
 * @brief   UART_ConfigTypee responsible for dynamic configuration of UART module
 */
typedef struct
{
    Mode mode;          /**< a user defined datatype to select the UART mode configuration */
    uint8 baud_rate;    /**< a user defined datatype to select the UART baudrate configuration */
}UART_ConfigType;

// ------------------ function prototypes ---------------------------

/**
 * \b Brief: This is UART Module Initialization Function 
 * @param Config_Ptr UART_ConfigType * Config_Ptr to select Config_Ptr
 * @return void 
 */
void UART_init(UART_ConfigType * Config_Ptr);

/**
 * \b Brief: This is function to transmit data
 * @param data uint8 data to select transmitted data using UART
 * @return void 
 */
void UART_Transmit(uint8 data);

#endif /* UART_H */
