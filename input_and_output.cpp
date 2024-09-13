#include "input_and_output.h"

static bool buff_check();

coeffs input_coeffs()
{
    double a = 0, b = 0, c = 0;

    int right_numb_coeffs = scanf("%lf %lf %lf", &a, &b, &c);

    printf("%d", right_numb_coeffs);

    struct coeffs all_coeffs = {};

    // TODO когда Ctrl+D бесконечный цикл
    while((right_numb_coeffs != 3 || buff_check()) || (a == EOF) || (b == EOF) || (c == EOF))
    {
        buff_clean();

        printf("Чё за хуйня??? Быстро введи ещё раз нормально коффициенты в одну строку через пробел\n");

        right_numb_coeffs = scanf("%lf %lf %lf", &a, &b, &c);
    }

    all_coeffs.first  = a;
    all_coeffs.second = b;
    all_coeffs.third  = c;

    return all_coeffs;
}

 static bool buff_check()
{
    int symb = getchar();

    while(symb != '\n' && symb != EOF) 
    {
        if(symb != ' ')
        {
            return true;
        }
        symb = getchar();
    }
    return false;
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