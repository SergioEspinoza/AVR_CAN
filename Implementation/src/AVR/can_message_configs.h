/****************************************************************** 
* can_message_configs.h
* Created on: Aug 4, 2015
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
 
#ifndef AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MESSAGE_CONFIGS_H_
#define AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MESSAGE_CONFIGS_H_

#ifndef can_message_configs_C_
#define can_message_configs_EXTERN extern
#else
#define can_message_configs_EXTERN
#endif /* can_message_configs_C_ */

/* Included Headers */
#include <task_scheduler.h>


//can_message_configs_EXTERN	
typedef enum{
	RX_ACC_CAN=0,
	RX_PRN_CAN,
	TX_CUSTOM
}M_box_assign;

typedef enum{
	HW_BOX_0=0,
	HW_BOX_1,
	HW_BOX_2,
	HW_BOX_3,
	HW_BOX_4,
	HW_BOX_5,
	NUM_MAILBOXES=HW_BOX_5
}MailBox_Hw;

#define CAN_STATUS_MESSAGE	0x0010
/*CAN MESSAGES*/
#define ECU_FUEL    0x0160
#define ECU_TACHO	0x0093
#define ECU_SPEED	0x0081
#define ECU_TEMP    0x0120

#define PRD_FUEL    SCH_200MS_SETUP
#define PRD_TACHO	SCH_50MS_SETUP
#define PRD_SPEED	SCH_50MS_SETUP
#define PRD_TEMP    SCH_200MS_SETUP

#ifdef UART_OR_TWI_INTERFACE
#define MailBox_0		HW_BOX_0 	,MAIL_BOX_DISABLE		, 8 ,   (CAN_ID_type)0x0020,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , 10
#define MailBox_1		HW_BOX_1 	,MAIL_BOX_ENABLE_TX		, 8 ,	(CAN_ID_type)ECU_FUEL,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_FUEL
#define MailBox_2		HW_BOX_2	,MAIL_BOX_ENABLE_TX		, 8 ,   (CAN_ID_type)ECU_TACHO,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_TACHO
#define MailBox_3		HW_BOX_3 	,MAIL_BOX_ENABLE_TX 	, 8 ,	(CAN_ID_type)ECU_SPEED,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_SPEED
#define MailBox_4		HW_BOX_4 	,MAIL_BOX_DISABLE 	, 8 ,	(CAN_ID_type)ECU_TEMP,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_TEMP
#define Service_Mail	HW_BOX_5	,MAIL_BOX_ENABLE_TX , 8 ,		(CAN_ID_type)CAN_STATUS_MESSAGE,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , 10
#else
#define MailBox_0		HW_BOX_0 	,MAIL_BOX_DISABLE		, 8 ,   (CAN_ID_type)0x0020,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , 0
#define MailBox_1		HW_BOX_1 	,MAIL_BOX_ENABLE_RX		, 8 ,	(CAN_ID_type)ECU_FUEL,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_FUEL
#define MailBox_2		HW_BOX_2	,MAIL_BOX_ENABLE_RX		, 8 ,   (CAN_ID_type)ECU_TACHO,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_TACHO
#define MailBox_3		HW_BOX_3 	,MAIL_BOX_ENABLE_RX 	, 8 ,	(CAN_ID_type)ECU_SPEED,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_SPEED
#define MailBox_4		HW_BOX_4 	,MAIL_BOX_DISABLE 	, 8 ,	(CAN_ID_type)ECU_TEMP,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , PRD_TEMP
#define Service_Mail	HW_BOX_5	,MAIL_BOX_ENABLE_RX , 8 ,		(CAN_ID_type)CAN_STATUS_MESSAGE,  (CAN_ID_type)0x07FF ,INTERRUPT_CAN_LEVEL_1 , 10
#endif
#define ServiceMail_Message_Box	HW_BOX_5

#define Config_Interface_CanDriver(x)	Can_Configure_MailBox(x)

#define Config_All_Can()	\
		Config_Interface_CanDriver(MailBox_0);\
		Config_Interface_CanDriver(MailBox_2); Config_Interface_CanDriver(MailBox_1)

#endif /* AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MESSAGE_CONFIGS_H_ */
