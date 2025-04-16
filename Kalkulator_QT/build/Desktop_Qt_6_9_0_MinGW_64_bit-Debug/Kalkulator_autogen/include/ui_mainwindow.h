/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAUTOR;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *EQUALS;
    QPushButton *MODULO;
    QPushButton *DZIEWIEC;
    QPushButton *MEM_GET;
    QPushButton *CZTERY;
    QPushButton *MEM_SUB;
    QPushButton *MULTIPLY;
    QPushButton *SZESC;
    QPushButton *ZERO;
    QPushButton *TRZY;
    QPushButton *MEM_ADD;
    QPushButton *DWA;
    QPushButton *SIEDEM;
    QPushButton *BACKSPACE;
    QPushButton *PIEC;
    QPushButton *MEMORY_CLEAR;
    QPushButton *SUB;
    QPushButton *OFF;
    QPushButton *CLEAR;
    QPushButton *DOT;
    QPushButton *DIVIDE;
    QPushButton *OSIEM;
    QPushButton *ADD;
    QPushButton *JEDEN;
    QLineEdit *EKRAN;
    QLineEdit *EKRAN2;
    QLineEdit *EKRAN3;
    QPushButton *KONWERSJA;
    QComboBox *z_jakiego;
    QComboBox *na_jaki;
    QPushButton *Matrix;
    QMenuBar *menubar;
    QMenu *menuMENU;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(340, 380);
        MainWindow->setMinimumSize(QSize(340, 380));
        MainWindow->setMaximumSize(QSize(340, 380));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color: black;\n"
"\n"
"}\n"
"\n"
"\n"
""));
        actionAUTOR = new QAction(MainWindow);
        actionAUTOR->setObjectName("actionAUTOR");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 120, 320, 230));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        EQUALS = new QPushButton(gridLayoutWidget);
        EQUALS->setObjectName("EQUALS");
        EQUALS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #006400;\n"
