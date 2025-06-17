#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "portfel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ruletkaokno;
class blackokno;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openRuletkaWindow();
    void openBlackjackWindow();

private:
    Ui::MainWindow *ui;
    Portfel m_portfel;
    ruletkaokno *ruletkaokno_;
    blackokno *blackokno_;
};

#endif // MAINWINDOW_H
