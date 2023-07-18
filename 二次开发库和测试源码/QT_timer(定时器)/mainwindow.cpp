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
    QString str;
    usbportstate = false;

    rushcandevices();

    timer = new QTimer(this);
    rxtimer = new QTimer(this);
    on_pushButton_clicked();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(rxtimer, SIGNAL(timeout()), this, SLOT(readcan()));
    connect(this,SIGNAL(sendhotplugs()),this,SLOT(hotplug_func()));
}

void MainWindow::hotplug_func(void)
{
    rushcandevices();
}

void MainWindow::rushcandevices(void)
{
    int i,devs;
    QString str,str2;
    devs = CAN_ScanDevice();

    if(usbportstate)
    {
        if(cpot > devs)
        {
            on_opencan_clicked();
            usbportstate = false;
            ui->canpot->clear();
            QMessageBox::information(this,tr("注意！"),tr("设备被移除！"));
            return;
        }
    }
    if(devs > 0)
    {
        str2 = "";
        for(i = devices ; i < devs; i++)
        {
            str.sprintf("%d",i);
            str2 += " "+str;
        }
    //    if(str2 != "") {statbar1->setText(tr("已连接通道:")+str2);}
        if(devs!= devices)
        {
            devices = devs;
            ui->canpot->clear();
            for(i = 0 ; i < devices; i++)
            {
                str.sprintf("%d",i);
                ui->canpot->addItem(str);
            }
            if((usbportstate == false)&&(devices > 0)&&(canport < ui->canpot->count()))
            {
                ui->canpot->setCurrentIndex(canport);
            }
        }
    }
    else
    {
        devices = 0;
        ui->canpot->clear();
      //  statbar1->setText(tr("未连接设备"));
    }
}

void MainWindow::can_func1()
{
    int ret;
    tmsg[0].ID = 0x211;
    if(++f1 > 360) f1 = 0;
    tmsg[0].ExternFlag = 1;
    tmsg[0].DataLen = 8;
    *(short*)(&tmsg[0].Data[0]) = f1;
    *(short*)(&tmsg[0].Data[2]) = sin((f1*3.1415)/180)*100;
}

void MainWindow::can_func2()
{
    int ret;
    tmsg[1].ExternFlag = 1;
    tmsg[1].DataLen = 8;
    tmsg[1].ID = 0x221;
    if(++f2 > 360) f2 = 0;
    *(short*)(&tmsg[1].Data[0]) = f2;
    *(short*)(&tmsg[1].Data[2]) = cos((f2*3.1415)/180)*100;
}

void MainWindow::can_func3()
{
    int a = rand() % 51 + 103;
    int ret;
    tmsg[2].ID = 0x201;
    tmsg[2].ExternFlag = 1;
    tmsg[2].DataLen = 8;
    *(short*)(&tmsg[2].Data[2]) = a+f3;
}

void MainWindow::can_func4()
{
    int a = rand() % 251 + 1030;
    static bool status = false;
    int ret;
    f3 = rand() % 251 + 1030;
    tmsg[3].ID = 0x231;
    if(status)
    {
        if(++f4 >= 80){status = false;}
    }
    else
    {
        if(--f4 <= -20){status = true;}
    }
    tmsg[3].DataLen = 8;
    tmsg[3].ExternFlag = 0;
    *(int*)(&tmsg[3].Data[0]) = f4;
}

void MainWindow::update()
{
    tcounter++;
    if(1)                 can_func1();
    if(tcounter%5  == 0)  can_func2();
    if(tcounter%10 == 0)  can_func3();
    if(tcounter%6 == 0)   can_func4();
    CAN_Transmit(cpot,tmsg,4,200);
}

QString u8ary2str(char data[],char lenth)
{
    char i;
    QString str,str2;
    if(lenth > 8) return "";
    for(i = 0;i < lenth;i++)
    {
        str2.sprintf(" %02x",data[i]);
        str += str2;
    }
    return str;
}

