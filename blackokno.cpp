/**
 * @file blackokno.cpp
 * @brief Implementacja klasy blackokno.
 */

#include "blackokno.h"
#include "ui_blackokno.h"
#include "mainwindow.h"
#include <QDoubleValidator>
#include <QMessageBox>
#include <QDebug>

/**
 * @brief Konstruktor okna gry w Blackjacka.
 *
 * Inicjalizuje UI, obiekty logiki i statystyk oraz łączy sygnały ze slotami.
 */
blackokno::blackokno(Portfel *p, QWidget *parent, MainWindow *main)
    : QDialog(parent),
    ui(new Ui::blackokno),
    portfel(p),
    mainWindow(main),
    gra(new BlackJack(portfel, this)),
    statystyki(new StatystykiGry()),
    stawka(0.0) {
    ui->setupUi(this);
    setup();
    resetPlansza();
    ustawPrzyciski(gra->getCurrentState());
}

/**
 * @brief Destruktor.
 */
blackokno::~blackokno() {
    delete statystyki;
    delete ui;
}

/**
 * @brief Inicjalizuje początkowe ustawienia okna i połączenia sygnałów.
 */
void blackokno::setup() {
    setWindowTitle(gra->getNazwaGry());
    ui->stankonta->setReadOnly(true);
    ui->playerHandEdit->setReadOnly(true);
    ui->dealerHandEdit->setReadOnly(true);
    ui->playerHandEdit->setAlignment(Qt::AlignCenter);
    ui->dealerHandEdit->setAlignment(Qt::AlignCenter);

    double min = 0.01;
    double max = portfel->pobierzSaldo();
    if (max < min) max = min;

    auto validator = new QDoubleValidator(min, max, 2, ui->betLineEdit);
    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->betLineEdit->setValidator(validator);
    ui->betLineEdit->setPlaceholderText("Kwota zakładu");

    connect(ui->back, &QPushButton::clicked, this, [=]() {
        if (mainWindow) mainWindow->show();
        this->close();
    });

    connect(portfel, &Portfel::saldoZmienione, this, [=](double saldo) {
        ui->stankonta->setText(QString::number(saldo, 'f', 2) + " $");
        auto v = static_cast<QDoubleValidator*>(const_cast<QValidator*>(ui->betLineEdit->validator()));
        if (v) v->setTop(qMax(v->bottom(), saldo));
    });

    ui->stankonta->setText(QString::number(portfel->pobierzSaldo(), 'f', 2) + " $");

    connect(gra, &BlackJack::gameStateChanged, this, &blackokno::zmienStan);
    connect(gra, &BlackJack::scoresUpdated, this, &blackokno::pokazWyniki);
    connect(gra, &BlackJack::playerCardDealt, this, &blackokno::kartaGracza);
    connect(gra, &BlackJack::dealerCardDealt, this, &blackokno::kartaKrupiera);
    connect(gra, &BlackJack::dealerRevealedCard, this, &blackokno::odkryjKarte);
    connect(gra, &BlackJack::graZakonczona, this, &blackokno::aktualizujStatystyki);
}

/**
 * @brief Slot obsługujący kliknięcie przycisku "DEAL".
 * Rozpoczyna nową rundę gry.
 */
void blackokno::on_dealButton_clicked() {
    auto currentState = gra->getCurrentState();

    if (currentState != BlackJack::GameState::PlayerTurn &&
        currentState != BlackJack::GameState::DealerTurn &&
        currentState != BlackJack::GameState::Betting) {
        gra->resetujGre();
    }

    if (gra->getCurrentState() != BlackJack::GameState::Betting) {
        QMessageBox::information(this, "Błąd gry", "Spróbuj zresetować.");
        return;
    }

    resetPlansza();

    QString txt = ui->betLineEdit->text().replace(",", ".");
    if (txt.isEmpty()) {
        QMessageBox::warning(this, "Brak stawki", "Wpisz kwotę stawki.");
        ui->betLineEdit->setFocus();
        return;
    }

    bool ok;
    double kwota = txt.toDouble(&ok);

    if (!ok || !ui->betLineEdit->hasAcceptableInput()) {
        QMessageBox::warning(this, "Zła stawka", "Wpisz poprawną kwotę.");
        ui->betLineEdit->setFocus();
        ui->betLineEdit->selectAll();
        return;
    }

    if (kwota > portfel->pobierzSaldo()) {
        QMessageBox::warning(this, "Brak środków", QString("Masz %1 $, chcesz postawić %2 $")
                                                       .arg(portfel->pobierzSaldo(), 0, 'f', 2)
                                                       .arg(kwota, 0, 'f', 2));
        return;
    }

    stawka = kwota;
    gra->startGame(kwota);
}

/**
 * @brief Slot obsługujący kliknięcie przycisku "HIT".
 */
