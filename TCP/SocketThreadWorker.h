#ifndef SOCKETTHREADWORKER_H
#define SOCKETTHREADWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <common/mavlink.h>
#include <QTimer>

class SocketThreadWorker : public QObject
{
    Q_OBJECT
public:
    explicit SocketThreadWorker(qintptr socketDescriptor,QObject *parent = 0);
    int id() {return _sysId;}
    qint64 lastHeartbeat() {return _lastHeartbeat;}

signals:
    void error(QTcpSocket::SocketError socketError);
    void socketConnected(int id);
    void socketDisconnect(const int id);
    void bytesReceived(int robertId, mavlink_message_t message);

private slots:
    void _receiveMessage();
    void _disconnect();
    void _errorMsg(QAbstractSocket::SocketError socketError);
    void _statusUpdate(void);

public slots:
    void init();
    void sendMessage(mavlink_message_t message);

private:
    quint64 _lastHeartbeat;
    static const unsigned int timeoutIntervalHeartbeat = 6;
    static const unsigned int mavlinkChannel = 1;

    qintptr _socketDescriptor;
    QTcpSocket* _tcpSocket;
    QTimer* _statusTimer;
    int _sysId;
};

#endif // SOCKETTHREADWORKER_H
