#include <iostream>
#include <windows.h> // Бібліотека Windows для ручного завантаження DLL

// Наша піддослідна функція: f(x) = x^2 - 4
double test_func(double x) {
    return x * x - 4.0;
}

// Створюємо "креслення" (тип) для функції напарника, щоб програма знала, як її викликати
typedef int (*FA_FIND_MIN)(double(*)(double), double, double, double, int, double*, double*);

int main() {
    std::cout << "=== Stage 3: Explicit Linking (LoadLibrary) ===" << std::endl;

    // 1. Завантажуємо DLL напарника вручну з папки, де лежить наша програма
    HMODULE hLib = LoadLibraryA("FunctionAnalysis.dll");

    // Перевіряємо, чи успішно завантажилась бібліотека
    if (hLib == NULL) {
        std::cout << "Error: Could not load FunctionAnalysis.dll!" << std::endl;
        return 1;
    }
    std::cout << "[+] FunctionAnalysis.dll loaded successfully." << std::endl;

    // 2. Шукаємо функцію "fa_findMinimum" всередині завантаженої DLL
    FA_FIND_MIN fa_findMinimum = (FA_FIND_MIN)GetProcAddress(hLib, "fa_findMinimum");

    if (fa_findMinimum == NULL) {
        std::cout << "Error: Could not find function inside DLL!" << std::endl;
        FreeLibrary(hLib);
        return 1;
    }

    // 3. Викликаємо знайдену функцію (шукаємо мінімум на відрізку від -5 до 5)
    double min_x = 0.0;
    double min_val = 0.0;
    int status = fa_findMinimum(test_func, -5.0, 5.0, 1e-6, 100, &min_x, &min_val);

    if (status == 0) {
        std::cout << "[Student A] Explicit Result: Minimum at x = " << min_x
            << ", f(x) = " << min_val << std::endl;
    }
    else {
        std::cout << "[Student A] Explicit Error: " << status << std::endl;
    }

    // 4. Очищаємо пам'ять (вивантажуємо DLL)
    FreeLibrary(hLib);
    return 0;
}