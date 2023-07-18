#include "form.h"
#include "ui_form.h"
#include "canbus.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <math.h>
#include <qfile.h>
#include <QDir>

#pragma execution_character_set("utf-8");

thread_receive::thread_receive()
{

}

thread_receive::~thread_receive()
{

}


void thread_receive::stop(void)
{
    breakout = 0;
}

void thread_receive::receivecan(int stat)
{
    canstate = stat;
}

void thread_receive::run()
{
    int lenth;
    breakout = 1;
    while(breakout)
    {
        if(canstate == 0) {msleep(100);continue;}
        lenth = CAN_Receive(dev,cpot,rmgs,100,100);
        if(lenth <= 0) continue;
        emit receivemsg(rmgs,lenth);
    }
}


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
   // cpot = 0;
    usbportstate = false;
    qRegisterMetaType<Can_Msg>("Can_Msg");
  //  rushcandevices();

    timer = new QTimer(this);
    on_pushButton_clicked();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    threc = new thread_receive;
    connect(threc, SIGNAL(receivemsg(Can_Msg*,int)), this, SLOT(readcan(Can_Msg*,int)));
    on_pushButton_clicked();
}

Form::~Form()
{
    delete ui;
    qDebug()<<"exit";
    if(usbportstate)
    {
        qDebug()<<"CloseDevice";
        ui->opencan->setText(tr("打开"));
        usbportstate = false;
        CAN_CloseDevice(dev,cpot);
        threc->receivecan(0);
    }
}


void Form::on_opencan_clicked()
{
    int ret;
    if(usbportstate)
    {
        ui->opencan->setText(tr("打开"));
        usbportstate = false;
        ret = CAN_CloseDevice(dev,cpot);
        qDebug()<<"CloseDevice"<<ret;
        timer->stop();
        threc->receivecan(0);
    }
    else
    {
//        qDebug()<<"ScanDevice";
        qDebug()<<"CAN_OpenDevice"<<dev<<cpot;

        ret = CAN_OpenDevice(dev,cpot);
        threc->dev = dev;
        threc->cpot = cpot;
        qDebug()<<"opencan "<< ret;
        if(ret != 0)  {QMessageBox::information(this,tr("错误！"),tr("打开CAN设备失败！")); return;}
        qDebug()<<"winitcan"<<winitcan();
        CAN_SetFilter(dev,cpot,0,0,0,0,1);
        ui->opencan->setText(tr("关闭"));
        usbportstate = true;
        tcounter = 0;
        f1=f2=f3=f4=0;
        timer->start(10);
        threc->receivecan(1);
        threc->start();
    }
}

int Form::winitcan()
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
    cancfg.baudrate = tmp;
    cancfg.configs |= 0x0001;  //接通内部匹配电阻
    cancfg.configs |= 0x0002;  //开启离线唤醒模式
    cancfg.configs |= 0x0004;  //开启自动重传
    rtn = CAN_Init(dev,cpot,&cancfg);
    tm2 = cancfg.baudrate/1000.0;
    return  rtn;
}

void Form::update()
{
    tcounter++;
  //  CAN_Transmit(dev,cpot,tmsg,4);
}


char Form::finddata (int idx,QString str)
{
    char dain;
    int ret = str.toLocal8Bit().count();
    while(idx < ret)
    {
        dain = str.at(idx).toLatin1();
        if     ((dain >= '0')&&(dain <= '9'))   { return 0; }
        else if((dain >= 'a')&&(dain <= 'f'))   { return 0; }
        else if((dain >= 'A')&&(dain <= 'F'))   { return 0; }
        else (idx)++;
    }
    return 1;
}

int Form::findhex_formstr (int *idx,int pos, QString str)
{
    char dain;
    int ret = str.toLocal8Bit().count();
    while(*idx < ret)
    {
        dain = str.at(*idx).toLatin1();
        if     ((dain >= '0')&&(dain <= '9'))   { return(dain - '0') ; }
        else if((dain >= 'a')&&(dain <= 'f'))   { return(dain + 10 - 'a') ; }
        else if((dain >= 'A')&&(dain <= 'F'))   { return(dain + 10 - 'A') ; }
        else if(pos == 1)                       { return 0xff; }
        else (*idx)++;
    }
    return 0xff;
}


int Form::str2u8(char* data, QString str)
{
    int ret;
    int da,db;
    int i = 0;
    int lenth;
    QByteArray buf;
    ret = str.toLocal8Bit().count();
    while(i < ret)
    {
        da = findhex_formstr(&i,0,str);
        if(da == 0xff)
        {
            if(finddata(i,str) == 1){ break;}
            else                    {da = 0;}
        }
        i++;
        if(str.at(i) == " ") { buf.append(da); i++;  continue; }
        db = findhex_formstr(&i,1,str);
        if(db == 0xff) buf.append(da);
        else buf.append((da<<4)|db);
        i++;
        if(buf.size() >= 8) break;
    }
    lenth = buf.size();
    memcpy(data,buf.data(),lenth);
    return lenth;
}


QString Form::u8ary2str(char data[],char lenth)
{
    char i;
    QString str,str2;
    if(lenth > 8) return "";
    for(i = 0;i < lenth;i++)
    {
        str2.sprintf(" %02x",(unsigned char)data[i]);
        str += str2;
    }
    return str;
}

void Form::readcan(Can_Msg *rmgs,int lenth)
{
    int i;
    QString str;
    int tmplenth = rxlenth;
    if(lenth <= 0) return;
    rxlenth += lenth;
    ui->tableWidget->setRowCount(rxlenth);
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
    ui->tableWidget->scrollToBottom();
}


void Form::on_pushButton_clicked()
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

void Form::on_sendcan_clicked()
{
    QString str;
    int lenth = 0;
    memset(tmsg,0,sizeof(tmsg));
    if(ui->cantype1->currentIndex() == 1) {tmsg[0].ExternFlag = 1;}
    if(ui->cantype2->currentIndex() == 1) {tmsg[0].RemoteFlag = 1;}
    str = ui->CanId->text();
    sscanf(str.toLatin1(),"%x",&tmsg[0].ID);
    lenth = str2u8( tmsg[0].Data,ui->lineEdit->text());
    tmsg[0].DataLen = lenth;
    CAN_Transmit(dev,cpot,tmsg,1,100);
}
