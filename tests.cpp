#include <stdio.h>

#include "../solveSquare/solvesquare.h"
#include "../double_cmp/double_cmp.h"
#include "../oneTest/onetest.h"

/*!
 * \brief tests: выполняет проверку программы решения квадратного уравнения, путём передачи ей уже заданных параметров проверки
 */

void tests(){
    //       a  b  c кол-во  x1    x2   №теста
    //               корней
    oneTest( 0, 1,-8,   1,    8,    0,   1);
    oneTest( 1, 0,-4,   2,   -2,    2,   2);
    oneTest( 2, 3, 0,   2,    0, -1.5,   3);
    oneTest( 0, 0, 3,   0,    0,    0,   4);
    oneTest( 0, 5, 0,   1,    0,    0,   5);
    oneTest( 3, 0, 0,   1,    0,    0,   6);
    oneTest( 0, 0, 0,   8,    0,    0,   7);
    oneTest( 1, 5, 6,   2,   -2,   -3,   8);
    oneTest( 1, 2, 1,   1,   -1,    0,   9);
    oneTest( 5, 1, 3,   0,    0,    0,  10);
    oneTest( 2,-6, 3,   2, 2.36, 0.63,  11);
}