" padding: 5px;\n"
"\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(EQUALS, 5, 2, 1, 1);

        MODULO = new QPushButton(gridLayoutWidget);
        MODULO->setObjectName("MODULO");
        MODULO->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MODULO, 1, 3, 1, 1);

        DZIEWIEC = new QPushButton(gridLayoutWidget);
        DZIEWIEC->setObjectName("DZIEWIEC");
        DZIEWIEC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(DZIEWIEC, 4, 2, 1, 1);

        MEM_GET = new QPushButton(gridLayoutWidget);
        MEM_GET->setObjectName("MEM_GET");
        MEM_GET->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MEM_GET, 0, 1, 1, 1);

        CZTERY = new QPushButton(gridLayoutWidget);
        CZTERY->setObjectName("CZTERY");
        CZTERY->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(CZTERY, 3, 0, 1, 1);

        MEM_SUB = new QPushButton(gridLayoutWidget);
        MEM_SUB->setObjectName("MEM_SUB");
        MEM_SUB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MEM_SUB, 0, 3, 1, 1);

        MULTIPLY = new QPushButton(gridLayoutWidget);
        MULTIPLY->setObjectName("MULTIPLY");
        MULTIPLY->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MULTIPLY, 3, 3, 1, 1);

        SZESC = new QPushButton(gridLayoutWidget);
        SZESC->setObjectName("SZESC");
        SZESC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(SZESC, 3, 2, 1, 1);

        ZERO = new QPushButton(gridLayoutWidget);
        ZERO->setObjectName("ZERO");
        ZERO->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(ZERO, 5, 0, 1, 1);

        TRZY = new QPushButton(gridLayoutWidget);
        TRZY->setObjectName("TRZY");
        TRZY->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(TRZY, 2, 2, 1, 1);

        MEM_ADD = new QPushButton(gridLayoutWidget);
        MEM_ADD->setObjectName("MEM_ADD");
        MEM_ADD->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MEM_ADD, 0, 2, 1, 1);

        DWA = new QPushButton(gridLayoutWidget);
        DWA->setObjectName("DWA");
        DWA->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(DWA, 2, 1, 1, 1);

        SIEDEM = new QPushButton(gridLayoutWidget);
        SIEDEM->setObjectName("SIEDEM");
        SIEDEM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(SIEDEM, 4, 0, 1, 1);

        BACKSPACE = new QPushButton(gridLayoutWidget);
        BACKSPACE->setObjectName("BACKSPACE");
        BACKSPACE->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(BACKSPACE, 1, 2, 1, 1);

        PIEC = new QPushButton(gridLayoutWidget);
        PIEC->setObjectName("PIEC");
        PIEC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(PIEC, 3, 1, 1, 1);

        MEMORY_CLEAR = new QPushButton(gridLayoutWidget);
        MEMORY_CLEAR->setObjectName("MEMORY_CLEAR");
        MEMORY_CLEAR->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(MEMORY_CLEAR, 1, 1, 1, 1);

        SUB = new QPushButton(gridLayoutWidget);
        SUB->setObjectName("SUB");
        SUB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(SUB, 4, 3, 1, 1);

        OFF = new QPushButton(gridLayoutWidget);
        OFF->setObjectName("OFF");
        OFF->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(OFF, 0, 0, 1, 1);

        CLEAR = new QPushButton(gridLayoutWidget);
        CLEAR->setObjectName("CLEAR");
        CLEAR->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(CLEAR, 1, 0, 1, 1);

        DOT = new QPushButton(gridLayoutWidget);
        DOT->setObjectName("DOT");
        DOT->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(DOT, 5, 1, 1, 1);

        DIVIDE = new QPushButton(gridLayoutWidget);
        DIVIDE->setObjectName("DIVIDE");
        DIVIDE->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(DIVIDE, 2, 3, 1, 1);

        OSIEM = new QPushButton(gridLayoutWidget);
        OSIEM->setObjectName("OSIEM");
        OSIEM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(OSIEM, 4, 1, 1, 1);

        ADD = new QPushButton(gridLayoutWidget);
        ADD->setObjectName("ADD");
        ADD->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(ADD, 5, 3, 1, 1);

        JEDEN = new QPushButton(gridLayoutWidget);
        JEDEN->setObjectName("JEDEN");
        JEDEN->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: #696969;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));

        gridLayout_2->addWidget(JEDEN, 2, 0, 1, 1);

        TRZY->raise();
        DWA->raise();
        PIEC->raise();
        SZESC->raise();
        MEMORY_CLEAR->raise();
        SIEDEM->raise();
        CZTERY->raise();
        OSIEM->raise();
        DIVIDE->raise();
        MODULO->raise();
        DZIEWIEC->raise();
        JEDEN->raise();
        CLEAR->raise();
        MULTIPLY->raise();
        SUB->raise();
        MEM_ADD->raise();
        MEM_SUB->raise();
        MEM_GET->raise();
        OFF->raise();
        BACKSPACE->raise();
        ADD->raise();
        EQUALS->raise();
        DOT->raise();
        ZERO->raise();
        EKRAN = new QLineEdit(centralwidget);
        EKRAN->setObjectName("EKRAN");
        EKRAN->setGeometry(QRect(10, 50, 321, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setPointSize(28);
        EKRAN->setFont(font);
        EKRAN->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"     background-color: black;\n"
"     border: 1px solid  #006400 ;\n"
"color: #006400;\n"
"}    \n"
""));
        EKRAN->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        EKRAN2 = new QLineEdit(centralwidget);
        EKRAN2->setObjectName("EKRAN2");
        EKRAN2->setGeometry(QRect(210, 10, 121, 41));
        EKRAN2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	font: 14pt \"Segoe UI\";\n"
"     background-color: black;\n"
"     border: 1px solid  #006400 ;\n"
"color: #006400;\n"
"}    \n"
""));
        EKRAN2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        EKRAN3 = new QLineEdit(centralwidget);
        EKRAN3->setObjectName("EKRAN3");
        EKRAN3->setGeometry(QRect(20, 60, 91, 41));
        EKRAN3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	font: 14pt \"Segoe UI\";\n"
