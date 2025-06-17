/**
 * @file portfel.cpp
 * @brief Implementacja klasy Portfel.
 */

#include "portfel.h"

Portfel::Portfel(QObject *parent)
    : QObject(parent), saldo(10000.0)
{
}

double Portfel::pobierzSaldo() const
{
    return saldo;
}

bool Portfel::dodajPieniadze(double kwota)
{
    if (kwota > 0) {
        saldo += kwota;
        emit saldoZmienione(saldo);
        return true;
    }
    return false;
}

bool Portfel::odejmijPieniadze(double kwota)
{
    if (kwota > 0 && saldo >= kwota) {
        saldo -= kwota;
        emit saldoZmienione(saldo);
        return true;
    }
    return false;
}

void Portfel::resetuj()
{
    saldo = 10000.0;
    emit saldoZmienione(saldo);
}
