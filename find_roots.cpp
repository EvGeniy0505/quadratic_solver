#include "find_roots.h"



roots find_roots_quantity(double first_coef_q, double second_coef_q, double third_coef_q)
{
    double det = 0;

    det = (second_coef_q * second_coef_q - 4 * first_coef_q * third_coef_q);

    roots q_roots = {};

    if(det > 0)
    {
        det = sqrt(det);

        q_roots.x_1 = (- second_coef_q + (det)) / (2 * first_coef_q);

        q_roots.x_2 = (- second_coef_q - (det)) / (2 * first_coef_q);

        q_roots.quantity_of_roots = TWO_ROOTS;
    }
    else if(det < 0)
    {
        q_roots.quantity_of_roots = ZERO_ROOTS;
    }
    else if(equal_null(det))
    {
        q_roots.x_1 = (- second_coef_q) / (2 * first_coef_q);

        q_roots.quantity_of_roots = ONE_ROOT;
    }

    return q_roots;
}

roots find_roots_linear(double second_coef_l, double third_coef_l)
{
    roots l_roots = {};

    if(equal_null(second_coef_l) && equal_null(third_coef_l))
    {
        l_roots.quantity_of_roots = INFINITE_ROOTS;
    }
    else if(equal_null(second_coef_l))
    {
        l_roots.quantity_of_roots = ZERO_ROOTS;
    }
    else
    {
        l_roots.x_1 = (- third_coef_l) / (second_coef_l);

        l_roots.quantity_of_roots = ONE_ROOT;
    }

    return l_roots;
}

roots find_roots_final(double first_coef, double second_coef, double third_coef)
{
    roots all_roots = {};

    if(equal_null(first_coef))
    {
        all_roots = find_roots_linear(second_coef, third_coef);

        return all_roots;
    }
    else
    {
        all_roots = find_roots_quantity(first_coef, second_coef, third_coef);

        return all_roots;
    }
}
