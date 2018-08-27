#include "StatusWidget.h"
#include "ui_StatusWidget.h"
#include <QDebug>

StatusWidget::StatusWidget(int id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusWidget)
{
    ui->setupUi(this);
    ui->label_RobertId->setText(QString::number(id));
}

StatusWidget::~StatusWidget()
{
    delete ui;
}

void StatusWidget::handleMessage(mavlink_message_t message)
{
     qDebug()<<"StatusWidget::handleMessage";
    switch (message.msgid) {
    case MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS:
    {
        mavlink_solar_clean_status_t status;
        mavlink_msg_solar_clean_status_decode(&message,&status);
        int cleaner_status = status.cleaner_status;
        ui->label_Work_Status->setText(QString::number(cleaner_status));
        ui->label_speed->setText(QString::number(status.move_speed));
        ui->label_Distance->setText(QString::number(status.position));
        ui->label_Time->setText(QString::number(status.running_time));
        ui->label_Battery->setText(QString::number(status.battery_remaining));
    }
        break;

    case MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE:
    {
        mavlink_solar_clean_temperature_t temp;
        mavlink_msg_solar_clean_temperature_decode(&message,&temp);
        ui->label_Battery_Temp->setText(QString::number(temp.temperature_enabled));
    }
        break;

    default:
        break;
    }
}
