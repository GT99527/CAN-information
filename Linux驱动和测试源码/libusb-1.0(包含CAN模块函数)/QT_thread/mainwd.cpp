#include "mainwd.h"
#include "ui_mainwd.h"
#include "form.h"
#include <QMessageBox>
#include <QDebug>

Mainwd::Mainwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainwd)
{
    ui->setupUi(this);
    frm1 = new Form;
    ui->tabWidget->removeTab(0);
    frm1->dev = 0;
    frm1->cpot = 0;
    ui->tabWidget->addTab(frm1,"CAN1");

    frm2 = new Form;
    frm2->dev = 0;
    frm2->cpot = 1;
    ui->tabWidget->addTab(frm2,"CAN2");
    ui->tabWidget->setEnabled(false);

    rushcandevices();
}

Mainwd::~Mainwd()
{
    delete ui;
}

void Mainwd::on_pushButton_clicked()
{
    rushcandevices();
}


void Mainwd::rushcandevices(void)
{
    int i,devs;
    QString str,str2;
    devs = CAN_ScanDevice();


    if(devs > 0)
    {
        str2 = "";
        for(i = devices ; i < devs; i++)
        {
            str.sprintf("%d",i);
            str2 += " "+str;
        }
        if(devs!= devices)
        {
            devices = devs;
            ui->canpot->clear();
            for(i = 0 ; i < devices; i++)
            {
                str.sprintf("%d",i);
                ui->canpot->addItem(str);
            }
        }
        ui->tabWidget->setEnabled(true);
    }
    else
    {
        devices = 0;
        ui->canpot->clear();
    }
}


void Mainwd::on_canpot_currentIndexChanged(int index)
{
    frm1->dev = index;
    frm2->dev = index;
}

