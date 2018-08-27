#include "CommunicationServer.h"
#include "QuadApplication.h"
#include "SocketThreadWorker.h"
#include <QThread>
#include <QDebug>

CommunicationServer::CommunicationServer(QObject *parent, int numConnections)
    : QTcpServer(parent)
{
    setMaxPendingConnections(numConnections);
    int i = qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");
    int j = qRegisterMetaType<mavlink_message_t>("mavlink_message_t");
    Q_UNUSED(i);
    Q_UNUSED(j);
}

void CommunicationServer::incomingConnection(qintptr socketDescriptor)
{
    if(_mapId2Worker.size() > maxPendingConnections()) {
        QTcpSocket* socket = new QTcpSocket;
        socket->setSocketDescriptor(socketDescriptor);
        socket->disconnectFromHost();
        return;
    }

    //SocketThread* thread = new SocketThread(socketDescriptor,this);
    QThread* thread = new QThread(this);
    SocketThreadWorker* worker = new SocketThreadWorker(socketDescriptor);
    worker->moveToThread(thread);
    //connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(worker,&SocketThreadWorker::socketConnected,this,&CommunicationServer::_socketConnected);
    connect(worker,&SocketThreadWorker::socketDisconnect,this,&CommunicationServer::_socketDisconnect);
    connect(worker,&SocketThreadWorker::bytesReceived,this,&CommunicationServer::_receiveBytes);
    connect(this,&CommunicationServer::initWorker,worker,&SocketThreadWorker::init);
    connect(thread,&QThread::finished,worker,&SocketThreadWorker::deleteLater);
    thread->start();
    emit initWorker();
    _mapWorker2Thread.insert(worker,thread);
}

void CommunicationServer::_socketConnected(int id)
{    
    SocketThreadWorker* worker = qobject_cast<SocketThreadWorker*>(sender());
    _mapId2Worker.insert(id,worker);
    emit socketConnected(id);
    disconnect(worker,&SocketThreadWorker::socketConnected,this,&CommunicationServer::_socketConnected);
}

void CommunicationServer::_socketDisconnect(const int id)
{
    SocketThreadWorker* worker = qobject_cast<SocketThreadWorker*>(sender());
    foreach (worker, _mapWorker2Thread.keys()) {
        //stop thread
       _mapWorker2Thread.value(worker)->quit();
       _mapWorker2Thread.remove(worker);
    }
    foreach (int sysId, _mapId2Worker.keys()) {
        if(sysId == id) {
            _mapId2Worker.remove(id);
        }
    }
    emit socketDisconnected(id);
}

void CommunicationServer::_receiveBytes(int robertId, mavlink_message_t message)
{
    emit bytesReceived(robertId,message);
}

void CommunicationServer::_sendMessage(int robertId,mavlink_message_t message)
{
    foreach (int id, _mapId2Worker.keys()) {
        if(robertId == id) {
            connect(this,&CommunicationServer::sendMessage,_mapId2Worker.value(id),&SocketThreadWorker::sendMessage);
            emit sendMessage(message);
        }
    }
}
