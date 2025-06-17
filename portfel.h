/**
 * @file portfel.h
 * @brief Definicja klasy Portfel, zarządzającej stanem konta gracza.
 */

#ifndef PORTFEL_H
#define PORTFEL_H

#include <QObject>

/**
 * @class Portfel
 * @brief Klasa odpowiedzialna za zarządzanie finansami gracza.
 *
 * Przechowuje aktualne saldo, umożliwia dodawanie i odejmowanie środków
 * oraz emituje sygnał w przypadku zmiany salda.
 */
class Portfel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy Portfel.
     * Inicjalizuje saldo domyślną wartością startową.
     * @param parent Wskaźnik do obiektu nadrzędnego QObject (opcjonalny).
     */
    explicit Portfel(QObject *parent = nullptr);

    /**
     * @brief Pobiera aktualne saldo portfela.
     * @return Wartość salda jako double.
     */
    double pobierzSaldo() const;

    /**
     * @brief Dodaje określoną kwotę do salda.
     * @param kwota Kwota do dodania. Musi być dodatnia.
     * @return `true` jeśli operacja się powiodła, `false` w przeciwnym razie.
     */
    bool dodajPieniadze(double kwota);

    /**
     * @brief Odejmuje określoną kwotę z salda.
     * @param kwota Kwota do odjęcia. Musi być dodatnia i nie większa niż saldo.
     * @return `true` jeśli operacja się powiodła, `false` w przeciwnym razie.
     */
    bool odejmijPieniadze(double kwota);

    /**
     * @brief Resetuje saldo do początkowej wartości.
     */
    void resetuj();

signals:
    /**
     * @brief Sygnał emitowany po każdej zmianie salda.
     * @param noweSaldo Nowa, zaktualizowana wartość salda.
     */
    void saldoZmienione(double noweSaldo);

private:
    /// @brief Prywatne pole przechowujące aktualne saldo gracza.
    double saldo;
};

#endif // PORTFEL_H
