#include "find_roots.h"


// TODO 
// функция большая пиздец, я даже разбираться не хочу
// разбей на функции для квадратного уравнения и для линейного
roots find_roots(double first_coef, double second_coef, double third_coef)
{
    double det = 0;

    det = (second_coef * second_coef - 4 * first_coef * third_coef);

    roots all_roots;

    if(equal_null(first_coef) && equal_null(second_coef) && equal_null(third_coef))
    {
        all_roots.quantity_of_roots = INFINITE_ROOTS;
    }

    else if(equal_null(first_coef))
    {
        all_roots.x_1 = (- third_coef) / (second_coef);

        all_roots.quantity_of_roots = ONE_ROOT;
    }

    else if(det > 0)
    {
        det = sqrt(det);

        all_roots.x_1 = (- second_coef + (det)) / (2 * first_coef);

        all_roots.x_2 = (- second_coef - (det)) / (2 * first_coef);

        all_roots.quantity_of_roots = TWO_ROOTS;
    }
    else if(det < 0)
    {
        all_roots.quantity_of_roots = ZERO_ROOTS;
    }
    else if(equal_null(det))
    {
        all_roots.x_1 = (- second_coef) / (2 * first_coef);

        all_roots.quantity_of_roots = ONE_ROOT;
    }

    return all_roots;
}
