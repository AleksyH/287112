/**
 * @file statystykiblackjack.h
 * @brief Definicja klasy StatystykiGry dla Blackjacka.
 */

#ifndef STATYSTYKIBLACKJACK_H
#define STATYSTYKIBLACKJACK_H

#include "blackjack.h"
#include <QDebug>

/**
 * @class StatystykiGry
 * @brief Klasa do śledzenia statystyk dla gry w Blackjacka.
 *
 * Używa mechanizmu przyjaźni do odczytywania wyników bezpośrednio
 * z obiektu logiki gry BlackJack.
 */
class StatystykiGry
{
public:
    /**
     * @brief Domyślny konstruktor.
     * Inicjalizuje wszystkie liczniki na zero.
     */
    StatystykiGry() : m_wygrane(0), m_przegrane(0), m_lacznaWygrana(0.0) {}

    /**
     * @brief Aktualizuje statystyki po zakończeniu rozdania w Blackjacku.
     * @param gra Referencja do obiektu gry, z której odczytywane są wyniki.
     */
    void zaktualizujPoGrze(const BlackJack& gra)
    {
        auto stan = gra.m_currentState;
        double stawka = gra.m_currentBet;

        if (stan == BlackJack::GameState::PlayerWins ||
            stan == BlackJack::GameState::Blackjack ||
            stan == BlackJack::GameState::DealerBust)
        {
            m_wygrane++;
            m_lacznaWygrana += (stan == BlackJack::GameState::Blackjack) ? (stawka * 1.5) : stawka;
        }
        else if (stan == BlackJack::GameState::DealerWins || stan == BlackJack::GameState::PlayerBust)
        {
            m_przegrane++;
            m_lacznaWygrana -= stawka;
        }

        qDebug() << "--- Statystyki Blackjack ---";
        qDebug() << "Wygrane:" << m_wygrane << "| Przegrane:" << m_przegrane;
        qDebug() << "Bilans: " << m_lacznaWygrana << "$";
        qDebug() << "--------------------------";
    }

private:
    int m_wygrane; ///< Licznik wygranych rund.
    int m_przegrane; ///< Licznik przegranych rund.
    double m_lacznaWygrana; ///< Całkowity bilans finansowy.
};
#endif // STATYSTYKIBLACKJACK_H
