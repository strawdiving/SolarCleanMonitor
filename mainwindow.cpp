#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QtCore>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLayout>
#include <QFile>

#include "QuadApplication.h"

static MainWindow* _instance = NULL;

MainWindow* MainWindow::_create()
{
    Q_ASSERT(_instance == NULL);
    _instance = new MainWindow();
    Q_ASSERT(_instance);
    return _instance;
}

/*
 *  启动TCP Server侦听，连接server和主界面的信号与槽
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , _tcpServer(NULL)
  , _currentRobert(NULL)
{
    ui->setupUi(this);
    //setFixedSize(1200,700);
    this->setStyleSheet("QPushButton {background: #cfe2f3}"
                        "QPushButton:pressed {background: 6699cc}");

    ui->label->setStyleSheet("border:2px solid blue;background-color:#d9d9d9");
    ui->label_2->setStyleSheet("border:2px solid blue;background-color:#d9d9d9");
    ui->label_3->setStyleSheet("border:2px solid blue;background-color:#d9d9d9");

    layout = new QGridLayout;
    layout->setSpacing(0);

    _nullWgt = new StatusWidget(0,this);
    ui->stackedWidget_Status->addWidget(_nullWgt);

    _tcpServer = new CommunicationServer();
    _tcpServer->listen(QHostAddress::Any,6666);
    connect(_tcpServer,&CommunicationServer::socketConnected,this,&MainWindow::_linkConnected);
    connect(_tcpServer,&CommunicationServer::socketDisconnected,this,&MainWindow::_linkDisconnected);
    connect(_tcpServer,&CommunicationServer::bytesReceived,this,&MainWindow::_receiveBytes);
    connect(this,&MainWindow::sendMessage,_tcpServer,&CommunicationServer::_sendMessage);
    show();
}

/*
 * 新建对应的RobertWidget和StatusWidget对象，在界面上显示已连接的robert，设置statusWidget为新连接的robert对应的状态信息
 * */
void MainWindow::_linkConnected(int robertId)
{
    RobertWidget* robert = new RobertWidget(robertId);
    StatusWidget* statusWidget = new StatusWidget(robertId);
        _mapRobert2Status.insert(robert,statusWidget);

    int j = 0;
    for(int i=0;i<_mapRobert2Status.count();i++) {
        if(i!=0 && i%4 == 0){
            j++;
        }
        layout->addWidget(robert,j,i%4,1,1);
    }
    ui->widget_Roberts->setLayout(layout);

    ui->stackedWidget_Status->addWidget(statusWidget);
    ui->stackedWidget_Status->setCurrentWidget(statusWidget);

    //qDebug()<<"count: robert statusWidget "<<_roberts.count()<<_statusWidgets.count();

    connect(robert,&RobertWidget::selected,this,&MainWindow::_robertSelected);
}

/*
 *  根据Id判断哪个robert的连接断开，在界面上移除，改变当前的statusWidget
 * */
void MainWindow::_linkDisconnected( int robertId)
{
    qDebug()<<"MainWindow::_linkDisconnected"<<robertId;
    RobertWidget* deletRobert = NULL;
    foreach (RobertWidget* robert, _mapRobert2Status.keys()) {
        if(robertId == robert->id()) {
            deletRobert = robert;
        }
    }
    if(deletRobert) {
        deletRobert->setParent(NULL);
        layout->removeWidget(deletRobert);

        ui->stackedWidget_Status->removeWidget(_mapRobert2Status.value(deletRobert));

        _mapRobert2Status.remove(deletRobert);
        if(deletRobert == _currentRobert) {
            if(!_mapRobert2Status.isEmpty()) {
                ui->stackedWidget_Status->setCurrentWidget(_mapRobert2Status.last());
            }
            else {
                ui->stackedWidget_Status->setCurrentWidget(_nullWgt);
            }
            qDebug()<<"map count "<<_mapRobert2Status.count();
        }
    }
}

/*
 * 点击robert后的响应槽，当前选中robert变换样式，且显示对应的statusWidget；
   发送solar_clean_control消息包
 */
void MainWindow::_robertSelected()
{
   RobertWidget* robert = qobject_cast<RobertWidget*>(sender());

   if(robert) {
       if(_currentRobert) {
           if(_currentRobert!=robert) {
               _currentRobert->setStyleSheet("border:1px solid #000000");
               _currentRobert = robert;
           }
       }
       else {
           _currentRobert = robert;
       }
       ui->stackedWidget_Status->setCurrentWidget(_mapRobert2Status.value(_currentRobert));

       mavlink_message_t message;
       mavlink_solar_clean_control_t command;
       command.cleaner_control = 1;
       command.move_speed_control = 5;
       command.move_mode_control = SOLAR_CLEAN_CLEANER_RUNNING_FORWARD;
       mavlink_msg_solar_clean_control_encode(robert->id(),0,&message,&command);
       emit sendMessage(robert->id(),message);
   }
}

/*
 * 根据Id判断信号的发送者，让对应的robertWidget和statusWidget来处理消息
 * */
void MainWindow::_receiveBytes(int robertId, mavlink_message_t message)
{
    foreach (RobertWidget* robert, _mapRobert2Status.keys()) {
        if(robertId == robert->id()) {
            robert->handleMessage(message);
            _mapRobert2Status.value(robert)->handleMessage(message);
        }
    }
}

 MainWindow* MainWindow::instance(void)
 {
     return _instance;
 }

void MainWindow::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event)
}

MainWindow::~MainWindow()
{
    _instance = NULL;
    delete ui;
    _mapRobert2Status.clear();
}
