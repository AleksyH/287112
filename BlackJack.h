/**
 * @file BlackJack.h
 * @brief Definicja klasy BlackJack oraz struktury Card.
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QVector>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include "gra.h"

class StatystykiGry;

/**
 * @struct Card
 * @brief Struktura reprezentująca pojedynczą kartę do gry.
 */
struct Card {
    /// @brief Enumerator dla koloru karty.
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    /// @brief Enumerator dla figury/wartości karty.
    enum Rank {
        TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING, ACE
    };
    Suit suit; ///< Kolor karty.
    Rank rank; ///< Figura/wartość karty.

    /**
     * @brief Zwraca reprezentację tekstową karty z symbolem koloru.
     * @return QString z wartością i symbolem, np. "K♥".
     */
    QString toString() const;

    /**
     * @brief Zwraca uproszczoną reprezentację wartości karty.
     * @return QString z wartością, np. "K", "A", "10".
     */
    QString valueString() const;

    /**
     * @brief Oblicza wartość punktową karty.
     * @param aceAsEleven Czy as ma być liczony jako 11 (true) czy 1 (false).
     * @return Wartość punktowa karty jako int.
     */
    int value(bool aceAsEleven = true) const;
};

/**
 * @brief Przeciążenie operatora << dla QDebug, umożliwiające łatwe logowanie kart.
 * @param debug Obiekt QDebug.
 * @param card Karta do wylogowania.
 * @return Referencja do obiektu QDebug.
 */
QDebug operator<<(QDebug debug, const Card& card);

/**
 * @class BlackJack
 * @brief Klasa implementująca logikę gry w Blackjacka.
 *
 * Dziedziczy po klasie Gra i implementuje jej wirtualne metody.
 * Zarządza talią kart, rękami gracza i krupiera oraz całym cyklem rozgrywki.
 */
class BlackJack : public Gra
{
    Q_OBJECT
    friend class StatystykiGry; ///< Deklaracja przyjaźni z klasą statystyk.

public:
    /// @brief Enumerator dla stanów gry w Blackjacka.
    enum class GameState {
        PlayerTurn, DealerTurn, PlayerBust, DealerBust,
        PlayerWins, DealerWins, Push, Blackjack, NotStarted, Betting
    };
    Q_ENUM(GameState)

    explicit BlackJack(Portfel *portfel, QObject *parent = nullptr);
    ~BlackJack() override;

    QString getNazwaGry() const override;
    void resetujGre() override;

    void startGame(double betAmount);
    void playerHit();
    void playerStand();

    const QVector<Card>& getPlayerHand() const;
    const QVector<Card>& getDealerHand() const;
    int getPlayerScore() const;
    int getDealerScore(bool revealAll = false) const;
    GameState getCurrentState() const;
    double getCurrentBet() const;

signals:
    void gameStateChanged(BlackJack::GameState newState, const QString& message = "");
    void playerCardDealt(const Card& card);
    void dealerCardDealt(const Card& card, bool hidden);
    void scoresUpdated(int playerScore, int dealerScore);
    void dealerRevealedCard(const Card& card);
    void graZakonczona(const BlackJack& gra);

private:
    void createDeck();
    void shuffleDeck();
    Card dealCard();
    int calculateHandValue(const QVector<Card>& hand) const;
    void dealerPlay();
    void determineWinner();
    void zakonczRozdanie(GameState finalState, const QString& message);

    QVector<Card> deck; ///< Talia kart używana w grze.
    QVector<Card> playerHand; ///< Ręka gracza.
    QVector<Card> dealerHand; ///< Ręka krupiera.
    double m_currentBet; ///< Aktualna stawka w rozdaniu.
    GameState m_currentState; ///< Aktualny stan gry.
};
#endif // BLACKJACK_H
