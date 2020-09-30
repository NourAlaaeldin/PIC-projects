/**
 * @file    UART.c
 * @brief   UART Module Source File for this program 
 * @author  Nour
 * @date    17/9/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include <pic16f877a.h>
#include "UART.h"

//--------------------- Private Function Prototypes ----------------

static void UART_TX_init(void);
static void UART_RX_init(void);

//--------------------- Public Function Definitions ----------------

void UART_init(UART_ConfigType * Config_Ptr)
{
    /* must be set to configure UART */
    TRISC6 = 1;  
    TRISC7 = 1;  
  
    /* enable serial port */
    RCSTA |= 0x80;
    
    if(Config_Ptr -> mode == TX)
    {
        UART_TX_init();
    }
    else if(Config_Ptr -> mode == RX)
    {
        UART_RX_init();
    }
    
    /* set baud rate */
    SPBRG = Config_Ptr -> baud_rate;
}

void UART_Transmit(uint8 data)
{
    /* wait until TSR is empty */
    while(!(TXSTA & 0x02));
    
    TXREG = data;
}

//--------------------- Private Function Definitions ----------------

static void UART_TX_init(void)
{
    /*
     * 1. transmit enabled
     * 2. Asynchronous mode is selected
     * 3. High speed is selected
     */
    TXSTA = 0x24;
}

static void UART_RX_init(void)
{
    /*
     * 1. Asynchronous mode is selected
     * 2. High speed is selected
     */
    TXSTA = 0x04;    
    
    /* enable continuous reception */
    RCSTA |= 0x10;
    
    /* enable receive interrupt */
    PIE1 |= 0x20;
}
