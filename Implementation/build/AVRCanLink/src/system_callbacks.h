/*
 * system_callbacks.h
 *
 *  Created on: Aug 13, 2015
 *      Author: 10014232
 */

#ifndef SYSTEM_CALLBACKS_H_
#define SYSTEM_CALLBACKS_H_

#include <can_midleware.h>
#include <can_message_configs.h>
#include <cpu.h>

#define NUM_CONTROL_BYTES    ( 0x04 ) // OP ( 1 byte ) + ID (2 bytes) + DLC ( 1 byte)
#define DATA_LEN             ( 0x0E )
#define CAN_READ             ( 0xA )
#define CAN_WRITE            ( 0xB )
#define CAN_READ_REPLY       ( 0xC )
#define CAN_WRITE_REPLY      ( 0xD )
#define GET_HIGH_BYTE( x )   ( ( ( x ) & ( 0xFF00 ) ) >> ( 8 ) )
#define GET_LOW_BYTE( x )    ( ( x ) & ( 0x00FF ) )
#define GET_HIGH_NIBBLE( x ) ( ( ( x ) & ( 0xF0 ) ) >> ( 4 ) )
#define GET_LOW_NIBBLE( x )  ( ( x ) & ( 0x0F ) )
#define CAT_NIBBLES( x, y )  ( ( ( ( x ) & ( 0x0F ) ) << 4 ) \
                             | ( ( y ) & ( 0x0F ) ) )
#define CAT_BYTES( x, y )    ( ( ( ( x ) & ( 0x00FF ) ) << 8 ) \
                             | ( ( y ) & ( 0x00FF ) ) )

void cbSetRXBuffer( uint8_t** data, uint32_t* len);
void cbSetTXBuffer( uint8_t** data, uint32_t* len);
void cbDecodeReceivedData( uint8_t *data, uint32_t len );
uint32_t cbFetchData( uint8_t* data );
uint8_t cbStartOfFrame( uint8_t data );
void cbSetupReply( uint8_t* in, uint8_t* out, uint32_t *len, uint8_t reply );
uint8_t cbCommitData( uint8_t* in, uint8_t* out, uint32_t idx, uint32_t len );
#endif /* SYSTEM_CALLBACKS_H_ */
