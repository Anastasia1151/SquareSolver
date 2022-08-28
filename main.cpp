#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "./tests/tests.h"
#include "./double_cmp/double_cmp.h"
#include "./solveSquare/solvesquare.h"
#include "./oneTest/onetest.h"

/*!
 * \brief inputCheckCoefficients: производит ввод коэффициентов с клавиатуры с последующей их проверкой на числа
 * \return введённый коэффициент
 */
double inputCheckCoefficients(char);

/*!
 * \brief testFromFile: открывает файл, читает из него параметры для проверки,
 * тестирует функцию  решения квадратного уравнения, закрывает файл
 */
void testFromFile();

/*!
 * \brief compRoots: осуществляет ввод коэффициентов и выводит кол-во корней и их значения
 */
void compRoots();

int main()
{
    compRoots();
    while (true){
        printf("Если хотите закончить, нажмите 0\n"
               "если хотите осуществить тестирование программы, нажмите 1\n"
               "если хотите выполнить тестирование программы с данными из файла, нажмите 2\n"
               "если продолжить - любой другой символ\n");
        int startx = 0;
        scanf("%d", &startx);
        if (startx == 0)
            break;
        else if (startx == 1) tests();
        else if (startx == 2) testFromFile();
        else compRoots();
    }
    return 0;
}

double inputCheckCoefficients(char coef_name){
    printf("%c = ", coef_name);
    double coef = 0;
    char just_for_error[10] = {};
    int check = scanf("%lf", &coef);
    while (check != 1) {
        printf("Ошибка ввода, попробуйте ещё раз\n%c = ", coef_name);
        scanf("%s", just_for_error);
        check = scanf("%lf", &coef);
    }
    return coef;
}

void testFromFile() {
    FILE *file = NULL;

    if ( (file = fopen("../test.txt", "r")) == NULL ){
        printf("Ошибка при открытии файла\n");
    }

    double a = 0, b = 0, c = 0, real_x1 = 0, real_x2 = 0;
    int real_nRoots = 0, number_of_test = 0;

    for ( int i = 1; i <= 1; i++ ){
        fscanf(file, "%lg %lg %lg %d %lg %lg %d", &a, &b, &c, &real_nRoots, &real_x1, &real_x2, &number_of_test);

        oneTest(a, b, c,  real_nRoots, real_x1, real_x2, number_of_test);
    }

    fclose(file);
}

void compRoots(){
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("Введите коэффициенты квадратного уравнения: \n");
    a = inputCheckCoefficients('a');
    b = inputCheckCoefficients('b');
    c = inputCheckCoefficients('c');
    int result = solveSquare(a, b, c, &x1, &x2);
    switch(result){
        case NO_ROOTS:
            printf("Корней нет\n");
            break;
        case ONE_ROOT:
            printf("Один корень: x = %.2f\n", x1);
            break;
        case TWO_ROOTS:
            printf("Два корня: \nx1 = %.2f\nx2 = %.2f\n", x1, x2);
            break;
        case SS_INF_NROOTS:
            printf("Бесконечно много корней\n");
            break;
        default:
            printf("Внутренняя ошибка программы\n");
    }
}
