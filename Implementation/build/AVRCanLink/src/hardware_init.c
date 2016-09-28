/****************************************************************** 
* hardware_init.c
* Created on: Jul 30, 2015
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*� 2015
*****************************************************************/ 
#ifndef hardware_init_C_
 #define hardware_init_C_
#endif
/**
 * \addtogroup hardware_init_module
 * @{
 */

/******************************************************************/
/*    I N C L U D E   F I L E S                                   */
/******************************************************************/
#include <watchdog.h>
#include <hardware_init.h>
#include <Indicator_Driver.h>
#include <usart.h>
#include <cpu.h>
#include <twi_at90can128.h>
/*******************************************************************************************/
/*    M A C R O S                                                                          */
/*******************************************************************************************/
void CAN_Main_Board_Init(void){
	watchdog_on(WDT_TIME_2_1S);
#ifdef UART_OR_TWI_INTERFACE
    //Here enable UART
    usart_init(BAUD_RATE_19_2k);
    usart_enable_interrupts( );
#else
    //Here enable TWI
    twiAt90can128Init( FALSE, TWIADDR, TWBR_VALUE, TWPS_VALUE );
    twiAt90can128EnableInterrupt( TRUE );
#endif
	Led_Indicators_Init();
	asm("NOP");
}

/*******************************************************************************************/
/*    F U N C T I O N   P R O T O T Y P E S                                                */
/*******************************************************************************************/

/**
 * @}
 */
