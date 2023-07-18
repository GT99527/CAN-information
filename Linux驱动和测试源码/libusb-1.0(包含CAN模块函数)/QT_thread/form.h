#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QThread>
#include <QDate>
#include "canbus.h"


class thread_receive : public QThread
{
    Q_OBJECT
public:
     thread_receive();
     ~thread_receive();
     void run(void);
     void stop(void);
     void receivecan(int st);
     int dev;
     int cpot;
private:
     int canstate = 0;
     int breakout = 0;
     Can_Msg  rmgs[500];
signals:
     void receivemsg(Can_Msg *msg,int lenth);
};


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    int dev;
    int cpot;
    int winitcan();
private slots:
    void on_opencan_clicked();
    void on_pushButton_clicked();
    void on_sendcan_clicked();
    void update();
    void readcan(Can_Msg *rmgs,int lenth);
private:
    Ui::Form *ui;
    int canport;
    int devices;
    QDate lastday;
    int baudrate;
    int tcounter;
    int f1,f2,f3,f4;
    QTimer *timer;
    thread_receive *threc;
    int rxlenth = 0;
    Can_Msg  tmsg[100];
    bool  usbportstate;
    void rushcandevices(void);
    char finddata (int idx,QString str);
    int str2u8(char* data, QString str);
    QString u8ary2str(char data[],char lenth);
    int findhex_formstr (int *idx,int pos, QString str);
};

#endif // FORM_H
