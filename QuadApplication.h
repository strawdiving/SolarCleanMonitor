#ifndef QUADAPPLICATION_H
#define QUADAPPLICATION_H

#include <QApplication>
#include "mainwindow.h"
//class MainWindow;

class QuadApplication : public QApplication
{

public:
    QuadApplication(int &argc, char* argv[]);
    ~QuadApplication();

    static QuadApplication* _app;
    bool _initForNormalAppBoot(void);

private:
    MainWindow* _mainwindow;
};

#endif // QUADAPPLICATION_H
