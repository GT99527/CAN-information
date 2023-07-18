/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *canpot;
    QLabel *label_34;
    QComboBox *baudrate;
    QLabel *label_2;
    QComboBox *wkmode;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *awum;
    QCheckBox *nart;
    QCheckBox *inres;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *readpar;
    QPushButton *setpar;
    QPushButton *opencan;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(446, 457);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout_7 = new QVBoxLayout(frame_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, -1, 5, -1);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        canpot = new QComboBox(frame_2);
        canpot->setObjectName(QStringLiteral("canpot"));
        sizePolicy.setHeightForWidth(canpot->sizePolicy().hasHeightForWidth());
        canpot->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(canpot, 0, 1, 1, 1);

        label_34 = new QLabel(frame_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy1.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_34, 1, 0, 1, 1);

        baudrate = new QComboBox(frame_2);
        baudrate->setObjectName(QStringLiteral("baudrate"));
        sizePolicy.setHeightForWidth(baudrate->sizePolicy().hasHeightForWidth());
        baudrate->setSizePolicy(sizePolicy);
        baudrate->setEditable(true);

        gridLayout_2->addWidget(baudrate, 1, 1, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        wkmode = new QComboBox(frame_2);
        wkmode->setObjectName(QStringLiteral("wkmode"));
        sizePolicy.setHeightForWidth(wkmode->sizePolicy().hasHeightForWidth());
        wkmode->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(wkmode, 2, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 5, 5, 5);
        awum = new QCheckBox(frame_2);
        awum->setObjectName(QStringLiteral("awum"));

        horizontalLayout_11->addWidget(awum);

        nart = new QCheckBox(frame_2);
        nart->setObjectName(QStringLiteral("nart"));

        horizontalLayout_11->addWidget(nart);

        inres = new QCheckBox(frame_2);
        inres->setObjectName(QStringLiteral("inres"));
        inres->setChecked(true);

        horizontalLayout_11->addWidget(inres);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, -1);
        readpar = new QPushButton(frame_2);
        readpar->setObjectName(QStringLiteral("readpar"));

        horizontalLayout_12->addWidget(readpar);

        setpar = new QPushButton(frame_2);
        setpar->setObjectName(QStringLiteral("setpar"));

        horizontalLayout_12->addWidget(setpar);

        opencan = new QPushButton(frame_2);
        opencan->setObjectName(QStringLiteral("opencan"));

        horizontalLayout_12->addWidget(opencan);


        verticalLayout_7->addLayout(horizontalLayout_12);

        tableWidget = new QTableWidget(frame_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_7->addWidget(tableWidget);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_7->addWidget(pushButton);


        verticalLayout->addWidget(frame_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SignalGen", 0));
        label->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\351\200\232\351\201\223\357\274\232", 0));
        label_34->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232KBd", 0));
        baudrate->clear();
        baudrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1000", 0)
         << QApplication::translate("MainWindow", "900", 0)
         << QApplication::translate("MainWindow", "800", 0)
         << QApplication::translate("MainWindow", "666", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "500", 0)
         << QApplication::translate("MainWindow", "400", 0)
         << QApplication::translate("MainWindow", "250", 0)
         << QApplication::translate("MainWindow", "200", 0)
         << QApplication::translate("MainWindow", "125", 0)
         << QApplication::translate("MainWindow", "100", 0)
         << QApplication::translate("MainWindow", "80", 0)
         << QApplication::translate("MainWindow", "50", 0)
         << QApplication::translate("MainWindow", "40", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "5", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\250\241\345\274\217\357\274\232", 0));
        wkmode->clear();
        wkmode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\255\243\345\270\270\346\250\241\345\274\217", 0)
         << QApplication::translate("MainWindow", "\347\216\257\345\233\236\346\250\241\345\274\217", 0)
         << QApplication::translate("MainWindow", "\351\235\231\351\273\230\346\250\241\345\274\217", 0)
         << QApplication::translate("MainWindow", "\351\235\231\351\273\230\347\216\257\345\233\236\346\250\241\345\274\217", 0)
        );
        awum->setText(QApplication::translate("MainWindow", "\347\246\273\347\272\277\345\224\244\351\206\222", 0));
        nart->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\351\207\215\344\274\240", 0));
        inres->setText(QApplication::translate("MainWindow", "\346\216\245\351\200\232\347\224\265\351\230\273", 0));
        readpar->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", 0));
        setpar->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        opencan->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\210\227\350\241\250", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
