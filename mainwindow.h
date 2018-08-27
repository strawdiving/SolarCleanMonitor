#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define M_PI (3.14159265358979323846)

#include <QMainWindow>
#include<QTimer>
#include <QElapsedTimer>
#include <QGridLayout>
#include "TCP/CommunicationServer.h"
#include "RobertWidget.h"
#include "StatusWidget.h"

#include <common/mavlink.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow*  _create();
    ~MainWindow();

    MainWindow* instance(void);
    void closeEvent(QCloseEvent* event);

signals:
    void sendMessage(int robertId,mavlink_message_t message);

private slots:
    void _robertSelected();


public slots:
    void _linkConnected(int robertId);
    void _linkDisconnected(int robertId);
    void _receiveBytes(int robertId, mavlink_message_t message);

protected:


private:
    CommunicationServer* _tcpServer;
    RobertWidget* _currentRobert;

    Ui::MainWindow *ui;    
    QGridLayout* layout;
    StatusWidget* _nullWgt;

    QMap<RobertWidget*,StatusWidget*> _mapRobert2Status;
};

#endif // MAINWINDOW_H
