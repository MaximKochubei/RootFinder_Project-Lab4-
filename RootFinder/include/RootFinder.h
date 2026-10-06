#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(ROOTFINDER_STATIC)
#ifdef ROOTFINDER_EXPORTS
#define ROOTFINDER_API __declspec(dllexport)
#else
#define ROOTFINDER_API __declspec(dllimport)
#endif
#else
#define ROOTFINDER_API
#endif

    /* Коди повернення */
    enum {
        RF_OK = 0,
        RF_ERR_NULL_ARG = 1,
        RF_ERR_INVALID_INTERVAL = 2,
        RF_ERR_NO_SIGN_CHANGE = 3,
        RF_ERR_NO_CONVERGENCE = 4,
        RF_ERR_BAD_PARAM = 5,
        RF_ERR_NOT_FINITE = 6,
        RF_ERR_ZERO_DIVISION = 7
    };

    typedef double (*RF_Func)(double);

    ROOTFINDER_API int rf_bisection(RF_Func f, double a, double b, double eps, int maxIter, double* root);
    ROOTFINDER_API int rf_newton(RF_Func f, RF_Func df, double x0, double eps, int maxIter, double* root);
    ROOTFINDER_API int rf_secant(RF_Func f, double x0, double x1, double eps, int maxIter, double* root);
    ROOTFINDER_API int rf_residual(RF_Func f, double x, double* value); /* value = |f(x)| */

#ifdef __cplusplus
}
#endif