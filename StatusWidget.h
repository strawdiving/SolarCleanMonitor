#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

/**
 * 主界面上显示的，有唯一id的Robot对应的状态信息的widget
 **/

#include <QWidget>
#include <common/mavlink.h>

namespace Ui {
class StatusWidget;
}

class StatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusWidget(int id, QWidget *parent = 0);
    ~StatusWidget();
    void handleMessage(mavlink_message_t message);

private:
    Ui::StatusWidget *ui;
    //qint16 _id;
};

#endif // STATUSWIDGET_H
