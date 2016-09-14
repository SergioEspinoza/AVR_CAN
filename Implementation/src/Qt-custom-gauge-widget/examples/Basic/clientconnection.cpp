#include <clientconnection.h>
#include <QHostAddress>
#include <stdint.h>

QString ClientConnection::serverName;


ClientConnection::ClientConnection(QObject *parent) :
    QObject(parent)
{

    socket = new QLocalSocket( this );

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    //connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(connected()));

    serverName = SOCKET_NAME_SERVER;
}

void ClientConnection::connectToServer( void )
{

    qDebug() << "Connecting GUI client in 45 secs,..";

    //socket->connectToHost( QHostAddress::LocalHost, port);
    socket->connectToServer( serverName, QIODevice::ReadWrite );

    if( !socket->waitForDisconnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
    }

    qDebug() << "Qt App Gage: Succesfull client GUI connection!!";

}

QLocalSocket::LocalSocketState ClientConnection::state( )
{
    return socket->state();
}

void ClientConnection::connected()
{
    qDebug() << "QT Gage Appication Connected!";
}

void ClientConnection::disconnected()
{
    qDebug() << "QT Gage Application Disconnected!";
}

void ClientConnection::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void ClientConnection::readyRead()
{
    int16_t value = 0;
    int8_t  unit = 0;
    int8_t id = 0;
    QByteArray *data = new QByteArray(  socket->readAll() );
    qDebug() << "Reading...";
    qDebug() << data->data();


    if( data->size() == IPC_SET_GAGE_FRAME_SZ &&
            ( (unsigned char) data->at(0) == IPC_SET_GAGE_SOF ) )
    {

        id = data->at( IPC_ID_IDX );

        value |= data->at( IPC_DATA_IDX_H );
        value <<= 8;
        value &= 0xFF00;
        value |= (int8_t) ( data->at( IPC_DATA_IDX_L) );
        unit = (int8_t) data->at( IPC_UNIT_IDX );

        //TODO: maybe add id if later needed
        qDebug() << "new gage value:";
        qDebug() << value;
        emit ( newData( id, value , unit ) );

    }
    else
    {
        qDebug() << "SOF missing";
    }
}

