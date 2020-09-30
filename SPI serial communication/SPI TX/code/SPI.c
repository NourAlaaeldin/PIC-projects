/**
 * @file    SPI.c
 * @brief   SPI Module Source File for this program 
 * @author  Nour
 * @date    29/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "SPI.h"
#include "PORT.h"

//--------------------- Private Function Prototypes ----------------

static void SPI_TX_init(void);
static void SPI_RX_init(void);

//--------------------- Public Function Definitions ----------------

void SPI_init(SPI_ConfigType * Config_Ptr)
{
    SSPCON |= Config_Ptr -> clk | (Config_Ptr -> polarity << 4) | 0x20;
    SSPSTAT = Config_Ptr -> cke << 6;    
    
    if(Config_Ptr -> mode == TX)
    {
        SPI_TX_init();
    }
    else if(Config_Ptr -> mode == RX)
    {
        SPI_RX_init();
    }
}

void SPI_Transmit(uint8 data)
{      
    SSPBUF = data;
}

//--------------------- Private Function Definitions ----------------

/* master */
static void SPI_TX_init(void)
{
    /* SCK -> output */
    set_pin_direction(PORTC_CONFIG,PIN3,OUTPUT);
    
    /* SDO -> output */
    set_pin_direction(PORTC_CONFIG,PIN5,OUTPUT);
    
    /* SS -> output */
    set_pin_direction(PORTA_CONFIG,PIN5,OUTPUT);
}

/* slave */
static void SPI_RX_init(void)
{
    /* SCK -> input */
    set_pin_direction(PORTC_CONFIG,PIN3,INPUT);
    
    /* SDO -> input */
    set_pin_direction(PORTC_CONFIG,PIN5,INPUT);
    
    /* SS -> input */
    set_pin_direction(PORTA_CONFIG,PIN5,INPUT);
    
    /* enable receive interrupt */
    PIE1 |= 0x08;    
}
