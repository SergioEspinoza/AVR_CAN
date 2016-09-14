#include <errno.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include"raspi_candrv.h"
#include "raspi_can_queue.h"
#include "raspi_gui_ipc.h"
#include "raspi_ipc_defs.h"


#define IN_SZ       25
#define FAKE_MSGS   3


//According to documented frame structure
    //       ___________________________________________________________________________________________
    //       |  Byte 0   |  Byte 1  | Byte 2  |  Byte 3 |  Byte 4      -    Byte ( n-1 )  |  Byte n     |
    //       |   I2C CMD |  ***  CAN ID ***   |    DLC  |  *******   CAN DATA  *********  |  I2C CHKSUM |
    //       ----------------------------------------------------------------------------------------
    //                   |                                                               |
    //                   |    ***********I2C DATA FIELD (Optional) *******************   |
    //                   -----------------------------------------------------------------

// fixed size for all fake reads
#define FAKE_READ_DATA_SZ 30 
#define FAKE_MSGS 3

char fake_read_mailbox_data[ FAKE_MSGS ][ FAKE_READ_DATA_SZ ] =
{
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 1
        0xB1,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        // CHKSM
        0x5b 
    },
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 2
        0xB2,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        //
        0x5c
    },
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 3
        0xB3,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        //
        0x5d
    }

};

char fake_read_wrong_mlbx_data[ FAKE_MSGS ] [ FAKE_READ_DATA_SZ] = 
{
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 3
        0xB2,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        // wrong checksum
        0xE3
    },
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 2
        0xB2,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        //  wrong ckksm
        0xE9
    },
    {
        // cmd =  I2C_CMD_MAILBOX_RESPONSE | mailbox = 3
        0xB2,
        // CAN ID
        0x25, 0x26, 
        // DLC
        0x19, 
        //data 25 bytes
        0x00, 0x01, 0x02, 0x03, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x05, 0x06, 0x07, 0x08, 0x04,
        0x00, 0x01, 0x02, 0x03, 0x04, 
        0x00, 0x01, 0x02, 0x03, 0x04, 
        //  wrong chksm
        0xE1
    }
};


#define TEST_DRIVER_RECEIVE   1
#define TEST_DRIVER_SEND      2
#define TEST_QUEUE_RECEIVE    3
#define TEST_SERVER_SEND      4
#define TEST_CLIENT_RECEIVE   5
#define TEST_GAUGE_CONTROL_TEST  6  
#define TEST_COMPLETE_INTEGRATION_TEST 7

static void raspi_function_test( int test_num );
static void raspi_can_driver_recv_test( void );
static void raspi_can_driver_send_test( void );
static void raspi_can_queue_test( void );
static void raspi_client_receive_test( void );
static void raspi_server_send_test( void );
static void raspi_gauge_control_test( void );
static void raspi_integration_test( void );


#define TRUE 0x01
#define FALSE 0x00
int main( int num, char** args  )
{
    int ret = 0;
    char usr_option = 0;
    char usr_input[ 2 ] = { 0 } ;

	#ifndef INTEGRATION_TEST
	
    while ( usr_option != 9 )
    {

        printf( "Raspi user space driver test\n\n\n" );
        printf( "\t Select test \n" );
        printf( "\t 1. User space driver receive \n"  
                " \t 2. User space driver send  \n " 
                " \t 3. can msg queue receive \n  " 
                " \t 4. IPC local socket server send test \n" 
                " \t 5. IPC local socket client receive test \n"
                " \t 6. IPC gage control IPC test\n"
				" \t 7. Complete Integration test"
                "\t 9. exit\n\n" );

        usr_input[0] = getchar();
        usr_option = atoi( usr_input );

        if( ( usr_option > 0 ) || ( usr_option < 4 ) )
        {
            raspi_function_test( usr_option );
        }
        else if( usr_option == 9 )
        {
            ret = -1;
        }
        else
        {
            printf( "choose valid option\n" );
        }
    }
	
	#else
	
	raspi_integration_test();

	#endif
	
    return ret;
}


static void raspi_function_test( int test_num )
{

    switch( test_num )
    {
        case TEST_DRIVER_RECEIVE:
            raspi_can_driver_recv_test( );
        break;

        case TEST_DRIVER_SEND:
            //raspi_can_driver_send_test( );
        break;


        case TEST_QUEUE_RECEIVE:
            raspi_can_queue_test( );
        break;
        case TEST_SERVER_SEND:
            raspi_server_send_test();
        break;

        case TEST_CLIENT_RECEIVE:
            raspi_client_receive_test();
        break;

        case TEST_GAUGE_CONTROL_TEST:
            raspi_gauge_control_test();
        break;
		
		case TEST_COMPLETE_INTEGRATION_TEST:
			raspi_integration_test();
		break;

        default:
        break;
    }

}

 #define TEST_GAUGE_ID  0x01
