# FunctionAnalysis SDK (Студент Б)

Бібліотека для дослідження функцій (пошук екстремумів та похідних) на C.

## Функції (C-interface):
- fa_evaluate: Обчислення значення функції в точці.
- fa_derivative: Наближене обчислення похідної.
- fa_findMinimum: Пошук мінімуму методом золотого перерізу.
- fa_findMaximum: Пошук максимуму методом золотого перерізу.

## Коди помилок (enum):
- 0: FA_OK (Успіх)
- 1: FA_ERR_NULL_ARG (Нульовий вказівник)
- 2: FA_ERR_INVALID_INTERVAL (Некоректний інтервал)
- 3: FA_ERR_BAD_PARAM (Некоректний параметр eps, h або maxIter)
- 4: FA_ERR_NO_CONVERGENCE (Немає збіжності за maxIter)
- 5: FA_ERR_NOT_FINITE (Результат не є скінченним числом)