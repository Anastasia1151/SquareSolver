#include <stdio.h>
#include <math.h>

#include "solvesquare.h"
#include "../double_cmp/double_cmp.h"
#include "../oneTest/onetest.h"

/*!
 * \brief solveSquare: решает квадратное уравнение
 * \param [in] a, b, c коэффициенты квадратного уравнения
 * \param [out] x1, x2 корни квадратного уравнения
 * \return количество корней (нет корней, 1 корень, 2 корня, бесконечное количество корней)
 */

int solveSquare(double a, double b, double c, double* x1, double* x2){
    double d = b*b - 4*a*c;

    if (isZero(a) == true){
        if (isZero(b) == true){
            if (isZero(c) == true) return SS_INF_NROOTS;

            else return NO_ROOTS;
        }

        else {
            *x1 = -c / b;
            return ONE_ROOT;
        }
    }

    else if (d < 0) return NO_ROOTS;

    else if (isZero(d) == true){
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }

    else {
        double sqrt_of_discriminant = sqrt(d);
        *x1 = (-b + sqrt_of_discriminant) / (2*a);
        *x2 = (-b - sqrt_of_discriminant) / (2*a);
        return TWO_ROOTS;
    }
}
