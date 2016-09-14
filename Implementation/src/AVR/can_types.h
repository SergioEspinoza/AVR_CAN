/****************************************************************** 
* can_types.h
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
 
#ifndef AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_TYPES_H_
#define AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_TYPES_H_

#ifndef can_types_C_
#define can_types_EXTERN extern
#else
#define can_types_EXTERN
#endif /* can_types_C_ */

/* Included Headers */
#include <stdint.h>

typedef enum{
	MUTEX_RELEASE_CHANNEL=0,
	MUTEX_LOCK_CHANNEL
}CAN_INT_MUTEX;

typedef enum{
	CAN_SUCESS=0,
	CAN_ERROR
}Can_status_states;
typedef uint8_t  can_event;
typedef uint8_t  can_Ir_lock;
typedef uint16_t CAN_ID_type;
typedef uint8_t  Can_err_type;
typedef uint16_t Can_timmer_type;
typedef uint8_t  MBox_type;
typedef uint8_t  CAN_Mode_type;
typedef uint8_t  can_dlc_type;
typedef uint8_t  can_int_ctrl;
typedef uint8_t  can_message_data;
typedef uint16_t can_tstamp;
typedef uint8_t  can_status;
#endif /* AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_TYPES_H_ */
