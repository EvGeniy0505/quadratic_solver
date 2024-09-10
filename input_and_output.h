#ifndef INPUT_AND_OUTPUT
#define INPUT_AND_OUTPUT

#include <stdio.h>

#include "other_func.h"

enum quantity_roots
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS = -1
};

struct roots
{
    int quantity_of_roots;
    double x_1;
    double x_2;
};

struct coeffs
{
    double first;
    double second;
    double third;
};



coeffs input_coeffs();

void output_answ(roots final_roots);


#endif