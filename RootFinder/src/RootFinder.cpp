#include "RootFinder.h"
#include <cmath>

namespace {
    bool bad(double v) { return !std::isfinite(v); }
    bool badEps(double e, int it) { return !(e > 0.0) || !std::isfinite(e) || it <= 0; }
}

extern "C" {

    int rf_bisection(RF_Func f, double a, double b, double eps, int maxIter, double* root) {
        if (!f || !root) return RF_ERR_NULL_ARG;
        if (bad(a) || bad(b) || a >= b) return RF_ERR_INVALID_INTERVAL;
        if (badEps(eps, maxIter)) return RF_ERR_BAD_PARAM;

        double fa = f(a), fb = f(b);
        if (bad(fa) || bad(fb)) return RF_ERR_NOT_FINITE;

        if (fa == 0.0) { *root = a; return RF_OK; }
        if (fb == 0.0) { *root = b; return RF_OK; }
        if ((fa < 0.0) == (fb < 0.0)) return RF_ERR_NO_SIGN_CHANGE;

        for (int i = 0; i < maxIter; ++i) {
            double m = a + (b - a) / 2.0;
            double fm = f(m);
            if (bad(fm)) return RF_ERR_NOT_FINITE;
            if (fm == 0.0 || (b - a) / 2.0 < eps) { *root = m; return RF_OK; }
            if ((fm < 0.0) == (fa < 0.0)) { a = m; fa = fm; }
            else { b = m; }
        }
        return RF_ERR_NO_CONVERGENCE;
    }

    int rf_newton(RF_Func f, RF_Func df, double x0, double eps, int maxIter, double* root) {
        if (!f || !df || !root) return RF_ERR_NULL_ARG;
        if (bad(x0) || badEps(eps, maxIter)) return RF_ERR_BAD_PARAM;

        double x = x0;
        for (int i = 0; i < maxIter; ++i) {
            double fx = f(x), dfx = df(x);
            if (bad(fx) || bad(dfx)) return RF_ERR_NOT_FINITE;
            if (dfx == 0.0) return RF_ERR_ZERO_DIVISION;

            double xn = x - fx / dfx;
            if (bad(xn)) return RF_ERR_NOT_FINITE;
            if (std::fabs(xn - x) < eps) { *root = xn; return RF_OK; }
            x = xn;
        }
        return RF_ERR_NO_CONVERGENCE;
    }

    int rf_secant(RF_Func f, double x0, double x1, double eps, int maxIter, double* root) {
        if (!f || !root) return RF_ERR_NULL_ARG;
        if (bad(x0) || bad(x1) || x0 == x1 || badEps(eps, maxIter)) return RF_ERR_BAD_PARAM;

        double xp = x0, xc = x1;
        double fp = f(xp), fc = f(xc);
        if (bad(fp) || bad(fc)) return RF_ERR_NOT_FINITE;

        for (int i = 0; i < maxIter; ++i) {
            if (fc == fp) return RF_ERR_ZERO_DIVISION;
            double xn = xc - fc * (xc - xp) / (fc - fp);
            if (bad(xn)) return RF_ERR_NOT_FINITE;
            if (std::fabs(xn - xc) < eps) { *root = xn; return RF_OK; }
            xp = xc; fp = fc;
            xc = xn; fc = f(xc);
            if (bad(fc)) return RF_ERR_NOT_FINITE;
        }
        return RF_ERR_NO_CONVERGENCE;
    }

    int rf_residual(RF_Func f, double x, double* value) {
        if (!f || !value) return RF_ERR_NULL_ARG;
        if (bad(x)) return RF_ERR_BAD_PARAM;
        double fx = f(x);
        if (bad(fx)) return RF_ERR_NOT_FINITE;
        *value = std::fabs(fx);
        return RF_OK;
    }

} // extern "C"