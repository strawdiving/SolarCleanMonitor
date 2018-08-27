#include "SocketThreadWorker.h"
#include <QDateTime>
#include <QDebug>
#include <QHostAddress>

SocketThreadWorker::SocketThreadWorker(qintptr socketDescriptor,QObject *parent)
    : QObject(parent),
    _socketDescriptor(socketDescriptor),
    _lastHeartbeat(0),
    _sysId(0)
{

}

void SocketThreadWorker::init()
{
    _statusTimer = new QTimer;
    connect(_statusTimer,&QTimer::timeout,this,&SocketThreadWorker::_statusUpdate);

    _tcpSocket = new QTcpSocket;
//! [1] //! [2]
    if (!_tcpSocket->setSocketDescriptor(_socketDescriptor)) {
        emit error(_tcpSocket->error());
        return;
    }

    connect(_tcpSocket,&QTcpSocket::readyRead,this,&SocketThreadWorker::_receiveMessage,Qt::DirectConnection);//in the same thread
    connect(_tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(_errorMsg(QAbstractSocket::SocketError)));
    connect(_tcpSocket,&QTcpSocket::disconnected,this,&SocketThreadWorker::_disconnect,Qt::DirectConnection);

    qDebug() << "run" << _tcpSocket->peerAddress().toString()<<_tcpSocket->peerPort();

    //_statusTimer->start(500);
}

void SocketThreadWorker::_statusUpdate(void)
{
    quint64 curTime = static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());
    qint64 intervel =  (curTime - _lastHeartbeat)/1000.0;
    if(intervel >= timeoutIntervalHeartbeat) {
        qDebug()<<"heartbeat exceed 6 seconds, disconnect";
        //socket disconnect, thread exit;
        _tcpSocket->disconnectFromHost();
    }
}

void SocketThreadWorker::_receiveMessage()
{
    qint64 blockSize = _tcpSocket->bytesAvailable();
    if(blockSize) {
        QByteArray block;

        block = _tcpSocket->readAll();
        //_tcpSocket->write(block);
        qDebug()<<QString(block.toHex());

        emit socketConnected(_sysId);

        mavlink_message_t message;
        mavlink_status_t status;

        static int nonmavlinkCount = 0;
        static bool decodedFirstPacket = false;

        for (int position = 0; position < block.size(); position++) {
            unsigned int decodeState = mavlink_parse_char(mavlinkChannel, (uint8_t)(block[position]), &message, &status);
            if (decodeState == 0 && !decodedFirstPacket)
            {
                if (nonmavlinkCount > 500)
                {
                   qDebug()<<"500 bytes with no mavlink message. Are we connected to a mavlink capable device?";
                }
            }
            if (decodeState == 1)
            {
               decodedFirstPacket = true;
               qDebug()<< message.msgid;
                _sysId = message.sysid;
               //emit socketConnected(_sysId);

                switch (message.msgid)
                {
                    //#0
                    case MAVLINK_MSG_ID_HEARTBEAT:
                    {
                        _lastHeartbeat =static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());

                        //qDebug()<<"first time: "<<lastHeartbeat;
                        mavlink_heartbeat_t heartbeat;
                        mavlink_msg_heartbeat_decode(&message, &heartbeat);
                        //qDebug()<<heartbeat.autopilot<<heartbeat.base_mode<<heartbeat.custom_mode;

                        //emit socketConnected(_sysId,this);
                    }
                    break;

                case MAVLINK_MSG_ID_SYS_STATUS:
                {
                    //_lastHeartbeat =static_cast<quint64>(QDateTime::currentMSecsSinceEpoch());

                    //qDebug()<<"first time: "<<lastHeartbeat;
                    mavlink_sys_status_t heartbeat;
                    mavlink_msg_sys_status_decode(&message, &heartbeat);
                    qDebug()<<"battery"<<heartbeat.battery_remaining;

                    //emit socketConnected(_sysId,this);
                }
                break;

                    default:
                        break;
                }
                emit bytesReceived(_sysId,message);
            }
        }
    }
}

void SocketThreadWorker::sendMessage(mavlink_message_t message)
{
    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    // Rewriting header to ensure correct link ID is set
    static uint8_t messageKeys[256] = MAVLINK_MESSAGE_CRCS;
    mavlink_finalize_message_chan(&message, _sysId, 0, mavlinkChannel,message.len, message.len, messageKeys[message.msgid]);
    // Write message into buffer, prepending start sign
    int len = mavlink_msg_to_send_buffer(buffer, &message);

   _tcpSocket->write((const char*)buffer, len);
}

void SocketThreadWorker::_disconnect()
{
    qDebug()<<"disconnected";
    emit socketDisconnect(_sysId);
    _tcpSocket->deleteLater();
    //_statusTimer->stop();
}

 void SocketThreadWorker::_errorMsg(QAbstractSocket:: SocketError socketError)
 {
     qDebug()<<"error: "<<socketError;
 }
