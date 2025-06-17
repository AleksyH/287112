/**
 * @file statystykiruletki.h
 * @brief Definicja klasy StatystykiRuletki.
 */

#ifndef STATYSTYKIRULETKI_H
#define STATYSTYKIRULETKI_H

#include "ruletka.h"
#include <QDebug>

/**
 * @class StatystykiRuletki
 * @brief Klasa do śledzenia statystyk dla gry w Ruletkę.
 *
 * Używa mechanizmu przyjaźni do odczytywania wyników z obiektu Ruletka.
 */
class StatystykiRuletki
{
public:
    /**
     * @brief Domyślny konstruktor.
     * Inicjalizuje wszystkie liczniki na zero.
     */
    StatystykiRuletki() : m_wygrane(0), m_przegrane(0), m_bilans(0.0) {}

    /**
     * @brief Aktualizuje statystyki po zakończeniu kręcenia kołem.
     * @param gra Referencja do obiektu gry, z której odczytywane są wyniki.
     */
    void zaktualizujPoZakreceniu(const Ruletka& gra)
    {
        double stawka = gra.m_ostatniaStawka;
        double wygrana = gra.m_ostatniaWygrana;

        if (wygrana > 0) {
            m_wygrane++;
            m_bilans += (wygrana - stawka);
        } else {
            m_przegrane++;
            m_bilans -= stawka;
        }

        qDebug() << "--- Statystyki Ruletki ---";
        qDebug() << "Wygrane:" << m_wygrane << "| Przegrane:" << m_przegrane;
        qDebug() << "Bilans: " << m_bilans << "$";
        qDebug() << "--------------------------";
    }

private:
    int m_wygrane; ///< Licznik wygranych rund.
    int m_przegrane; ///< Licznik przegranych rund.
    double m_bilans; ///< Całkowity bilans finansowy.
};

#endif // STATYSTYKIRULETKI_H
