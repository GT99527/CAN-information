#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include <QDate>
#include "ucanbus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void hotplug_func(void);

private:
    int cpot;
    Ui::MainWindow *ui;
    void rushcandevices(void);
signals:
    void sendhotplugs(void);
};
#endif // MAINWINDOW_H
