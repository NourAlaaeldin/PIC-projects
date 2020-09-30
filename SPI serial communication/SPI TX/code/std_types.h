/**
 * @file    std_types.h
 * @brief   Standard Types Header File for this program 
 * @author  Nour
 * @date    16/9/2019
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------
#ifndef STANDARD_LIBRARY_H
#define STANDARD_LIBRARY_H

//--------------------- Preprocessor Defines -----------------------

#define LOW				0u /**< a preprocessor to define low */
#define HIGH			1u /**< a preprocessor to define high */

#define FALSE			0u /**< a preprocessor to define false */
#define TRUE    		1u /**< a preprocessor to define true */

#define INPUT			1u /**< a preprocessor to define input */
#define OUTPUT			0u /**< a preprocessor to define output */

#define NULL_PTR		(void *)0 /**< a preprocessor to define null pointer */

//--------------------- Public Data Types --------------------------

typedef unsigned char uint8; /**< a user defined datatype to define uint8 */
typedef unsigned short uint16; /**< a user defined datatype to define uint16 */
typedef unsigned long uint32; /**< a user defined datatype to define uint32 */

#endif /* STANDARD_LIBRARY_H */
