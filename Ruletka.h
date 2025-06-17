/**
 * @file Ruletka.h
 * @brief Definicja klasy Ruletka, implementującej logikę gry.
 */

#ifndef RULETKA_H
#define RULETKA_H

#include <QObject>
#include <QSet>
#include <QString>
#include "gra.h"
#include "portfel.h"

class StatystykiRuletki;

/**
 * @class Ruletka
 * @brief Klasa implementująca logikę gry w Ruletkę.
 *
 * Dziedziczy po klasie Gra. Odpowiada za losowanie numerów, sprawdzanie
 * zakładów i obliczanie wygranych.
 */
class Ruletka : public Gra
{
    Q_OBJECT
    friend class StatystykiRuletki; ///< Deklaracja przyjaźni.
    friend class ruletkaokno; ///< Przyjaźń z GUI do odczytu wyniku.

public:
    /// @brief Enumerator dla kolorów pól na kole ruletki.
    enum class KolorPola {
        Czerwony,
        Czarny,
        Zielony
    };
    Q_ENUM(KolorPola)

    explicit Ruletka(Portfel* portfel, QObject *parent = nullptr);
    ~Ruletka() override;

    QString getNazwaGry() const override;
    void resetujGre() override;

    int zakrec();
    void sprawdzWygrana(int wylosowanyNumer, const QString& typZakladu, int obstawionyNumer, double stawka);
    KolorPola getKolorNumeru(int numer) const;
    bool czyParzysty(int numer) const;
    bool czyNieparzysty(int numer) const;

signals:
    void rundaZakonczona(const Ruletka& gra, const QString& komunikat);
    void koloZakrecone(int numer);

private:
    QSet<int> numeryCzerwone; ///< Zbiór numerów czerwonych.
    QSet<int> numeryCzarne; ///< Zbiór numerów czarnych.
    double m_ostatniaStawka; ///< Stawka z ostatniej rundy.
    double m_ostatniaWygrana; ///< Kwota wygranej z ostatniej rundy.

    void inicjalizujPolaRuletki();
};

#endif // RULETKA_H
