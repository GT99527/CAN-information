#include "mainwindow.h"
#include "ucanbus.h"
#include <QApplication>

MainWindow *w;

void func_hotplugs(void)
{
    w->sendhotplugs();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font  = a.font();
    font.setPointSize(10);
    a.setFont(font);
    a.setAttribute(Qt::AA_EnableHighDpiScaling);
    w = new MainWindow;
    Reg_HotPlug_Func(&func_hotplugs);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    return a.exec();
}
