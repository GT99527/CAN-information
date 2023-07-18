#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include <QDate>
#include "ucanbus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class thread_receive : public QThread
{
    Q_OBJECT
public:
     thread_receive();
     ~thread_receive();
     void run(void);
     void stop(void);
     void receivecan(int st);
private:
     int canstate = 0;
     int breakout = 0;
     Can_Msg  rmgs[500];
signals:
     void receivemsg(Can_Msg *msg,int lenth);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update();
    void readcan(Can_Msg *rmgs,int lenth);
    void on_readpar_clicked();
    void on_setpar_clicked();
    void on_opencan_clicked();
    void hotplug_func(void);
    void on_pushButton_clicked();

private:
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
    Ui::MainWindow *ui;
    bool  usbportstate;
    int winitcan();
    void can_func1();
    void can_func2();
    void can_func3();
    void can_func4();
    void rushcandevices(void);
signals:
    void sendhotplugs(void);
};
#endif // MAINWINDOW_H
