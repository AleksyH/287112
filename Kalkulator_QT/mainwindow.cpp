#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->EKRAN->setReadOnly(true);
    ui->EKRAN2->setReadOnly(true);
    ui->EKRAN3->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ZERO_clicked()
{
    akt_cyfra+= '0';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_JEDEN_clicked()
{
    akt_cyfra+= '1';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_DWA_clicked()
{
    akt_cyfra+= '2';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_TRZY_clicked()
{
    akt_cyfra+= '3';
    ui->EKRAN->setText(akt_cyfra);
}

void MainWindow::on_CZTERY_clicked()
{
    akt_cyfra+= '4';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_PIEC_clicked()
{
    akt_cyfra+= '5';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_SZESC_clicked()
{
    akt_cyfra+= '6';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_SIEDEM_clicked()
{
    akt_cyfra+= '7';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_OSIEM_clicked()
{
    akt_cyfra+= '8';
    ui->EKRAN->setText(akt_cyfra);
}
void MainWindow::on_DZIEWIEC_clicked()
{
    akt_cyfra+= '9';
    ui->EKRAN->setText(akt_cyfra);
}

void MainWindow::on_OFF_clicked()
{
    QApplication::quit();
}

void MainWindow::on_CLEAR_clicked()
{
    akt_cyfra.clear();
    liczba1.clear();
    liczba2.clear();
    znak.clear();
    z_klikniety = false;
    ui->EKRAN->setText("");
    ui->EKRAN3->setText("");
}


void MainWindow::on_MEMORY_CLEAR_clicked()
{
    pamiec = 0;
    ui->EKRAN2->clear();
}


void MainWindow::on_MODULO_clicked()
{
    ui->EKRAN3->show();
    if (!z_klikniety) {
        liczba1 = akt_cyfra;
        akt_cyfra.clear();
        z_klikniety = true;
        znak = "%";
    } else {
        liczba2 = akt_cyfra;
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;
        ui->EKRAN3->setText(liczba1 + znak + liczba2);
        if (znak == "+") wynik = calc.add(a, b);
        else if (znak == "-") wynik = calc.sub(a, b);
        else if (znak == "*") wynik = calc.tim(a, b);
        else if (znak == "/") wynik = calc.div(a, b);
        else if (znak == "%") wynik = calc.mod(a, b);

        liczba1 = QString::number(wynik);
        ui->EKRAN->setText(liczba1);

        akt_cyfra.clear();
    }

    znak = "%";
}


void MainWindow::on_MULTIPLY_clicked()
{
    ui->EKRAN3->show();
    if (!z_klikniety) {
        liczba1 = akt_cyfra;
        akt_cyfra.clear();
        z_klikniety = true;
        znak = "*";
    } else {
        liczba2 = akt_cyfra;
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;
        if (b == 0 and znak=="/" || znak=="%") {
            QMessageBox::critical(this, "Błąd", "Nie można dzielić przez 0!");
            ui->EKRAN->setText("");
            ui->EKRAN3->setText("");
            akt_cyfra.clear();
            liczba1.clear();
            liczba2.clear();
            z_klikniety = false;
            return;
        }
        ui->EKRAN3->setText(liczba1 + znak + liczba2);
        if (znak == "+") wynik = calc.add(a, b);
        else if (znak == "-") wynik = calc.sub(a, b);
        else if (znak == "*") wynik = calc.tim(a, b);
        else if (znak == "/") wynik = calc.div(a, b);
        else if (znak == "%") wynik = calc.mod(a, b);

        liczba1 = QString::number(wynik);
        ui->EKRAN->setText(liczba1);

        akt_cyfra.clear();
    }

    znak = "*";
}


void MainWindow::on_SUB_clicked()
{
    ui->EKRAN3->show();
    if (!z_klikniety) {
        liczba1 = akt_cyfra;
        akt_cyfra.clear();
        z_klikniety = true;
        znak = "-";
    } else {
        liczba2 = akt_cyfra;
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;
        ui->EKRAN3->setText(liczba1 + znak + liczba2);
        if (znak == "+") wynik = calc.add(a, b);
        else if (znak == "-") wynik = calc.sub(a, b);
        else if (znak == "*") wynik = calc.tim(a, b);
        else if (znak == "/") wynik = calc.div(a, b);
        else if (znak == "%") wynik = calc.mod(a, b);

        liczba1 = QString::number(wynik);
        ui->EKRAN->setText(liczba1);

        akt_cyfra.clear();
    }

    znak = "-";
}


void MainWindow::on_ADD_clicked()
{
    ui->EKRAN3->show();
    if (!z_klikniety) {
        liczba1 = akt_cyfra;
        akt_cyfra.clear();
        z_klikniety = true;
        znak = "+";
    } else {
        liczba2 = akt_cyfra;
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;
        ui->EKRAN3->setText(liczba1 + znak + liczba2);
        if (znak == "+") wynik = calc.add(a, b);
        else if (znak == "-") wynik = calc.sub(a, b);
        else if (znak == "*") wynik = calc.tim(a, b);
        else if (znak == "/") wynik = calc.div(a, b);
        else if (znak == "%") wynik = calc.mod(a, b);

        liczba1 = QString::number(wynik);
        ui->EKRAN->setText(liczba1);

        akt_cyfra.clear();
    }

    znak = "+";

}


void MainWindow::on_DIVIDE_clicked()
{
    ui->EKRAN3->show();
    if (!z_klikniety) {
        liczba1 = akt_cyfra;
        akt_cyfra.clear();
        z_klikniety = true;
        znak = "/";
    } else {
        liczba2 = akt_cyfra;
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;
        if (b == 0) {
            QMessageBox::critical(this, "Błąd", "Nie można dzielić przez 0!");
            ui->EKRAN->setText("");
            ui->EKRAN3->setText("");
            akt_cyfra.clear();
            liczba1.clear();
            liczba2.clear();
            z_klikniety = false;
            return;
        }
        ui->EKRAN3->setText(liczba1 + znak + liczba2);
        if (znak == "+") wynik = calc.add(a, b);
        else if (znak == "-") wynik = calc.sub(a, b);
        else if (znak == "*") wynik = calc.tim(a, b);
        else if (znak == "/") wynik = calc.div(a, b);
        else if (znak == "%") wynik = calc.mod(a, b);

        liczba1 = QString::number(wynik);
        ui->EKRAN->setText(liczba1);

        akt_cyfra.clear();
    }

    znak = "/";
}


void MainWindow::on_DOT_clicked()
{
    if (!akt_cyfra.contains('.')) {
        akt_cyfra += '.';
        ui->EKRAN->setText(akt_cyfra);
    }
}


void MainWindow::on_EQUALS_clicked()

{
    ui->EKRAN3->show();
    if (!z_klikniety or akt_cyfra.isEmpty())
        return;

    liczba2 = akt_cyfra;
    double a = liczba1.toDouble();
    double b = liczba2.toDouble();
    double wynik = 0;
    if (b == 0 && (znak == "/" || znak == "%")) {
        QMessageBox::critical(this, "Błąd", "Nie można dzielić przez 0!");
        ui->EKRAN->setText("");
        ui->EKRAN3->setText("");
        akt_cyfra.clear();
        liczba1.clear();
        liczba2.clear();
        z_klikniety = false;
        return;
    }
    if (znak == "+") wynik = calc.add(a, b);
    else if (znak == "-") wynik = calc.sub(a, b);
    else if (znak == "*") wynik = calc.tim(a, b);
    else if (znak == "/") wynik = calc.div(a, b);
    else if (znak == "%") wynik = calc.mod(a, b);

    QString wynikText = QString::number(wynik);
    ui->EKRAN->setText(wynikText);
    ui->EKRAN3->setText(liczba1 + znak + liczba2);
    akt_cyfra.clear();
    liczba1 = wynikText;
    liczba2.clear();
    z_klikniety = false;

}



void MainWindow::on_MEM_ADD_clicked()
{
    double wartosc = ui->EKRAN->text().toDouble();
    pamiec += wartosc;
    ui->EKRAN2->setText("M: " + QString::number(pamiec));
}


void MainWindow::on_MEM_SUB_clicked()
{
    double wartosc = ui->EKRAN->text().toDouble();
    pamiec -= wartosc;
    ui->EKRAN2->setText("M: " + QString::number(pamiec));
}




void MainWindow::on_MEM_GET_clicked()
{
    akt_cyfra = QString::number(pamiec);
    ui->EKRAN->setText(akt_cyfra);
}


void MainWindow::on_BACKSPACE_clicked()
{
    if (!akt_cyfra.isEmpty()) {
        akt_cyfra.chop(1);
        ui->EKRAN->setText(akt_cyfra);
    }
}


void MainWindow::on_Matrix_clicked()
{
    ui->EKRAN3->hide();
    ui->Matrix->hide();

    ui->EKRAN->setText("0101010101010101010101010101");


    int ret = QMessageBox::critical(this, "The matrix has you...", "Follow the white rabbit.\nKnock knock, Neo.", QMessageBox::Ok);

    if (ret == QMessageBox::Ok) {
        QApplication::quit();
    }
}


void MainWindow::on_actionAUTOR_triggered()
{
    QMessageBox::information(this, "Autor", "Autor: Aleksy Harbacewicz\nNr indeksu: 287112");
}

void MainWindow::on_KONWERSJA_clicked()
{
    ui->EKRAN3->hide();
    QString liczba_kon;
    if (akt_cyfra == "") {
        liczba_kon = ui->EKRAN->text();
    } else {
        liczba_kon = akt_cyfra;
    }

    QString from = ui->z_jakiego->currentText();
    QString to = ui->na_jaki->currentText();
    int z_systemu = 10;
    int na_system = 10;

    if (from == "Binarny") z_systemu = 2;
    if (from == "Ósemkowy") z_systemu = 8;
    if (from == "Dziesiętny") z_systemu = 10;
    if (from == "Szesnastkowy") z_systemu = 16;

    if (to == "Binarny") na_system = 2;
    if (to == "Ósemkowy") na_system = 8;
    if (to == "Dziesiętny") na_system = 10;
    if (to == "Szesnastkowy") na_system = 16;

    bool czy_działa;
    int wartosc = liczba_kon.toInt(&czy_działa, z_systemu);
    if (czy_działa == false) {
         QMessageBox::critical(this, "Błąd Konwersji", "Konwersja nie powiodła sie");
        akt_cyfra.clear();
         ui->EKRAN->clear();
        return;
    }

    QString wynik_kon = QString::number(wartosc, na_system);
    ui->EKRAN->setText("Wynik: " + wynik_kon);
    akt_cyfra.clear();
}


