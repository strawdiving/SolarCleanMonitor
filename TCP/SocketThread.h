#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <common/mavlink.h>
#include <QTimer>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(int socketDescriptor, QObject *parent);
    void run() override;
    int id() {return _sysId;}
    qint64 lastHeartbeat() {return _lastHeartbeat;}


signals:
    void error(QTcpSocket::SocketError socketError);
    void socketConnected(int id);
    void socketDisconnect(const int id, QTcpSocket* socket);
    void bytesReceived(int robertId, mavlink_message_t message);

private slots:
    void _receiveMessage();
    void _disconnect();
    void _errorMsg(QAbstractSocket::SocketError socketError);
    void _statusUpdate(void);

public slots:
    void _sendMessage(mavlink_message_t message);

private:
    quint64 _lastHeartbeat;
    static const unsigned int timeoutIntervalHeartbeat = 6;
    static const unsigned int mavlinkChannel = 1;

    int _socketDescriptor;
    QTcpSocket* _tcpSocket;
    QTimer* _statusTimer;
    int _sysId;
};

#endif // SOCKETTHREAD_H
