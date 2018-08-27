#include "RobertWidget.h"
#include "ui_RobertWidget.h"
#include "StatusWidget.h"
#include <QDebug>

RobertWidget::RobertWidget(int robertId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobertWidget),
    _robertId(robertId)
{
    setFixedSize(180,240);
    ui->setupUi(this);
    ui->label_ID->setText(QString::number(robertId));
    this->setStyleSheet("border:1px solid #000000");
}

RobertWidget::~RobertWidget()
{
    delete ui;
}

void RobertWidget::mousePressEvent(QMouseEvent* event)
{
    this->setStyleSheet("border:3px solid #27c927");
    emit selected();
}

void RobertWidget::handleMessage(mavlink_message_t message)
{
    qDebug()<<"RobertWidget::handleMessage";
    switch (message.msgid) {
    case MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS:
    {
        mavlink_solar_clean_status_t status;
        mavlink_msg_solar_clean_status_decode(&message,&status);
        int cleaner_status = status.cleaner_status;
        ui->label_Work_Status->setText(QString::number(cleaner_status));
        switch(cleaner_status) {
        case SOLAR_CLEAN_CLEANER_STOP:
            ui->label_Work_Indicator->setStyleSheet("background-color:red");
            break;
        case SOLAR_CLEAN_CLEANER_RUNNING_FORWARD:
        case SOLAR_CLEAN_CLEANER_RUNNING_REVERSE:
            ui->label_Work_Indicator->setStyleSheet("background-color:#27c927");
            break;
        }
    }
        break;
    default:
        break;
    }
}
