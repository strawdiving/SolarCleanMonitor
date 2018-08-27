#ifndef ROBERTWIDGET_H
#define ROBERTWIDGET_H

#include <QWidget>
#include <common/mavlink.h>

class StatusWidget;
class RobertWidget;

namespace Ui {
class RobertWidget;
}

class RobertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RobertWidget(int robertId, QWidget *parent = 0);
    ~RobertWidget();

    int id(void) { return _robertId;}
    void handleMessage(mavlink_message_t message);

signals:
    void selected(void);

public slots:    

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int                     _robertId;
    Ui::RobertWidget *ui;
};

#endif ROBERTWIDGET_H