static void raspi_gauge_control_test( void )
{
    int sz = 0;
    int input = 0;
    int keep_going = true;
    int test_samples = 0;
    int i = 0;
    short int test_data[ ] =
    {
        0x0001,
        0x000f,
        0x0015, 
        0x001f,
        0x0020,
        0x0027,
        0x002f,
        0x0037,
        0x003f,
        0x0045
    };

    // data lenght
    test_samples = sizeof( test_data ) / sizeof( short int );

    if( raspi_gui_server_init() == 0 )
    {
        printf( "server successfull initialization\n" ); 
        printf( "server is now listening for client connections\n" );

        //accept one client connection 
        if ( raspi_gui_server_accept( ) == 0 )
        {
            printf( "incoming client conection\n" );

            while( keep_going )
            {

                printf( "press any key to start test\n " );
                printf( "press q to abort!\n" );

                input = getchar();

                if ( input != 'q' )
                { 

                    for( i = 0 ; i < test_samples ; i++ )
                    {

                        // maybe add unt later
                        sz = raspi_gui_server_send_gauge( TEST_GAUGE_ID, test_data[ i ], 0 );

                        if ( sz > 0 )
                        {
                            printf("succesfull server data transfer of %d bytes: \n", sz );
                            sleep( 1 );
                        } 
                        else if( sz == -1 )
                        {
                            perror( "send gauge error!\n" );
                            keep_going = false;
                            break;
                        }
                    }
                }
                else
                {
                    printf( "server abort!\n" );
                    keep_going = 0;
                }
            }
        }
        raspi_gui_server_close();
    }
    else
    {
        printf("server init failed!!\n");
    }
}

#define RASPI_TEST_ITER   50
											
#define CAN_MSG_GAGE_VALH_IDX  1
#define CAN_MSG_GAGE_VALL_IDX  0
#define INTEGRATION_TEST_GAUGE_ID	1

static void raspi_integration_test( void )
{
	int ret_val = 0;
    can_msg msg;
    int idx = 0;
	int sz = 0;
	int ipc_sz = 0;
    int input = 0;
    int keep_going = true;
    int i = 0;
	short int gage_val = 0;
	
    ret_val = raspi_can_msg_queue_init( );

    if ( ret_val ==  RASPI_CAN_OK )
    {
			if( raspi_gui_server_init() == 0 )
			{
				printf( "server successfull initialization\n" ); 
				printf( "server is now listening for client connections\n" );

				//accept one client connection 
				if ( raspi_gui_server_accept( ) == 0 )
				{
					printf( "incoming client conection\n" );

					if( rapspi_can_msg_queue_start( ) == 0 )
					{
						printf( "msg queue sucessfully started\n" );
						printf( "listening incoming can msgs\n" );
					
						while( keep_going )
						{
							//printf( "press any key to start test\n " );
							//printf( "press q to abort!\n" );

							//input = getchar();

							//if ( input != 'q' )
							//{
								for( i = 0 ; i < RASPI_TEST_ITER ; i++ )
								{	
									if( ( sz = raspi_can_msg_queue_size( ) ) > 0 )
									{
										for( idx = 0 ; idx < sz ; idx++ )
										{
											memset( &msg, 0x00, sizeof(can_msg) );
											raspi_can_msg_dequeue( &msg ); 

											printf( "msg dequeued\n" );
											printf( "msg ID 0x%04x \n", msg.msgID );

											gage_val = ( msg.data[ CAN_MSG_GAGE_VALH_IDX ] << 8 ) | ( msg.data[ CAN_MSG_GAGE_VALL_IDX ] );
										
											printf( "sending gage id: %d and gage vlaue: %d ", INTEGRATION_TEST_GAUGE_ID, gage_val );
											
											// maybe add unt later
											ipc_sz = raspi_gui_server_send_gauge( INTEGRATION_TEST_GAUGE_ID, gage_val, 0 );

											if ( ipc_sz != -1 )
											{
												printf("succesfull server command issued \n" );
											}
											else
											{
												perror( "server send cmd error!\n" );
												keep_going = false;
												break;
											}

										}

									}
								
								}
							//}
							//else
							//{
								//keep_going = false;
								//break;
							//}
						}
					}
                }
                else
                {
                    printf( "server abort!\n" );
                    keep_going = 0;
                }
            }
			else
			{
				printf("server init failed!!\n");
			}
    }
	else
	{
		printf("raspi can driver init failed\n");
	}
    
    printf( "raspi server going down!!!\n" );
	raspi_gui_server_close();
    raspi_can_msg_queue_stop();
			
 }

#define IPC_FRAME_SOF  0xAA
#define IPC_FRAME_SZ   0x05


static void raspi_server_send_test( void )
{
    int sz = 0;
    const char send_buff[ ] =
    {
        IPC_FRAME_SOF, 
        0x01,  // ID
        0x00,  // Data H
        0x05,  // Data L 
        0x01   //
    };

    if( raspi_gui_server_init() == 0 )
    {
        printf( "server successfull initialization\n" ); 
        printf( "server is now listening for client connections\n" );
        printf( "press any key after client is ready\n" );

        (void)getchar();

        while( true )
        {
            //accept one client connection 
            if ( raspi_gui_server_accept( ) == 0 )
            { 
                printf( "incoming client conection\n" );
                sz = raspi_gui_server_send( send_buff, sizeof(send_buff));

                if ( sz == sizeof( send_buff ) )
                {
                    printf("succesfull server data transfer of %d bytes: \n", sz );
                    raspi_gui_server_close();
                    break;
                } 
                else if( ( sz > 0 ) &&  ( sz < sizeof( send_buff ) ) )
                {
                    printf( "server incomplete transmit\n" );
                }
                else if( sz == E_NOCLIENT )
                {
                    printf( "no client connection\n" );
                }

            }
        }
    }
    else
    {
        printf("server init failed!!\n");
        printf( "press any key to continue\n" );
        (void)getchar();
    }
}

