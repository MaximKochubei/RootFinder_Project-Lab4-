#include <iostream>
#include "RootFinder.h"

static double f(double x) { return x * x - 2.0; }
static double df(double x) { return 2.0 * x; }

int main() {
    double r = 0, res = 0;
    if (rf_bisection(f, 0, 2, 1e-9, 200, &r) == RF_OK)
        std::cout << "bisection: " << r << "\n";
    if (rf_newton(f, df, 1.0, 1e-12, 50, &r) == RF_OK)
        std::cout << "newton: " << r << "\n";
    if (rf_secant(f, 1.0, 2.0, 1e-12, 50, &r) == RF_OK)
        std::cout << "secant: " << r << "\n";
    if (rf_residual(f, r, &res) == RF_OK)
        std::cout << "residual: " << res << "\n";
    return 0;
}