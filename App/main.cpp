#include <iostream>
#include "RootFinder.h"         
#include "FunctionAnalysis.h"   

// Наша піддослідна функція: f(x) = x^2 - 4
double test_func(double x) {
    return x * x - 4.0;
}

// Похідна нашої функції: f'(x) = 2x
double test_deriv(double x) {
    return 2.0 * x;
}

int main() {
    std::cout << "=== Stage 3: Cross-Testing ===" << std::endl;

    // 1. RootFinder (Моя бібліотека)
    double root = 0.0;
    int status_rf = rf_newton(test_func, test_deriv, 3.0, 1e-6, 100, &root);

    if (status_rf == 0) {
        std::cout << "[Student A] RootFinder: Found root x = " << root << std::endl;
    }
    else {
        std::cout << "[Student A] RootFinder Error: " << status_rf << std::endl;
    }

    // 2. FunctionAnalysis (Бібліотека напарника)
    double min_x = 0.0;
    double min_val = 0.0;
    int status_fa = fa_findMinimum(test_func, -5.0, 5.0, 1e-6, 100, &min_x, &min_val);

    if (status_fa == 0) {
        std::cout << "[Student B] FunctionAnalysis: Minimum at x = " << min_x
            << ", f(x) = " << min_val << std::endl;
    }
    else {
        std::cout << "[Student B] FunctionAnalysis Error: " << status_fa << std::endl;
    }

    return 0;
}