#define MAX_RECV_BUFF_SZ  50
static void raspi_client_receive_test( void )
{
    int keep_going = 1;
    int sz = 0;
    char recv_buffer[ MAX_RECV_BUFF_SZ ] = { 0 };

    raspi_gui_client_init();

    printf( "client succesfull initialization\n" );

    while( keep_going )
    { 
        printf( "press any key to try connection once\n" );
        (void)getchar();

        if ( raspi_gui_client_connect( ) == 0 )
        {
            printf( "successfull connection\n" );

            // receive using connection
            while( true )
            {
                if ( (  sz = raspi_gui_client_recv( recv_buffer, MAX_RECV_BUFF_SZ ) ) != -1 )
                {
                    printf( "raspi client succesfull revieve %d bytes\n", sz );
                    raspi_gui_client_close( );
                    keep_going = 0;
                    break;
                }
                else if ( ( sz == -1 ) && (errno == EAGAIN ) )
                {
                    printf( "blocking read avoided... \n" );
                    sleep( 1 );
                    continue;
                }
                else
                {
                    printf( "client read error\n" );
                    keep_going = 0;
                    break;
                }
            }
        }
        else
        {
            printf("connection failed\n");
        }
    }
}



#define RCV_TST_BUFF_SZ 30
static void raspi_can_driver_recv_test( void )
{
    raspi_can_ctx ctx; 
    int rcv_ret=0; 
    int idx = 0;
    int byte_num = 0; 
    int rcv_ok = 0;
    can_msg msg[ RCV_TST_BUFF_SZ ];
    char curByte;
    

    memset( msg, 0x00, sizeof(can_msg) * 3 );

    printf( "receiving from slave address: %d \n", ctx.i2c_slave_addr );
    printf( "Abort process for exit \n" );

    if( raspi_can_init( &ctx ) == RASPI_CAN_OK )
    {
        while( TRUE )
        {
            rcv_ret = raspi_can_poll( &ctx, RCV_TST_BUFF_SZ, msg );

            if( ( rcv_ret != RASPI_CAN_ERROR ) && ( rcv_ret > 0 ) )
            {
                printf( "Sucessfull data receive \n" );

                //for(  idx = 0 ; idx < rcv_ret; idx++ )
                //{
                //    curByte = msg[idx].data[ idx ];  

                //    printf( "byte[%d]: %4x\n", idx, curByte );

                //}

            }
            else if( rcv_ret == RASPI_CAN_ERROR )
            {
                printf( "raspi_can_recv error\n" );
            }

        }
    }

}


static void raspi_can_driver_send_test( void )
{
    //TODO: complete when needed  

}

static void raspi_can_queue_test( void )
{
    int ret_val = 0;
    can_msg msg;
    int keep_going = 1;
    int sz = 0;
    int idx = 0;


    ret_val = raspi_can_msg_queue_init( );

    if ( ret_val ==  RASPI_CAN_OK )
    {

        if( rapspi_can_msg_queue_start( ) == 0 )
        {

            printf( "msg queue sucessfully started\n" );
            printf( "listening incoming can msgs\n" );

            while( keep_going )
            { 
                if( ( sz = raspi_can_msg_queue_size( ) ) > 0 )
                {
                    for( idx = 0 ; idx < sz ; idx++ )
                    {
                        memset( &msg, 0x00, sizeof(can_msg) );
                        raspi_can_msg_dequeue( &msg ); 

                        printf( "msg dequeued\n" );
                        printf( "msg ID %d\n", msg.msgID );
                    }

                }
            }

            raspi_can_msg_queue_stop();

        }
        else
        {
            printf( "raspi_can_msg_queue  error\n" );
        }
    }
}


int fake_read( int fd , char* bytes , int num)
{
    static int curMsgIdx = 0;
    int idx = 0;
    int ret = -1;

    curMsgIdx = ( curMsgIdx > FAKE_MSGS ) ? 0 : curMsgIdx;

    if( num >=  FAKE_READ_DATA_SZ )
    {
        memset( bytes, 0x0, FAKE_READ_DATA_SZ );
        memcpy( bytes, fake_read_mailbox_data[ curMsgIdx ], FAKE_READ_DATA_SZ );
        curMsgIdx++;
        ret = FAKE_READ_DATA_SZ; 
    }
    else
    {
        ret = -1;
    }

    return ret;
}


int fake_write( int fd,  char* bytes, int num )
{
    int wr_bytes = 0;

    wr_bytes = num;

    return wr_bytes;
}

