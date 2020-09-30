/**
 * @file    SPI.h
 * @brief   SPI Module Header File for this program 
 * @author  Nour
 * @date    29/9/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef SPI_H
#define SPI_H

// ------------------ File Inclusions -------------------------------

#include "std_types.h"

//--------------------- Public Data Types --------------------------

//--------------------- Enums --------------------------------------

/*
 * 0 -> Transmit occurs on transition from Idle to active clock state
 * 1 -> Transmit occurs on transition from active to Idle clock state
 */
typedef enum
{
	_0,_1
}Clock_Select;

/*
 * 0 -> Idle state for clock is a low level
 * 1 -> Idle state for clock is a high level
 */
typedef enum
{
    __0,__1
}Polarity;

/*
 * 0 -> SPI Master mode, clock = FOSC/4
 * 1 -> SPI Master mode, clock = FOSC/16
 * 2 -> SPI Master mode, clock = FOSC/64
 * 3 -> SPI Master mode, clock = TMR2 output/2
 * 4 -> SPI Slave mode, clock = SCK pin. SS pin control enabled.
 * 5 -> SPI Slave mode, clock = SCK pin. SS pin control disabled. SS can be used as I/O pin.
 */
typedef enum
{
    ___0,___1,___2,___3,___4,___5
}CLK;

typedef enum
{
	TX,RX
}Mode;

//--------------------- Structures ----------------------------------

/**
 * @name    SPI_ConfigType
 * @brief   SPI_ConfigTypee responsible for dynamic configuration of SPI module
 */
typedef struct
{
    Clock_Select cke;   /**< a user defined datatype to select the SPI clock select configuration */
    Polarity polarity;  /**< a user defined datatype to select the SPI polarity configuration */
    CLK clk;            /**< a user defined datatype to select the SPI clock configuration */
    Mode mode;          /**< a user defined datatype to select the SPI mode configuration */
}SPI_ConfigType;

// ------------------ function prototypes ---------------------------

/**
 * \b Brief: This is SPI Module Initialization Function 
 * @param Config_Ptr SPI_ConfigType * Config_Ptr to select Config_Ptr
 * @return void 
 */
void SPI_init(SPI_ConfigType * Config_Ptr);

/**
 * \b Brief: This is function to transmit data using SPI
 * @param data uint8 data to select transmitted data
 * @return void 
 */
void SPI_Transmit(uint8 data);

#endif /* SPI_H */
