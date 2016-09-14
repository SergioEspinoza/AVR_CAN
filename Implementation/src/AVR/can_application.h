/****************************************************************** 
* can_application.h
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
 
#ifndef AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_APPLICATION_H_
#define AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_APPLICATION_H_

#ifndef can_application_C_
#define can_application_EXTERN extern
#else
#define can_application_EXTERN
#endif /* can_application_C_ */

/* Included Headers */



//can_application_EXTERN	

can_application_EXTERN void CAN_App_50ms_Task(void);
can_application_EXTERN void Can_App_Init(void);
can_application_EXTERN void Can_App_200ms_Task(void);
can_application_EXTERN void Can_App_IDLE_Hook(void);
#endif /* AVRCAN_DEV_IMPLEMENTATION_INCLUDE_CAN_APPLICATION_H_ */
