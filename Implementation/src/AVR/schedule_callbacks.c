/*---------------------------------------------------------------------------*/
/**************************************************************************//**
 *  \file      schedule_callbacks.c
 *  \addtogroup timers
 *  @{
 *  \author    Roberto Alejandro Flores Estrada
 *  \since     10/08/2015
 *
 *****************************************************************************/

#include <schedule_callbacks.h>
#include <can_midleware.h>
#include <can_driver.h>
#include <Indicator_Driver.h>
#include <can_midleware.h>
#include <task_scheduler.h>
/*---------------------------------------------------------------------------*/

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox0( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox0( void )
{
    CanMw_Send_TX_Message( 0 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox1( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox1( void )
{
    CanMw_Send_TX_Message( 1 );
	
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox2( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox2( void )
{
    CanMw_Send_TX_Message( 2 );
	
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox3( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox3( void )
{
    CanMw_Send_TX_Message( 3 );
	
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox4( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox4( void )
{
    CanMw_Send_TX_Message( 4 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox5( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox5( void )
{
    CanMw_Send_TX_Message( 5 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox6( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox6( void )
{
    CanMw_Send_TX_Message( 6 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox7( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox7( void )
{
    CanMw_Send_TX_Message( 7 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox8( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox8( void )
{
    CanMw_Send_TX_Message( 8 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox9( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox9( void )
{
    CanMw_Send_TX_Message( 9 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox10( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox10( void )
{
    CanMw_Send_TX_Message( 10 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox11( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox11( void )
{
    CanMw_Send_TX_Message( 11 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox12( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox12( void )
{
    CanMw_Send_TX_Message( 12 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox13( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox13( void )
{
    CanMw_Send_TX_Message( 13 );
    return;
}

/**************************************************************************//**
 * \fn      void schedule_callback_Mailbox14( void )
 * \brief
 * \return
 *****************************************************************************/
void schedule_callback_Mailbox14( void )
{
    CanMw_Send_TX_Message( 14 );
    return;
}

/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox0( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox0( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 0, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox(0, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox1( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox1( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 1, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 1, &MboxCfg );
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox2( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox2( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 2, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 2, &MboxCfg );
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox3( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox3( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 3, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 3, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox4( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox4( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 4, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 4, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox5( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox5( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 5, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox(5, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox6( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox6( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 6, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 6, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox7( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox7( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 7, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 7, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox8( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox8( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 8, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 8, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox9( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox9( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 9, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 9, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox10( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox10( void )

{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 10, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 10, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox11( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox11( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 11, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 11, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox12( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox12( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 12, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 12, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox13( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox13( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 13, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 13, &MboxCfg);
	return;
}
/**************************************************************************//**
 * \fn      void timeout_callback_Mailbox14( void )
 * \brief
 * \return
 *****************************************************************************/
void timeout_callback_Mailbox14( void )
{
	CanMW_MBox MboxCfg;
	Get_MboxConfig( 14, &MboxCfg );
	MboxCfg.msg.ttc_timmer = SCH_INVALID;
	Write_Message_Mbox( 14, &MboxCfg);
	return;
}