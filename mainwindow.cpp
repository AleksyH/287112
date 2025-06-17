#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ruletkaokno.h"
#include "blackokno.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ruletkaokno_(nullptr)
    , blackokno_(nullptr)
{
    ui->setupUi(this);

    this->setStyleSheet(
        "QMainWindow {"
        " background-image: url(:/images/do_projektu.png);"
        " background-repeat: no-repeat;"
        " background-position: center;"
        " background-size: cover;"
        " }"
    );

    ui->stankonta->setText(QString::number(m_portfel.pobierzSaldo(), 'f', 2) + " $");

    connect(&m_portfel, &Portfel::saldoZmienione, this, [=](double saldo){
        ui->stankonta->setText(QString::number(saldo, 'f', 2) + " $");
    });
    ui->stankonta->setReadOnly(true);


    connect(ui->openWindowButton, &QPushButton::clicked, this, &MainWindow::openRuletkaWindow);
    connect(ui->openWindowButton2, &QPushButton::clicked, this, &MainWindow::openBlackjackWindow);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::openRuletkaWindow()
{
    if (!ruletkaokno_) {

        ruletkaokno_ = new ruletkaokno(this, &m_portfel, this);
        ruletkaokno_->setAttribute(Qt::WA_DeleteOnClose);
        connect(ruletkaokno_, &QDialog::finished, this, [this](){ ruletkaokno_ = nullptr; });
    }
    if(ruletkaokno_){
        ruletkaokno_->show();
        this->hide();
    }
}

void MainWindow::openBlackjackWindow()
{
    if (!blackokno_) {

        blackokno_ = new blackokno(&m_portfel, this, this);
        blackokno_->setAttribute(Qt::WA_DeleteOnClose);
        connect(blackokno_, &QDialog::finished, this, [this](){ blackokno_ = nullptr; });
    }
    if(blackokno_){
        blackokno_->show();
        this->hide();
    }
}
