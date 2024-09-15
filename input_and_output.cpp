#include <ctype.h>

#include "input_and_output.h"

static bool buff_check();

static void buff_clean();

coeffs input_coeffs()
{
    struct coeffs all_coeffs = {};

    int right_numb_coeffs = scanf("%lf %lf %lf", &all_coeffs.first, &all_coeffs.second , &all_coeffs.third);

    while(right_numb_coeffs != 3 || buff_check())
    {
        buff_clean();

        printf("Чё за хуйня??? Быстро введи ещё раз нормально коффициенты в одну строку через пробел\n");

        right_numb_coeffs = scanf("%lf %lf %lf", &all_coeffs.first, &all_coeffs.second , &all_coeffs.third);
    }

    return all_coeffs;
}

void output_answ(roots final_roots)
{
    switch(final_roots.quantity_of_roots)
    {
        case TWO_ROOTS:
            printf("x_1 = %lf, x_2 = %lf\n", final_roots.x_1, final_roots.x_2);
            printf("Не, ну 2 корня у уравнения это заебись\n");
            break;
        case ONE_ROOT:
            printf("x_1 = %lf\n", final_roots.x_1);
            printf("Ура!!! Один корень!!! Ты наконец-то узнал длину своего члена!\n");
            break;
        case ZERO_ROOTS:
            printf("Корней у уравнения нет нихуя, пошел в пизду, милый друг\n");
            break;
        case INFINITE_ROOTS:
            printf("Блять, ну получил ты что 0 = 0 и чего ты добивался??? Корней просто дохуя...\n");
            break;
        default:
            printf("ERROR!!! Sorry, твоё очко cry\n");
    }
}

static void buff_clean()
{
    int next_symb = getchar();

    while(next_symb != '\n' && next_symb != EOF)
    {
        next_symb = getchar();
    }
}

static bool buff_check()
{
    int symb = getchar();

    while(symb != '\n' && symb != EOF) 
    {
        if(!isspace(symb)) 
        {
            return true;
        }
        symb = getchar();
    }
    return false;
}