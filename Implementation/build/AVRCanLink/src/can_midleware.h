/****************************************************************** 
* can_midleware.h
* Created on: Aug 3, 2015
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
 
#ifndef AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MIDLEWARE_H_
#define AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MIDLEWARE_H_

#ifndef can_midleware_C_
#define can_midleware_EXTERN extern
#else
#define can_midleware_EXTERN
#endif /* can_midleware_C_ */

/* Included Headers */
#include <stdint.h>
#include <can_types.h>
#include <can_driver.h>




#define CAN_MW_LEN	(8+1)
typedef enum{
	INTERRUPT_CAN_OFF=0,
	INTERRUPT_CAN_LEVEL_1,
	INTERRUPT_CAN_LEVEL_2,
	INTERRUPT_CAN_LEVEL_3,
	INTERRUPT_CAN_LEVEL_4,
	INTERRUPT_CAN_LEVEL_5,
	INTERRUPT_CAN_LEVEL_6,
}CanMW_Interrupt_level;

typedef struct{
	CAN_ID_type conf_message_id;
	CAN_ID_type conf_mask;
   can_dlc_type conf_dlc;
   can_int_ctrl enable_int;
}CanMW_MBox_config;

typedef struct{
	     CAN_ID_type message_id;
	    can_dlc_type dlc;
	can_message_data data[CAN_MW_LEN];
          can_tstamp stamp;
          Can_timmer_type ttc_timmer;
}CanMw_Message;

typedef struct{
	MBox_type                 mailbox;
	CAN_Mode_type                mode;
	can_int_ctrl           int_status;
	CAN_ID_type 			conf_mask;
	can_int_ctrl 		   enable_int;
	CanMw_Message			      msg;
}CanMW_MBox;




//can_midleware_EXTERN	

can_midleware_EXTERN void CanMW_set_mutex(can_Ir_lock state);
can_midleware_EXTERN can_Ir_lock CanMW_get_mutex(void);
can_midleware_EXTERN can_event CanMW_Event_Get(void);
can_midleware_EXTERN void CanMW_Event_Clean(void);
can_midleware_EXTERN void CanMW_APP_Init(void);
can_midleware_EXTERN void CanMw_Update_App(void);
can_midleware_EXTERN void CanMw_MailBox_Rx_Handler(MBox_type mail_box_no);
can_midleware_EXTERN void CanMW_ReceivedRxHandle(void);

can_midleware_EXTERN void Write_Message_Mbox(MBox_type mail,CanMW_MBox  * mail_box);
can_midleware_EXTERN void Get_Message_FromMbox(MBox_type mail,CanMw_Message * message);
can_midleware_EXTERN void Get_MboxConfig(MBox_type mail,CanMW_MBox * MboxConfig);
can_midleware_EXTERN void CanMw_Send_TX_Messages(void);
can_midleware_EXTERN void CanMw_Send_TX_Message( MBox_type mailbox_num );
can_midleware_EXTERN void CanMW_ReSync_Driver(void);
can_midleware_EXTERN void CanMW_ReConf_Driver(void);
can_midleware_EXTERN void StatusCAN_Report_MCU(void);
can_midleware_EXTERN void CanMW_InitMail_Box(MBox_type mailbox_num,CAN_Mode_type operation_mode,can_dlc_type data_l,CAN_ID_type msg_id,CAN_ID_type mbox_mask,can_int_ctrl enable_ints,Can_timmer_type time);
#endif /* AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_MIDLEWARE_H_ */
