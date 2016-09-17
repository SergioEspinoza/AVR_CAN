/****************************************************************** 
 * main.c
 * Created on: Jul 14, 2015
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
 *© 2015
 *****************************************************************/
#ifndef main_C_
#define main_C_
#endif
/**
 * \addtogroup main_module
 * @{
 */

/******************************************************************/
/*    I N C L U D E   F I L E S                                   */
/******************************************************************/
#include <cpu.h>
#include <task_scheduler.h>
#include <watchdog.h>
#include <hardware_init.h>
#include <can_driver.h>
#include <can_midleware.h>
#include <avr/interrupt.h>
#include <print_functions.h>
#include <can_message_configs.h>
#include <can_application.h>
/*******************************************************************************************/
/*    M A C R O S                                                                          */
/*******************************************************************************************/

/*******************************************************************************************/
/*    F U N C T I O N   P R O T O T Y P E S                                                */
/*******************************************************************************************/
int  main(void){

	CAN_Main_Board_Init();
	Can_App_Init();
	ENABLE_ALL_INTERRUPTS();
	can_ctrl_enable_controller();
	schedulerInit( );
	sei();
 	while(1){
	      schedulerEventHandler();
	      Can_App_IDLE_Hook();

		watchdog_reset( );
	}

	return 0;
}


/**
 * @}
 */