void blackokno::on_hitButton_clicked() {
    gra->playerHit();
}

/**
 * @brief Slot obsługujący kliknięcie przycisku "STAND".
 */
void blackokno::on_standButton_clicked() {
    gra->playerStand();
}

/**
 * @brief Slot reagujący na zmianę stanu gry.
 * Aktualizuje UI, w tym przyciski i widoczność elementów.
 */
void blackokno::zmienStan(BlackJack::GameState stan, const QString& msg) {
    ustawPrzyciski(stan);

    bool isGameFinished = (stan != BlackJack::GameState::PlayerTurn &&
                           stan != BlackJack::GameState::DealerTurn &&
                           stan != BlackJack::GameState::Betting);

    if (isGameFinished) {
        ui->dealerHandEdit->show();

        QMessageBox::information(this, "Koniec rozdania", msg);
    }

    if (stan == BlackJack::GameState::Betting) {
        resetPlansza();
    }

    if (isGameFinished) {
        pokazRekeKrupiera(true);
    }
}

/**
 * @brief Slot wywoływany, gdy gracz otrzymuje kartę.
 */
void blackokno::kartaGracza(const Card&) {
    pokazRekeGracza();
}

/**
 * @brief Slot wywoływany, gdy krupier otrzymuje kartę.
 */
void blackokno::kartaKrupiera(const Card&, bool) {
    pokazRekeKrupiera(gra->getCurrentState() != BlackJack::GameState::PlayerTurn);
}

/**
 * @brief Slot aktualizujący wyświetlane wyniki punktowe.
 */
void blackokno::pokazWyniki(int gracz, int krupier) {
    ui->playerScoreLabel->setText(QString("Wynik: %1").arg(gracz));
    ui->dealerScoreLabel->setText(QString("Wynik: %1").arg(krupier));
}

/**
 * @brief Slot wywoływany, gdy ukryta karta krupiera jest odsłaniana.
 */
void blackokno::odkryjKarte(const Card&) {
    pokazRekeKrupiera(true);
}

/**
 * @brief Slot aktualizujący statystyki po zakończeniu gry.
 */
void blackokno::aktualizujStatystyki(const BlackJack& zakonczonaGra) {
    statystyki->zaktualizujPoGrze(zakonczonaGra);
}

/**
 * @brief Aktualizuje pole tekstowe z kartami gracza.
 */
void blackokno::pokazRekeGracza() {
    QStringList karty;
    for (const Card& c : gra->getPlayerHand()) {
        karty.append(c.valueString());
    }
    ui->playerHandEdit->setText(karty.join(", "));
}

/**
 * @brief Aktualizuje pole tekstowe z kartami krupiera.
 */
void blackokno::pokazRekeKrupiera(bool pokazWszystkie) {
    QStringList karty;
    const auto& reka = gra->getDealerHand();

    if (reka.isEmpty()) {
        ui->dealerHandEdit->clear();
        return;
    }

    bool ukryj = !pokazWszystkie && (gra->getCurrentState() == BlackJack::GameState::PlayerTurn);

    for (int i = 0; i < reka.size(); ++i) {
        if (i == 0 && ukryj) {
            karty.append("X");
        } else {
            karty.append(reka[i].valueString());
        }
    }
    ui->dealerHandEdit->setText(karty.join(", "));
}

/**
 * @brief Resetuje wygląd planszy do gry do stanu początkowego.
 */
void blackokno::resetPlansza() {
    ui->playerHandEdit->clear();
    ui->dealerHandEdit->clear();
    ui->playerScoreLabel->setText("Wynik: 0");
    ui->dealerScoreLabel->setText("Wynik: 0");

    ui->dealerHandEdit->hide();


    ui->stankonta->setText(QString::number(portfel->pobierzSaldo(), 'f', 2) + " $");
    auto v = static_cast<QDoubleValidator*>(const_cast<QValidator*>(ui->betLineEdit->validator()));
    if (v) v->setTop(qMax(v->bottom(), portfel->pobierzSaldo()));
}

/**
 * @brief Włącza/wyłącza przyciski w zależności od stanu gry.
 */
void blackokno::ustawPrzyciski(BlackJack::GameState stan) {
    bool turaGracza = (stan == BlackJack::GameState::PlayerTurn);
    bool moznaDeal = !turaGracza && (stan != BlackJack::GameState::DealerTurn);

    ui->dealButton->setEnabled(moznaDeal);
    ui->hitButton->setEnabled(turaGracza);
    ui->standButton->setEnabled(turaGracza);
    ui->betLineEdit->setEnabled(moznaDeal);
}

/**
 * @brief Slot obsługujący kliknięcie przycisku "RESET".
 */
void blackokno::on_reset_clicked()
{
    portfel->resetuj();
    gra->resetujGre();
}