void MainWindow::readcan()
{
    int i,lenth;
    QString str;
    int tmplenth = rxlenth;
    lenth = CAN_Receive(cpot,rmgs,500,10);
    if(lenth <= 0) return;
    rxlenth += lenth;
    ui->tableWidget->setRowCount(rxlenth);
  //  qDebug()<<rxlenth;
    for(i = 0 ; i < lenth; i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem;
        if(rmgs[i].ExternFlag == 1) {str = "扩展帧";}
        else                        {str = "标准帧";}
        item1->setText(str);
        ui->tableWidget->setItem(tmplenth+i,0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(str.sprintf("%X",rmgs[i].ID));
        ui->tableWidget->setItem(tmplenth+i,1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setText(str.sprintf("%X",rmgs[i].DataLen));
        ui->tableWidget->setItem(tmplenth+i,2, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem;
        str = u8ary2str(rmgs[i].Data,rmgs[i].DataLen);
        item4->setText(str);
        ui->tableWidget->setItem(tmplenth+i,3, item4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::winitcan()
{
    int rtn;
    int tmp;
    double tm1,tm2;
    QString str;
    Can_Config cancfg;
    cancfg.model = ui->wkmode->currentIndex();
    str = ui->baudrate->currentText();
    tm1 = str.toDouble();
    baudrate = tm1;
    tmp =tm1 *1000;
    cancfg.configs = 0;
    if(ui->inres->isChecked())         cancfg.configs |= 0x0001;  //接通内部匹配电阻
    if(ui->awum->isChecked())          cancfg.configs |= 0x0002;  //开启离线唤醒模式
    if(ui->nart->isChecked())          cancfg.configs |= 0x0004;  //开启自动重传
    cancfg.baudrate = tmp;

    rtn = CAN_Init(cpot,&cancfg);
    tm2 = cancfg.baudrate/1000.0;
    return  rtn;
}

void MainWindow::on_readpar_clicked()
{
    if(!usbportstate)
    {
        QMessageBox::information(this,tr("错误"),tr("请打开CAN设备！"));
        return;
    }
    qDebug()<<"ResetCAN"<< CAN_Reset(cpot);
}

void MainWindow::on_setpar_clicked()
{
    if(!usbportstate)
    {
        QMessageBox::information(this,tr("错误"),tr("请打开CAN设备！"));
        return;
    }
    qDebug()<<winitcan();

}

void MainWindow::on_opencan_clicked()
{
    int ret;
    if(usbportstate)
    {
        qDebug()<<"CloseDevice";
        ui->opencan->setText(tr("打开"));
        usbportstate = false;
        ret = CAN_CloseDevice(cpot);
        qDebug()<<"CloseDevice"<<ret;
        timer->stop();
    }
    else
    {
        qDebug()<<"ScanDevice";
        qDebug()<<CAN_ScanDevice();
        if(ui->canpot->count() == 0)
           {QMessageBox::information(this,tr("错误！"),tr("没有找到CAN设备！")); return;}
        cpot = ui->canpot->currentIndex();
        ret = CAN_OpenDevice(cpot);
        qDebug()<<"opencan "<< ret;
        if(ret != 0)
           {QMessageBox::information(this,tr("错误！"),tr("打开CAN设备失败！")); return;}
        qDebug()<<"winitcan"<<winitcan();
        ui->opencan->setText(tr("关闭"));
        usbportstate = true;
        tcounter = 0;
        f1=f2=f3=f4=0;
        timer->start(10);
        rxtimer->start(20);
    }
}


void MainWindow::on_pushButton_clicked()
{
    QStringList leadlist;
    leadlist     <<  tr("帧类型")
                 <<  tr("帧ID")
                 <<  tr("数据长度")
                 <<  tr("帧数据");
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(leadlist);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0,65);
    ui->tableWidget->setColumnWidth(1,65);
    ui->tableWidget->setColumnWidth(2,65);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    rxlenth = 0;
    ui->tableWidget->setRowCount(rxlenth);
}