"     background-color: black;\n"
"     border: 0px;\n"
" color: #006400;\n"
"}    \n"
""));
        KONWERSJA = new QPushButton(centralwidget);
        KONWERSJA->setObjectName("KONWERSJA");
        KONWERSJA->setGeometry(QRect(10, 10, 61, 41));
        KONWERSJA->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #008000;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));
        z_jakiego = new QComboBox(centralwidget);
        z_jakiego->addItem(QString());
        z_jakiego->addItem(QString());
        z_jakiego->addItem(QString());
        z_jakiego->addItem(QString());
        z_jakiego->setObjectName("z_jakiego");
        z_jakiego->setGeometry(QRect(70, 10, 71, 41));
        z_jakiego->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));
        na_jaki = new QComboBox(centralwidget);
        na_jaki->addItem(QString());
        na_jaki->addItem(QString());
        na_jaki->addItem(QString());
        na_jaki->addItem(QString());
        na_jaki->setObjectName("na_jaki");
        na_jaki->setGeometry(QRect(140, 10, 71, 41));
        na_jaki->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color:  #228B22;\n"
" padding: 5px;\n"
"}    \n"
"QPushButton:pressed{\n"
"     background-color: #A9A9A9;\n"
" padding: 5px;\n"
"}    "));
        Matrix = new QPushButton(centralwidget);
        Matrix->setObjectName("Matrix");
        Matrix->setGeometry(QRect(130, 60, 16, 16));
        Matrix->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"     background-color: black;\n"
"     border: 0px;\n"
"}    \n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 340, 22));
        menuMENU = new QMenu(menubar);
        menuMENU->setObjectName("menuMENU");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMENU->menuAction());
        menuMENU->addAction(actionAUTOR);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAUTOR->setText(QCoreApplication::translate("MainWindow", "AUTOR", nullptr));
        EQUALS->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        MODULO->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        DZIEWIEC->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        MEM_GET->setText(QCoreApplication::translate("MainWindow", "M_GET", nullptr));
        CZTERY->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        MEM_SUB->setText(QCoreApplication::translate("MainWindow", "M-", nullptr));
        MULTIPLY->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        SZESC->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        ZERO->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        TRZY->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        MEM_ADD->setText(QCoreApplication::translate("MainWindow", "M+", nullptr));
        DWA->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        SIEDEM->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        BACKSPACE->setText(QCoreApplication::translate("MainWindow", "BACKSPACE", nullptr));
        PIEC->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        MEMORY_CLEAR->setText(QCoreApplication::translate("MainWindow", "M_CLEAR", nullptr));
        SUB->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        OFF->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        CLEAR->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        DOT->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        DIVIDE->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        OSIEM->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        ADD->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        JEDEN->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        EKRAN->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        KONWERSJA->setText(QCoreApplication::translate("MainWindow", "CONVERT", nullptr));
        z_jakiego->setItemText(0, QCoreApplication::translate("MainWindow", "Binarny", nullptr));
        z_jakiego->setItemText(1, QCoreApplication::translate("MainWindow", "\303\223semkowy", nullptr));
        z_jakiego->setItemText(2, QCoreApplication::translate("MainWindow", "Dziesi\304\231tny", nullptr));
        z_jakiego->setItemText(3, QCoreApplication::translate("MainWindow", "Szesnastkowy", nullptr));

        na_jaki->setItemText(0, QCoreApplication::translate("MainWindow", "Binarny", nullptr));
        na_jaki->setItemText(1, QCoreApplication::translate("MainWindow", "\303\223semkowy", nullptr));
        na_jaki->setItemText(2, QCoreApplication::translate("MainWindow", "Dziesi\304\231tny", nullptr));
        na_jaki->setItemText(3, QCoreApplication::translate("MainWindow", "Szesnastkowy", nullptr));

        Matrix->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        menuMENU->setTitle(QCoreApplication::translate("MainWindow", "MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
