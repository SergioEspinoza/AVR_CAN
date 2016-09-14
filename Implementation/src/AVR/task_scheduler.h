/*---------------------------------------------------------------------------*/
/*
 * task_scheduler.h
 *
 *  Created on: Aug 6, 2015
 *      Author: 10014232
 */

#ifndef MSG_SCHEDULER_H_
#define MSG_SCHEDULER_H_

#include <timers_at90can128.h>


#define SCH_COUNT_INIT                   ( 0 )
#define SCH_HIGH_STATE                   ( TRUE )
#define  SCH_LOW_STATE                   ( FALSE )
typedef void (*FUNC)( void );

typedef struct
{
    uint8_t low_cycles;
    uint8_t high_cycles;
}waveform;

typedef struct
{
    uint8_t active;
    waveform *dty_cycles;
    uint8_t state;
    uint8_t count;
    FUNC function;
} schedulerItem;

typedef enum
{
    SCH_INVALID,
    SCH_10MS_SETUP,
    SCH_15MS_SETUP,
    SCH_20MS_SETUP,
    SCH_25MS_SETUP,
    SCH_30MS_SETUP,
    SCH_35MS_SETUP,
    SCH_40MS_SETUP,
    SCH_45MS_SETUP,
    SCH_50MS_SETUP,
    SCH_55MS_SETUP,
    SCH_60MS_SETUP,
    SCH_65MS_SETUP,
    SCH_70MS_SETUP,
    SCH_75MS_SETUP,
    SCH_80MS_SETUP,
    SCH_85MS_SETUP,
    SCH_90MS_SETUP,
    SCH_95MS_SETUP,
    SCH_100MS_SETUP,
    SCH_105MS_SETUP,
    SCH_110MS_SETUP,
    SCH_115MS_SETUP,
    SCH_120MS_SETUP,
    SCH_125MS_SETUP,
    SCH_130MS_SETUP,
    SCH_135MS_SETUP,
    SCH_140MS_SETUP,
    SCH_145MS_SETUP,
    SCH_150MS_SETUP,
    SCH_155MS_SETUP,
    SCH_160MS_SETUP,
    SCH_165MS_SETUP,
    SCH_170MS_SETUP,
    SCH_175MS_SETUP,
    SCH_180MS_SETUP,
    SCH_185MS_SETUP,
    SCH_190MS_SETUP,
    SCH_195MS_SETUP,
    SCH_200MS_SETUP,
    SCH_205MS_SETUP,
    SCH_210MS_SETUP,
    SCH_215MS_SETUP,
    SCH_220MS_SETUP,
    SCH_225MS_SETUP,
    SCH_230MS_SETUP,
    SCH_235MS_SETUP,
    SCH_240MS_SETUP,
    SCH_245MS_SETUP,
    SCH_250MS_SETUP,
    SCH_255MS_SETUP,
    SCH_260MS_SETUP,
    SCH_265MS_SETUP,
    SCH_270MS_SETUP,
    SCH_275MS_SETUP,
    SCH_280MS_SETUP,
    SCH_285MS_SETUP,
    SCH_290MS_SETUP,
    SCH_295MS_SETUP,
    SCH_300MS_SETUP,
    SCH_305MS_SETUP,
    SCH_310MS_SETUP,
    SCH_315MS_SETUP,
    SCH_320MS_SETUP,
    SCH_325MS_SETUP,
    SCH_330MS_SETUP,
    SCH_335MS_SETUP,
    SCH_340MS_SETUP,
    SCH_345MS_SETUP,
    SCH_350MS_SETUP,
    SCH_355MS_SETUP,
    SCH_360MS_SETUP,
    SCH_365MS_SETUP,
    SCH_370MS_SETUP,
    SCH_375MS_SETUP,
    SCH_380MS_SETUP,
    SCH_385MS_SETUP,
    SCH_390MS_SETUP,
    SCH_395MS_SETUP,
    SCH_400MS_SETUP
} sch_time_list;

#define SCHEDULER_BASE_FREQ              ( 0x64 )  // 1/20ms = 50Hz, T = 20ms
#define SCHEDULER_PRESCALER              ( 0x400 ) // 1024
#define SCHEDULER_PRESCALER_OPT          ( TMRN_PRESCALER_1024 )
#define SCHEDULER_TMR_WFG                ( TMR0_WFG_CTC )
#define SCHEDULER_TMR_MODE               ( TMR0_COMP_TGL_OC0A )
#define SCHEDULER_COMP_REG               ( ( ( OSCSPEED \
                                         / SCHEDULER_BASE_FREQ ) \
                                         / (2 * SCHEDULER_PRESCALER ) ) \
                                         - 1 )
#define SCHEDULER_INTERRUPT_EN           ( TRUE << OCIE0A )

void schedulerInit( void );
void schedulerSetupItem( uint8_t index, uint8_t active, sch_time_list time );
void schedulerEnableInterrupt( void );
void schedulerEventHandler( void );
void schedulerResetCount( uint8_t index );
/*---------------------------------------------------------------------------*/
#endif /* MSG_SCHEDULER_H_ */
