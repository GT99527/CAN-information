#ifndef MAINWD_H
#define MAINWD_H

#include <QMainWindow>
#include <QTabWidget>
#include "form.h"

namespace Ui {
class Mainwd;
}

class Mainwd : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainwd(QWidget *parent = nullptr);
    ~Mainwd();
    void rushcandevices(void);
private slots:
    void on_pushButton_clicked();

    void on_canpot_currentIndexChanged(int index);

private:

    int canport;
    int devices;
    Form *frm1;
    Form *frm2;
    Ui::Mainwd *ui;
};

#endif // MAINWD_H
