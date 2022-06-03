//
// Created by Iurii on 03.06.2022.
//

#ifndef TASK_37_4_3_TV_REMOTE_CONTROLLER_REMOTE_CONTROLLER_H
#define TASK_37_4_3_TV_REMOTE_CONTROLLER_REMOTE_CONTROLLER_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QProgressBar>

class remote_controller : public QMainWindow {
    Q_OBJECT

public:
    remote_controller(QWidget* parent = nullptr): QMainWindow(parent) {}
    QLCDNumber* lcdNumber = nullptr;
    QProgressBar* progressBar = nullptr;

public slots:
    void ch1(){lcdNumber->display(lcdNumber->value() * 0 + 1);};
    void ch2(){lcdNumber->display(lcdNumber->value() * 0 + 2);};
    void ch3(){lcdNumber->display(lcdNumber->value() * 0 + 3);};
    void ch4(){lcdNumber->display(lcdNumber->value() * 0 + 4);};
    void ch5(){lcdNumber->display(lcdNumber->value() * 0 + 5);};
    void ch6(){lcdNumber->display(lcdNumber->value() * 0 + 6);};
    void ch7(){lcdNumber->display(lcdNumber->value() * 0 + 7);};
    void ch8(){lcdNumber->display(lcdNumber->value() * 0 + 8);};
    void ch9(){lcdNumber->display(lcdNumber->value() * 0 + 9);};
    void ch0(){lcdNumber->display(lcdNumber->value() * 0);};
    void chUp(){
        if (lcdNumber->value() < 9)
            lcdNumber->display(lcdNumber->value() + 1);};
    void chDown(){
        if (lcdNumber->value() > 0)
            lcdNumber->display(lcdNumber->value() - 1);};
    void volumeUp(){progressBar->setValue(progressBar->value() + 10);};
    void volumeDown(){progressBar->setValue(progressBar->value() - 10);};
};

#endif //TASK_37_4_3_TV_REMOTE_CONTROLLER_REMOTE_CONTROLLER_H
