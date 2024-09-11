#ifndef COUNT_ROOTS
#define COUNT_ROOTS

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "other_func.h"
#include "input_and_output.h"

roots find_roots_quantity(double first_coef_q, double second_coef_q, double third_coef_q);

roots find_roots_linear(double second_coef_l, double third_coef_l);

roots find_roots_final(double first_coef, double second_coef, double third_coef);

#endif