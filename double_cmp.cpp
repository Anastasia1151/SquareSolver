#include <stdio.h>
#include <math.h>

/*!
 * \brief isZero: сравнивает число с плавающей запятой с нулём
 * \param [in] coef Нужное для сравнения с нулём число
 * \return Возвращает 1, если число равно нулю; иначе - 0
 */
bool isZero(double coef){
    const double DELTA = 0.01;
    if (coef > -DELTA && coef < DELTA) return true;
    else return false;
}
