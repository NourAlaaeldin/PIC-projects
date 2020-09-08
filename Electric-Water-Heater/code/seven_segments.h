/**
 * @file    seven_segments.h
 * @brief   seven_segments Module Header File for this program 
 * @author  Nour
 * @date    28/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef SEVEN_SEGMENTS_H
#define SEVEN_SEGMENTS_H

//------------------ File Inclusions -------------------------------

#include "std_types.h"

//------------------  function prototypes --------------------------


/**
 * \b Brief: This is The seven segments Module Initialization Function 
 * @param void 
 * @return void 
 */
void seven_segment_init(void);

/**
 * \b Brief: This is the Function to display number on 7 segment
 * @param num uint8 num to set num 
 * @return void 
 */
void display_num(uint8 num);

/**
 * \b Brief: This is the Function to display number on 2 7 segments
 * @param num uint8 num to set num 
 * @return void 
 */
void display_num_2_7_seg(uint8 num);

/**
 * \b Brief: This is the Function to turn off 2 7 segments 
 * @param void 
 * @return void 
 */
void turn_off_2_7_seg(void);

#endif /* SEVEN_SEGMENTS_H */
