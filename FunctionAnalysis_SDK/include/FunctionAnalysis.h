#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(FUNCTIONANALYSIS_STATIC)
#ifdef FUNCTIONANALYSIS_EXPORTS
#define FUNCTIONANALYSIS_API __declspec(dllexport)
#else
#define FUNCTIONANALYSIS_API __declspec(dllimport)
#endif
#else
#define FUNCTIONANALYSIS_API
#endif

    enum {
        FA_OK = 0,
        FA_ERR_NULL_ARG = 1,
        FA_ERR_INVALID_INTERVAL = 2,
        FA_ERR_BAD_PARAM = 3,
        FA_ERR_NO_CONVERGENCE = 4,
        FA_ERR_NOT_FINITE = 5
    };

    typedef double (*FA_Func)(double);

    FUNCTIONANALYSIS_API int fa_evaluate(FA_Func f, double x, double* result);
    FUNCTIONANALYSIS_API int fa_derivative(FA_Func f, double x, double h, double* result);
    FUNCTIONANALYSIS_API int fa_findMinimum(FA_Func f, double a, double b, double eps, int maxIter, double* xExt, double* fExt);
    FUNCTIONANALYSIS_API int fa_findMaximum(FA_Func f, double a, double b, double eps, int maxIter, double* xExt, double* fExt);

#ifdef __cplusplus
}
#endif