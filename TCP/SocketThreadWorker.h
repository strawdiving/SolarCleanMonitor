#ifndef SOCKETTHREADWORKER_H
#define SOCKETTHREADWORKER_H

/**
 * 该类的对象在子线程运行，管理单个的socket通讯。
 **/

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
    /// 对应本地的_errorMsg槽
    void error(QTcpSocket::SocketError socketError);
    /// _receiveMessage()槽中，收到数据后发送
    void socketConnected(int id);
    /// _disconnect()槽中发送
    void socketDisconnect(const int id);
    /// _receiveMessage()槽中转发mavlink消息
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
    /// 定时器定时查询，判断心跳包的间隔，如果超时，socket调用disconnectFromHost，
    /// socket即发送disconnected信号
    quint64 _lastHeartbeat;
    static const unsigned int timeoutIntervalHeartbeat = 6;
    static const unsigned int mavlinkChannel = 1;

    qintptr _socketDescriptor;
    QTcpSocket* _tcpSocket;
    QTimer* _statusTimer;
    int _sysId;
};

#endif // SOCKETTHREADWORKER_H
