#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kalkulator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ZERO_clicked();
    void on_JEDEN_clicked();
    void on_DWA_clicked();
    void on_TRZY_clicked();
    void on_CZTERY_clicked();
    void on_PIEC_clicked();
    void on_SZESC_clicked();
    void on_SIEDEM_clicked();
    void on_OSIEM_clicked();
    void on_DZIEWIEC_clicked();





    void on_OFF_clicked();

    void on_CLEAR_clicked();

    void on_MEMORY_CLEAR_clicked();

    void on_MODULO_clicked();

    void on_MULTIPLY_clicked();

    void on_SUB_clicked();

    void on_ADD_clicked();

    void on_DIVIDE_clicked();

    void on_DOT_clicked();

    void on_EQUALS_clicked();

    void on_MEM_ADD_clicked();

    void on_MEM_SUB_clicked();

    void on_MEM_GET_clicked();

    void on_BACKSPACE_clicked();

    void on_Matrix_clicked();

    void on_actionAUTOR_triggered();


    void on_KONWERSJA_clicked();

private:
    Ui::MainWindow *ui;
    kalkulator calc;
    QString liczba1;
    QString liczba2;
    QString znak;
    QString operacje;
    bool z_klikniety = false;
    QString akt_cyfra;
     double pamiec = 0;



};

#endif // MAINWINDOW_H
