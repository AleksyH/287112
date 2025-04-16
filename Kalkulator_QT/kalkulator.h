#ifndef KALKULATOR_H
#define KALKULATOR_H

class kalkulator {

    bool mem_used = false;

public:
    double add(double a, double b);
    double sub(double a, double b);
    double tim(double a, double b);
    double div(double a, double b);
    double mod(double a, double b);
};

#endif // KALKULATOR_H
