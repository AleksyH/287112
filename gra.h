/**
 * @file gra.h
 * @brief Definicja abstrakcyjnej klasy bazowej dla wszystkich gier w kasynie.
 */

#ifndef GRA_H
#define GRA_H

#include "portfel.h"
#include <QString>
#include <QObject>

/**
 * @class Gra
 * @brief Abstrakcyjna klasa bazowa definiująca wspólny interfejs dla wszystkich gier.
 *
 * Klasa ta wymusza na klasach pochodnych implementację podstawowych metod,
 * takich jak pobieranie nazwy gry i resetowanie jej stanu. Umożliwia to
 * polimorficzne traktowanie różnych gier w aplikacji.
 */
class Gra : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy Gra.
     * @param portfel Wskaźnik do obiektu Portfel, który będzie współdzielony przez grę.
     * @param parent Wskaźnik do obiektu nadrzędnego QObject (opcjonalny).
     */
    explicit Gra(Portfel *portfel, QObject *parent = nullptr)
        : QObject(parent), m_portfel(portfel) {}

    /**
     * @brief Wirtualny destruktor.
     * Zapewnia poprawne niszczenie obiektów klas pochodnych.
     */
    virtual ~Gra() {}

    /**
     * @brief Czysto wirtualna metoda do pobierania nazwy gry.
     * @return Nazwa gry jako QString.
     *
     * Każda klasa dziedzicząca po Gra musi zaimplementować tę metodę.
     */
    virtual QString getNazwaGry() const = 0;

    /**
     * @brief Czysto wirtualna metoda do resetowania stanu gry.
     *
     * Każda klasa dziedzicząca po Gra musi zaimplementować tę metodę,
     * aby przywrócić grę do stanu początkowego.
     */
    virtual void resetujGre() = 0;

protected:
    /// @brief Wskaźnik do współdzielonego obiektu portfela.
    Portfel* m_portfel;
};

#endif // GRA_H
