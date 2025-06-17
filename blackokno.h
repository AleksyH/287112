/**
 * @file blackokno.h
 * @brief Definicja klasy blackokno, interfejsu graficznego dla gry Blackjack.
 */

#ifndef BLACKOKNO_H
#define BLACKOKNO_H

#include <QDialog>
#include "portfel.h"
#include "blackjack.h"
#include "statystykiblackjack.h"

namespace Ui { class blackokno; }
class MainWindow;

/**
 * @class blackokno
 * @brief Klasa okna dialogowego dla gry Blackjack.
 *
 * Odpowiada za interfejs graficzny, obsługę zdarzeń od użytkownika (kliknięcia)
 * oraz komunikację z obiektem logiki gry BlackJack.
 */
class blackokno : public QDialog
{
    Q_OBJECT
public:
    explicit blackokno(Portfel *portfel, QWidget *parent = nullptr, MainWindow *main = nullptr);
    ~blackokno();

private slots:
    void on_dealButton_clicked();
    void on_hitButton_clicked();
    void on_standButton_clicked();
    void on_reset_clicked();

    void zmienStan(BlackJack::GameState nowyStan, const QString& msg);
    void kartaGracza(const Card& karta);
    void kartaKrupiera(const Card& karta, bool ukryta);
    void pokazWyniki(int gracz, int krupier);
    void odkryjKarte(const Card& karta);
    void aktualizujStatystyki(const BlackJack& gra);

private:
    void setup();
    void pokazRekeGracza();
    void pokazRekeKrupiera(bool pokazWszystkie = false);
    void resetPlansza();
    void ustawPrzyciski(BlackJack::GameState stan);

    Ui::blackokno *ui; ///< Wskaźnik do obiektów UI wygenerowanych z pliku .ui.
    Portfel *portfel; ///< Wskaźnik do obiektu portfela.
    MainWindow *mainWindow; ///< Wskaźnik do głównego okna aplikacji.
    BlackJack *gra; ///< Wskaźnik do obiektu logiki gry.
    StatystykiGry *statystyki; ///< Wskaźnik do obiektu statystyk.
    double stawka; ///< Aktualna stawka w grze.
};

#endif // BLACKOKNO_H
