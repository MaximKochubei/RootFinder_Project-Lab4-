#include <iostream>
#include "RootFinder.h"         
#include "FunctionAnalysis.h"   

double test_func(double x) { return x * x - 4.0; }
double test_deriv(double x) { return 2.0 * x; }

int main() {
    std::cout << "=== Stage 3: Cross-Testing (Normal) ===" << std::endl;

    // 1. Тестуємо твою бібліотеку
    double root = 0.0;
    int status_rf = rf_newton(test_func, test_deriv, 3.0, 1e-6, 100, &root);
    if (status_rf == 0) std::cout << "[Student A] RootFinder: Found root x = " << root << std::endl;

    // 2. Тестуємо бібліотеку напарника
    double min_x = 0.0, min_val = 0.0;
    int status_fa = fa_findMinimum(test_func, -5.0, 5.0, 1e-6, 100, &min_x, &min_val);
    if (status_fa == 0) std::cout << "[Student B] FunctionAnalysis: Minimum at x = " << min_x << ", f(x) = " << min_val << std::endl;

    // ---------------------------------------------------------
    // ПУНКТ 6: EDGE CASES (Тестування помилок)
    // ---------------------------------------------------------
    std::cout << "\n=== Point 6: Edge Cases Testing ===" << std::endl;

    // Тест 1: Передаємо пустоту (nullptr) замість функції
    std::cout << "Test 1: Passing nullptr to FunctionAnalysis..." << std::endl;
    int err_null = fa_findMinimum(nullptr, -5.0, 5.0, 1e-6, 100, &min_x, &min_val);
    std::cout << "Result: Error code " << err_null << " (Crash avoided!)" << std::endl;

    // Тест 2: Передаємо неправильний інтервал (від 5 до -5 замість від -5 до 5)
    std::cout << "Test 2: Invalid interval (5.0 to -5.0)..." << std::endl;
    int err_interval = fa_findMinimum(test_func, 5.0, -5.0, 1e-6, 100, &min_x, &min_val);
    std::cout << "Result: Error code " << err_interval << " (Crash avoided!)" << std::endl;

    return 0;
}