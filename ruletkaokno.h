/**
 * @file ruletkaokno.h
 * @brief Definicja klasy ruletkaokno, interfejsu graficznego dla gry w Ruletkę.
 */

#ifndef RULETKAOKNO_H
#define RULETKAOKNO_H

#include <QDialog>
#include "ruletka.h"
#include "portfel.h"
#include "statystykiruletki.h"

class MainWindow;
namespace Ui { class ruletkaokno; }

/**
 * @class ruletkaokno
 * @brief Klasa okna dialogowego dla gry w Ruletkę.
 *
 * Odpowiada za interfejs graficzny, obsługę zakładów i komunikację z logiką gry.
 */
class ruletkaokno : public QDialog
{
    Q_OBJECT

public:
    explicit ruletkaokno(QWidget *parent = nullptr, Portfel *portfel = nullptr, MainWindow *main = nullptr);
    ~ruletkaokno();

private slots:
    void on_spinButton_clicked();
    void on_All_In_clicked();
    void on_reset_clicked();
    void obsluzKoniecRundy(const Ruletka& gra, const QString& komunikat);


    void on_zero_clicked();
    void on_jeden_clicked();
    void on_dwa_clicked();
    void on_trzy_clicked();
    void on_cztery_clicked();
    void on_piec_clicked();
    void on_szesc_clicked();
    void on_siedem_clicked();
    void on_osiem_clicked();
    void on_dziewiec_clicked();
    void on_dziesiec_clicked();
    void on_jedena_clicked();
    void on_dwana_clicked();
    void on_trzyna_clicked();
    void on_czterna_clicked();
    void on_pietna_clicked();
    void on_szesna_clicked();
    void on_siedemna_clicked();
    void on_osiemna_clicked();
    void on_dziewietna_clicked();
    void on_dwadziescia_clicked();
    void on_dwajeden_clicked();
    void on_dwadwa_clicked();
    void on_dwatrzy_clicked();
    void on_dwacztery_clicked();
    void on_dwapiec_clicked();
    void on_dwaszesc_clicked();
    void on_dwasiedem_clicked();
    void on_dwaosiem_clicked();
    void on_dwadziewiec_clicked();
    void on_trzydziesci_clicked();
    void on_trzyjeden_clicked();
    void on_trzydwa_clicked();
    void on_trzytrzy_clicked();
    void on_trzycztery_clicked();
    void on_trzypiec_clicked();
    void on_trzyszesc_clicked();
    void on_red_clicked();
    void on_black_clicked();
    void on_even_clicked();
    void on_odd_clicked();
    void aktual_walidator();

private:
    Ui::ruletkaokno *ui; ///< Wskaźnik do obiektów UI.
    Portfel *portfel; ///< Wskaźnik do portfela.
    MainWindow *mainWindow; ///< Wskaźnik do okna głównego.
    Ruletka *ruletka; ///< Wskaźnik do logiki gry.
    StatystykiRuletki *statystyki; ///< Wskaźnik do statystyk ruletki.

    double aktualnaStawka; ///< Aktualnie postawiona kwota.
    QString typZakladu; ///< Typ postawionego zakładu.
    int obstawionyNumer; ///< Numer, na który postawiono (jeśli dotyczy).
    bool zakladPostawiony; ///< Flaga informująca, czy postawiono zakład.

    void przygotujZaklad(const QString& typ, int numer = -1);
    void wyswietlStatusZakladu(const QString& wiadomosc = "");
};

#endif // RULETKAOKNO_H
