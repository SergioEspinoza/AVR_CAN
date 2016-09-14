/****************************************************************** 
* can_application.c
* Created on: Aug 6, 2015
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
#ifndef can_application_C_
 #define can_application_C_
#endif
/**
 * \addtogroup can_application_module
 * @{
 */

/******************************************************************/
/*    I N C L U D E   F I L E S                                   */
/******************************************************************/
#include <can_midleware.h>
#include <cpu.h>
#include <usart.h>
#include <task_scheduler.h>
#include <watchdog.h>
#include <hardware_init.h>
#include <can_driver.h>
#include <avr/interrupt.h>
#include <print_functions.h>
#include <can_message_configs.h>
#include <Indicator_Driver.h>

/*******************************************************************************************/
/*    M A C R O S                                                                          */
/*******************************************************************************************/
#define TEST_MODE_CAN_TX  					0
#define MCU_STATUS_REPORT_CAN  				1
#define CAN_ERROR_TX_REPORT_LED				1
/*******************************************************************************************/
/*    F U N C T I O N   P R O T O T Y P E S                                                */
/*******************************************************************************************/
volatile uint8_t can_initialization=0;

#if TEST_MODE_CAN_TX == 1
volatile uint32_t counterxxxxx=0;
void TX_CAN_SEND_DummyTask(void){
	if(counterxxxxx==10000){
		CanMw_Send_TX_Messages();
		counterxxxxx=0;
	}else{
		counterxxxxx++;
	}
}
#endif

void Can_AppLED(void);

void Can_App_Init(void){
	Can_Driver_Init();
	CanMW_APP_Init();

	CanMW_InitMail_Box(MailBox_0);
	CanMW_InitMail_Box(MailBox_1);
	CanMW_InitMail_Box(MailBox_2);
	CanMW_InitMail_Box(MailBox_3);
	CanMW_InitMail_Box(MailBox_4);

	CanMW_InitMail_Box(Service_Mail);
	
#ifndef UART_OR_TWI_INTERFACE
	schedulerSetupItem( 1, TRUE, PRD_FUEL );
	schedulerSetupItem( 2, TRUE, PRD_TACHO );
	schedulerSetupItem( 3, TRUE, PRD_SPEED );
#endif
	ENABLE_CAN_RECEIVE_INTERRUPT();
	can_initialization=1;
}
void CAN_App_50ms_Task(void){


}
void Can_App_IDLE_Hook(void){
	if(CanMW_Event_Get()){
		CanMW_ReSync_Driver();

		CanMW_Event_Clean();
		ENABLE_CAN_RECEIVE_INTERRUPT();
		ENABLE_ALL_INTERRUPTS();
		sei();
	}

	#if TEST_MODE_CAN_TX == 1
	TX_CAN_SEND_DummyTask();
	#endif

	if(can_initialization==0){
		CanMW_ReConf_Driver();
		can_initialization=1;
	}
#if MCU_STATUS_REPORT_CAN == 1	
StatusCAN_Report_MCU();
#endif

#if CAN_ERROR_TX_REPORT_LED == 1
	ErrorTask();
#endif

}

void ErrorTask(void){
	Can_err_type status_error=0;

	status_error=Get_CAN_Tx_error();
	if(status_error){
		Led_Err(LED_INDICATOR_ON);
	}else{
		Led_Err(LED_INDICATOR_OFF);
	}
}
void Can_AppLED(void){
	CanMw_Message Mbread;

	Get_Message_FromMbox(RX_ACC_CAN,&Mbread);
	if(Mbread.data[0]==0x20){
		Led_Tx(LED_INDICATOR_ON);
	}else{
		Led_Tx(LED_INDICATOR_OFF);
	}
}
/**
 * @}
 */
