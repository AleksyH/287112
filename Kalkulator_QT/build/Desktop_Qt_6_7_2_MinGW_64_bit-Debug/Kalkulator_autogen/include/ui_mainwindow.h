/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *OFF;
    QPushButton *pushButton_2;
    QPushButton *TRZY;
    QPushButton *KONWERSJA;
    QPushButton *DOT;
    QPushButton *SUB;
    QPushButton *ADD;
    QPushButton *ZERO;
    QPushButton *CZTERY;
    QPushButton *DZIEWIEC;
    QPushButton *SIEDEM;
    QPushButton *MULTIPLY;
    QPushButton *DIVIDE;
    QPushButton *PIEC;
    QPushButton *MEMORY_CLEAR;
    QPushButton *EQUALS;
    QPushButton *OSIEM;
    QPushButton *DWA;
    QPushButton *SZESC;
    QPushButton *JEDEN;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(340, 380);
        MainWindow->setMinimumSize(QSize(340, 380));
        MainWindow->setMaximumSize(QSize(340, 380));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 130, 320, 206));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        OFF = new QPushButton(gridLayoutWidget);
        OFF->setObjectName("OFF");

        gridLayout_2->addWidget(OFF, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 0, 3, 1, 1);

        TRZY = new QPushButton(gridLayoutWidget);
        TRZY->setObjectName("TRZY");

        gridLayout_2->addWidget(TRZY, 1, 2, 1, 1);

        KONWERSJA = new QPushButton(gridLayoutWidget);
        KONWERSJA->setObjectName("KONWERSJA");

        gridLayout_2->addWidget(KONWERSJA, 0, 2, 1, 1);

        DOT = new QPushButton(gridLayoutWidget);
        DOT->setObjectName("DOT");

        gridLayout_2->addWidget(DOT, 4, 1, 1, 1);

        SUB = new QPushButton(gridLayoutWidget);
        SUB->setObjectName("SUB");

        gridLayout_2->addWidget(SUB, 3, 3, 1, 1);

        ADD = new QPushButton(gridLayoutWidget);
        ADD->setObjectName("ADD");

        gridLayout_2->addWidget(ADD, 4, 3, 1, 1);

        ZERO = new QPushButton(gridLayoutWidget);
        ZERO->setObjectName("ZERO");

        gridLayout_2->addWidget(ZERO, 4, 0, 1, 1);

        CZTERY = new QPushButton(gridLayoutWidget);
        CZTERY->setObjectName("CZTERY");

        gridLayout_2->addWidget(CZTERY, 2, 0, 1, 1);

        DZIEWIEC = new QPushButton(gridLayoutWidget);
        DZIEWIEC->setObjectName("DZIEWIEC");

        gridLayout_2->addWidget(DZIEWIEC, 3, 2, 1, 1);

        SIEDEM = new QPushButton(gridLayoutWidget);
        SIEDEM->setObjectName("SIEDEM");

        gridLayout_2->addWidget(SIEDEM, 3, 0, 1, 1);

        MULTIPLY = new QPushButton(gridLayoutWidget);
        MULTIPLY->setObjectName("MULTIPLY");

        gridLayout_2->addWidget(MULTIPLY, 2, 3, 1, 1);

        DIVIDE = new QPushButton(gridLayoutWidget);
        DIVIDE->setObjectName("DIVIDE");

        gridLayout_2->addWidget(DIVIDE, 1, 3, 1, 1);

        PIEC = new QPushButton(gridLayoutWidget);
        PIEC->setObjectName("PIEC");

        gridLayout_2->addWidget(PIEC, 2, 1, 1, 1);

        MEMORY_CLEAR = new QPushButton(gridLayoutWidget);
        MEMORY_CLEAR->setObjectName("MEMORY_CLEAR");

        gridLayout_2->addWidget(MEMORY_CLEAR, 0, 1, 1, 1);

        EQUALS = new QPushButton(gridLayoutWidget);
        EQUALS->setObjectName("EQUALS");

        gridLayout_2->addWidget(EQUALS, 4, 2, 1, 1);

        OSIEM = new QPushButton(gridLayoutWidget);
        OSIEM->setObjectName("OSIEM");

        gridLayout_2->addWidget(OSIEM, 3, 1, 1, 1);

        DWA = new QPushButton(gridLayoutWidget);
        DWA->setObjectName("DWA");

        gridLayout_2->addWidget(DWA, 1, 1, 1, 1);

        SZESC = new QPushButton(gridLayoutWidget);
        SZESC->setObjectName("SZESC");

        gridLayout_2->addWidget(SZESC, 2, 2, 1, 1);

        JEDEN = new QPushButton(gridLayoutWidget);
        JEDEN->setObjectName("JEDEN");

        gridLayout_2->addWidget(JEDEN, 1, 0, 1, 1);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(10, 40, 321, 81));
        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(220, 10, 111, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 340, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OFF->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        TRZY->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        KONWERSJA->setText(QCoreApplication::translate("MainWindow", "CONVERT", nullptr));
        DOT->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        SUB->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        ADD->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        ZERO->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        CZTERY->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        DZIEWIEC->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        SIEDEM->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        MULTIPLY->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        DIVIDE->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        PIEC->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        MEMORY_CLEAR->setText(QCoreApplication::translate("MainWindow", "M_CLEAR", nullptr));
        EQUALS->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        OSIEM->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        DWA->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        SZESC->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        JEDEN->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
