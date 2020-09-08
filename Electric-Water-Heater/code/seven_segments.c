/**
 * @file    seven_segments.c
 * @brief   seven_segments Module Source File for this program 
 * @author  Nour
 * @date    28/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <htc.h>
#include "PORT.h"
#include "DIO.h"
#include "seven_segments.h"

//--------------------- Preprocessor Defines -----------------------

#define _XTAL_FREQ 4000000

#define CONTROL                         /**< a preprocessor to define control mode */
#define BCD                             /**< a preprocessor to define BCD usage */
#define SEG_7_DIR       PORTB_CONFIG    /**< a preprocessor to define seven segments direction */

#ifdef BCD
#define SEC_7_GROUP     FIRST_GROUP     /**< a preprocessor to define seven segments group */
#endif /* BCD */

#ifdef CONTROL
#define RIGHT_SEVEN_SEGMENT_PORT    PORTD_CONFIG    /**< a preprocessor to define right seven segments port */
#define LEFT_SEVEN_SEGMENT_PORT     PORTD_CONFIG    /**< a preprocessor to define left seven segments port */
#define RIGHT_SEVEN_SEGMENT_PIN     PIN6            /**< a preprocessor to define right seven segments pin */
#define LEFT_SEVEN_SEGMENT_PIN      PIN7            /**< a preprocessor to define left seven segments pin */
#endif /* CONTROL */

//--------------------- Public Function Definitions ----------------

void seven_segment_init(void)
{
    /* set seven segment as output */
    /* initial value is low */
#ifdef CONTROL
    set_pin_direction(RIGHT_SEVEN_SEGMENT_PORT,RIGHT_SEVEN_SEGMENT_PIN,OUTPUT);
    write_pin(RIGHT_SEVEN_SEGMENT_PORT,RIGHT_SEVEN_SEGMENT_PIN,LOW);
    
    set_pin_direction(LEFT_SEVEN_SEGMENT_PORT,LEFT_SEVEN_SEGMENT_PIN,OUTPUT);
    write_pin(LEFT_SEVEN_SEGMENT_PORT,LEFT_SEVEN_SEGMENT_PIN,LOW);
#endif /* CONTROL */
    
#ifdef BCD
    set_group_direction(SEG_7_DIR,SEC_7_GROUP,OUTPUT);
    write_group(SEG_7_DIR,SEC_7_GROUP,LOW);
#endif /* BCD */
    
#ifdef NO_BCD
    set_port_direction(SEG_7_DIR,OUTPUT);
    write_port(SEG_7_DIR,LOW);
#endif /* NO_BCD */
}

void display_num(uint8 num)
{
    /* set the value to the seven segment */
#ifdef BCD
    write_group_value(SEG_7_DIR,SEC_7_GROUP,num);    
#endif /* BCD */
    
#ifdef NO_BCD
    uint8 segments_code[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
    write_port(SEG_7_DIR,segments_code[num]);
#endif /* NO_BCD */
}

#ifdef CONTROL
void display_num_2_7_seg(uint8 num)
{
    /* calculate right digit value */
    uint8 right_digit = num % 10;
    write_pin(LEFT_SEVEN_SEGMENT_PORT,LEFT_SEVEN_SEGMENT_PIN,LOW);
    write_pin(RIGHT_SEVEN_SEGMENT_PORT,RIGHT_SEVEN_SEGMENT_PIN,HIGH);
    display_num(right_digit);
    __delay_ms(5);
    
    /* calculate left digit value */
    uint8 left_digit = num / 10;
    write_pin(LEFT_SEVEN_SEGMENT_PORT,LEFT_SEVEN_SEGMENT_PIN,HIGH);
    write_pin(RIGHT_SEVEN_SEGMENT_PORT,RIGHT_SEVEN_SEGMENT_PIN,LOW);
    display_num(left_digit);
    __delay_ms(5);
}

void turn_off_2_7_seg(void)
{
    /* turn off two seven segments by setting the values low */
    write_pin(LEFT_SEVEN_SEGMENT_PORT,LEFT_SEVEN_SEGMENT_PIN,LOW);
    write_pin(RIGHT_SEVEN_SEGMENT_PORT,RIGHT_SEVEN_SEGMENT_PIN,LOW);
}
#endif /* CONTROL */
