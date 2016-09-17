/*---------------------------------------------------------------------------*/
/**
 *  \file twi_at90can128.h
 *  \author Roberto Alejandro Flores Estrada
 *  \since 13/07/2015
 *
 */

#ifndef TWI_AT90CAN128_H_
#define TWI_AT90CAN128_H_

#include <cpu.h>
#include <util/twi.h>
#include <system_callbacks.h>


#define TW_SCL_FREQ             ( 100000 )
#define TWIADDR                 ( 0x39 ) /**< LSB in TWAR is TWGCE, which indicates
                                              if slave responds to the general call*/
#define TWCR_DEFAULT            ( 0x00 )
#define TWDR_DEFAULT            ( 0xFF )
#define TWPS_VALUE              ( 0x00 )
#define TWBR_VALUE              ( ( ( OSCSPEED ) \
                                - 16 * ( TW_SCL_FREQ ) ) \
                                >> ( ( 2 * ( TWPS_VALUE ) ) + 1 ) ) \
                                / ( TW_SCL_FREQ )

#define TW_GLOBAL_CALL_ON       ( 0x01 )
#define TW_BIT_ON               ( 0x01 )
#define TW_BIT_OFF              ( 0x00 )
/*
 * \f$ TWBR=\frac{(clock_freq-16(twi_freq))>>(2TWPS+1)}{twi_freq} \f$
 */
typedef union TWControlRegisterBitfields
{
    struct
    {
        uint8_t btwie:   1; /**< Enables TW interruption */
        uint8_t btwnc:   1; /**< Reserved */
        uint8_t btwen:   1; /**< Activates the TW interface, enables SDA
                                 & SCL pins*/
        uint8_t btwwc:   1; /**< Indicates an invalid access to Data Register
                                 occurred, shall be done when TWINT is high*/
        uint8_t btwsto:  1; /**< Sends STOP condition at master mode, turns
                                 SCL and SDA to high impedance at slave mode*/
        uint8_t btwsta:  1; /**< Intends to become Master and sends a Start
                                 condition*/
        uint8_t btwea:   1; /**< */
        uint8_t btwint:  1; /**< Interrupt flag, cleared by writing a one
                                 over it in software*/
                            /** SCL line will be held low until TWINT is
                             * cleared, this allows the data be processed
                             * before sending/capturing the next byte.*/
    }bits; /**< */
    uint8_t byte; /**< */
}twcrBf;

void twiAt90can128Init( uint8_t gCallEnable, uint8_t address,
                          uint8_t baudrate, uint8_t prescaler );
void twiAt90can128EnableInterrupt( uint8_t btwie );
uint8_t twiAt90can128MasterSendMsg( uint8_t address, uint8_t *data,
                                 uint32_t length, uint8_t opt );
uint8_t* twiAt90can128MasterGetData( void );
uint8_t* twiAt90can128SlaveGetData( void );
uint8_t twiAt90can128IsBusy( void );
uint8_t twiAt90can128EvaluateStep( void );

#endif /* TWI_AT90CAN128_H_ */
