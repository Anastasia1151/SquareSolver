#include <stdio.h>

#include "../double_cmp/double_cmp.h"
#include "../solveSquare/solvesquare.h"
#include "onetest.h"

//@file

/*!
 * \brief oneTest: производит 1 тест программы решения квадратного  уравнения
 * \param [in] a, b, c коэффициенты квадратного уравнения
 * \param real_nRoots действительное/реальное количество корней
 * \param real_x1, real_x2 реальные корни уравнения по заданным коэффициентам
 * \param number_of_test номер теста
 */

void oneTest(double a, double b, double c, int real_nRoots, double real_x1, double real_x2, int number_of_test){
    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    if ( !( nRoots == real_nRoots && ((isZero(x1 -real_x1) && isZero(x2 - real_x2)) || (isZero(x2 -real_x1) && isZero(x1 - real_x2))))){
        printf("Неудачный тест номер %d: кол-во корней = %d, x1 = %lg, x2 = %lg\n"
               "ожидалось: кол-во корней = %d, x1 = %lg, x2 = %lg\n",
               number_of_test, nRoots, x1, x2, real_nRoots, real_x1, real_x2);
    }
    else printf("Тест %d выполнен успешно\n", number_of_test);
}
