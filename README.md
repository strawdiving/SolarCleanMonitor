# SolarCleanMonitor
A demo for multithread monitor of solar-clean robots

[QTCPServer]: http://doc.qt.io/archives/qt-5.8/qtcpserver.html
[多线程Server]: http://doc.qt.io/archives/qt-5.8/qtnetwork-threadedfortuneserver-example.html

需求：

在同一个局域网内，有多台机器人一起工作，和监控站连接同一路由。监控站收到机器人TCP连接请求后，开启一个独立的线程，接收该机器人发送的消息并向机器人发送控制指令。

通讯协议基于Mavlink协议修改，添加所需的消息包。添加的消息包详见 SolarCleanMonitor/libs/mavlink/MAVLink/message_definitions/solar-clean.xml。如何定制消息，详见Mavlink。

socket是一对一的连接，数据都完全独立，不存在数据混在一起发的情况，区分客户端，根据QTcpSocket的peerAddress（）、peerPort（）和peerName（）来辨别不同的client，端口号作为能唯一确定机器人的ID。

思路：采用长连接的方式，即客户端一直与服务器保持连接。每有一个client连接到地面站，在incommingConnection函数中就新建一个socket，启动一个线程，一直监听该socket的消息。

QTcpServer提供基于TCP的服务器。此类可以接受传入的TCP连接，您可以指定端口或让QTcpServer自动选择一个端口。您可以监听特定地址或机器的所有地址。调用QTcpServer的listen()来设置server的IP和port，让服务器侦听传入的连接。调用close（）会使QTcpServer停止侦听传入连接。

```c++
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
  , _tcpServer(NULL)
{
    _tcpServer = new CommunicationServer();
    _tcpServer->listen(QHostAddress::Any,6666);
    ......
}
```

一有新连接可用时，QTcpServer就会调用incommingConnection函数，基本实现是创建QTcpSocket，设置套接字描述符（socket descriptor），然后将QTcpSocket存储在pending connections的内部列表中。最后发出newConnection（）信号。

connect(server,SLOT(newConnection),server,SLOT(slotFunc))，在server的响应槽里，调用server的nexePendingConnection()接受connection，并用返回的QTcpSocket对象和client通信。

注：返回的QTcpSocket对象不能在别的thread中使用。如果想在其他thread使用，要重载incommingConnection函数。要记录哪个用户连接或者要进行相应处理，就需要重写该函数。一般会新建一个QTcpServer的派生类。

参考

[Threaded Fortune Server]: http://doc.qt.io/archives/qt-5.8/qtnetwork-threadedfortuneserver-example.html	"Threaded Fortune Server"

的例子，我们将实现一个QTcpServer的子类，它在另一个线程中启动每个socket连接。

首先，我们将实现一个QTcpServer的子类QCommunicationServer，

```c++
class CommunicationServer : public QTcpServer
{
    Q_OBJECT
public:
    CommunicationServer(QObject *parent = 0,int numConnections=10);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void initWorker(void);
};
```

CommunicationServer继承自QTcpServer，并且重新实现了QTcpServer::incomingConnection()。

在CommunicationServer的构造函数中，可以用setMaxPendingConnections()设置最大连接数。

```c++
void CommunicationServer::incomingConnection(qintptr socketDescriptor)
{
    if(_mapId2Worker.size() > maxPendingConnections()) {
        QTcpSocket* socket = new QTcpSocket;
        socket->setSocketDescriptor(socketDescriptor);
        socket->disconnectFromHost();
        return;
    }

    // 新建一个子线程
    QThread* thread = new QThread(this);
    // 新建一个线程处理对象
    SocketThreadWorker* worker = new SocketThreadWorker(socketDescriptor);
    // 该对象的运行在子线程中
    worker->moveToThread(thread);
 
 connect(this,&CommunicationServer::initWorker,worker,&SocketThreadWorker::init);
 // 确保线程一旦完成就被删除
 connect(thread,&QThread::finished,worker,&SocketThreadWorker::deleteLater);
 
 // 启动线程
 thread->start();
   
 emit initWorker();
}
```

在我们的QTcpServer：incommingConnection()的实现中，当不超过最大连接数时，每当有新连接时（新收到一个connection），就新建一个子线程，新建一个线程处理对象，将该对象moveToThread到该线程中，则该对象将运行在子线程中。

注：在用moveToThread时，无需重写run(）函数，继承自object的类都运行在子线程中。

通过将thread的finished（）信号连接到QObject :: deleteLater（），我们确保线程一旦完成就被删除。然后我们可以调用QThread :: start（）来启动线程。

新建的线程处理类：SocketThreadWorker。

```c++
SocketThreadWorker::SocketThreadWorker(qintptr socketDescriptor,QObject *parent)
    : QObject(parent),
    _socketDescriptor(socketDescriptor)
{

}

void SocketThreadWorker::init()
{
  // 创建QTcpSocket对象
    _tcpSocket = new QTcpSocket;

    if (!_tcpSocket->setSocketDescriptor(_socketDescriptor)) {
        emit error(_tcpSocket->error());
        return;
    }
    connect(_tcpSocket,&QTcpSocket::readyRead,this,&SocketThreadWorker::_receiveMessage,Qt::DirectConnection);//in the same thread
    connect(_tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(_errorMsg(QAbstractSocket::SocketError)));
    connect(_tcpSocket,&QTcpSocket::disconnected,this,&SocketThreadWorker::_disconnect,Qt::DirectConnection);
}
```

首先要做的是创建QTcpSocket对象，值得注意的是，我们在子线程中创建了这个对象，它自动将socket与子线程的事件循环相关联。

通过调用QTcpSocket :: setSocketDescriptor（）初始化socket，将我们的_socketDescriptor作为setSocketDescriptor（）的参数传递。

2、知识点：

socket的disconnectFromHost试图关闭socket，关闭后发射disconnected信号，调用槽deletelater()，删除disconnected信号的发送者sender()

当client调用connectToHost()，试图连接（HostName：port），成功建立一个connection后发射connected信号。