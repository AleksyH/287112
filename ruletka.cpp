/**
 * @file ruletka.cpp
 * @brief Implementacja klasy Ruletka.
 */

#include "ruletka.h"
#include <QRandomGenerator>
#include <QDebug>

Ruletka::Ruletka(Portfel* portfel, QObject *parent)
    : Gra(portfel, parent), m_ostatniaStawka(0.0), m_ostatniaWygrana(0.0)
{
    qDebug() << "Konstruktor Ruletka: tworzenie obiektu gry.";
    inicjalizujPolaRuletki();
}

Ruletka::~Ruletka()
{
    qDebug() << "Destruktor Ruletka: niszczenie obiektu gry.";
}

QString Ruletka::getNazwaGry() const
{
    return "Ruletka";
}

void Ruletka::resetujGre()
{
    qDebug() << "Ruletka::resetujGre() wywołane.";
}

void Ruletka::inicjalizujPolaRuletki()
{
    numeryCzerwone = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    numeryCzarne = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
}

int Ruletka::zakrec()
{
    int numer = QRandomGenerator::global()->bounded(0, 37);
    emit koloZakrecone(numer);
    return numer;
}

Ruletka::KolorPola Ruletka::getKolorNumeru(int numer) const
{
    if (numer == 0) return Ruletka::KolorPola::Zielony;
    if (numeryCzerwone.contains(numer)) return Ruletka::KolorPola::Czerwony;
    if (numeryCzarne.contains(numer)) return Ruletka::KolorPola::Czarny;
    return Ruletka::KolorPola::Zielony;
}

bool Ruletka::czyParzysty(int numer) const
{
    return numer != 0 && numer % 2 == 0;
}

bool Ruletka::czyNieparzysty(int numer) const
{
    return numer != 0 && numer % 2 != 0;
}

void Ruletka::sprawdzWygrana(int wylosowanyNumer, const QString& typZakladu, int obstawionyNumer, double stawka)
{
    double wygranaKwota = 0.0;

    if (typZakladu == "Zero") {
        if (wylosowanyNumer == 0) wygranaKwota = stawka * 36.0;
    } else if (typZakladu.startsWith("Numer ")) {
        if (wylosowanyNumer == obstawionyNumer && obstawionyNumer != 0) wygranaKwota = stawka * 36.0;
    } else if (typZakladu == "Czerwone") {
        if (getKolorNumeru(wylosowanyNumer) == Ruletka::KolorPola::Czerwony) wygranaKwota = stawka * 2.0;
    } else if (typZakladu == "Czarne") {
        if (getKolorNumeru(wylosowanyNumer) == Ruletka::KolorPola::Czarny) wygranaKwota = stawka * 2.0;
    } else if (typZakladu == "Parzyste") {
        if (czyParzysty(wylosowanyNumer)) wygranaKwota = stawka * 2.0;
    } else if (typZakladu == "Nieparzyste") {
        if (czyNieparzysty(wylosowanyNumer)) wygranaKwota = stawka * 2.0;
    }

    m_ostatniaStawka = stawka;
    m_ostatniaWygrana = wygranaKwota;

    Ruletka::KolorPola kolorWylosowanego = getKolorNumeru(wylosowanyNumer);
    QString kolorStr;
    switch (kolorWylosowanego) {
    case Ruletka::KolorPola::Czerwony: kolorStr = "Czerwony"; break;
    case Ruletka::KolorPola::Czarny:   kolorStr = "Czarny";   break;
    case Ruletka::KolorPola::Zielony:  kolorStr = "Zielony";  break;
    }


    QString komunikat = QString("Wylosowano: %1 (%2)").arg(wylosowanyNumer).arg(kolorStr);

    emit rundaZakonczona(*this, komunikat);
}
