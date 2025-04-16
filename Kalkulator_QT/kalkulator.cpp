#include "kalkulator.h"
#include <cmath>

double kalkulator::add(double a, double b) {
    return a + b;
}

double kalkulator::sub(double a, double b) {
    return a - b;
}

double kalkulator::tim(double a, double b) {
    return a * b;
}

double kalkulator::div(double a, double b) {
    if (b == 0) return 0;
    return a / b;
}

double kalkulator::mod(double a, double b) {
    if (b == 0) return 0;
    return std::fmod(a, b);
}


