/****************************************************************** 
* cpu.h
* Created on: Jul 9, 2015
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
 
#ifndef IMPLEMENTATION_INCLUDE_CPU_H_
#define IMPLEMENTATION_INCLUDE_CPU_H_

#ifndef cpu_C_
#define cpu_EXTERN extern
#else
#define cpu_EXTERN
#endif /* cpu_C_ */

#include <board_configs.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//#define UART_OR_TWI_INTERFACE

#ifndef TRUE
#define TRUE        ( 1 )
#endif

#ifndef FALSE
#define FALSE       ( 0 )
#endif

#ifndef NULL
#define NULL         ( (void*) ( 0 ) )
#endif

/** AT90CAN BOARD XTAL  */
#define OSCSPEED					BOARD_MAIN_CLOCK		/* in Hz */

#endif /* IMPLEMENTATION_INCLUDE_CPU_H_ */
