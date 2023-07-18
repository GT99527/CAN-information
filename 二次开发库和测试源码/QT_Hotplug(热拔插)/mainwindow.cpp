#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ucanbus.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <math.h>
#include <qfile.h>
#include <QDir>

#pragma execution_character_set("utf-8");


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cpot = 0;
    connect(this,SIGNAL(sendhotplugs()),this,SLOT(hotplug_func()));//热拔插
}

void MainWindow::hotplug_func(void)
{
    rushcandevices();
}

void MainWindow::rushcandevices(void)
{
    int i,devs;
    QString str;
    devs = CAN_ScanDevice();
    qDebug()<<devs;
    if(devs <= 0)
    {
        ui->canpot->clear();
        QMessageBox::information(this,tr("注意！"),tr("设备被移除！"));
        return;
    }
    else
    {        
        ui->canpot->clear();
        for(i = 0 ; i < devs; i++)
        {
            str.sprintf("%d",i);
            ui->canpot->addItem(str);
        }
        QMessageBox::information(this,tr("注意！"),tr("设备已插入！"));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
