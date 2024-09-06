

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

enum quantity_roots
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};


struct roots   
{
    double x_1;
    double x_2;        
};

void buff_clean();

void struct_konstr(double first_root, double second_root);

int how_many_roots(double first_coef, double second_coef, double third_coef);

double count_roots(double first_coef, double second_coef, double third_coef);

int main()
{
    double a = 0, b = 0, c = 0;

    int flag = 0;

    char* user_answer = (char*) calloc(3, sizeof(char));


    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    do
    {
        if(strcmp(user_answer, "да") == 0 || strcmp(user_answer, "Да") == 0)
        {
            printf("Okay, man. Вводи коэффициенты:\n");
        }

        flag = scanf("%lf %lf %lf", &a, &b, &c);

        while(flag != 3)
        {
            buff_clean();

            printf("Чё за хуйня??? Быстро введи ещё раз нормально коффициенты в одну строку через пробел\n");

            flag = scanf("%lf %lf %lf", &a, &b, &c);
            
        }
        switch(how_many_roots(a, b, c))
        {
            case TWO_ROOTS:
                count_roots(a, b, c);
                printf("Не, ну 2 корня у уравнения это заебись\n");
                break;
            case ONE_ROOT:
                printf("%lf\n", count_roots(a, b, c));
                printf("Ура!!! Один корень!!! Ты наконец-то узнал длину своего члена!\n");  
                break;
            case ZERO_ROOTS:
                printf("Корней у уравнения нет нихуя, пошел в пизду, милый друг\n");
                break;
            default:
                printf("ERROR!!! Sorry, твоё очко cry\n");
        }
    
        printf("Бляха, еще решать эту хуйню хочешь?\n");
        scanf("%s", user_answer);
        
        while((strcmp(user_answer, "нет") != 0) && (strcmp(user_answer, "Нет") != 0) && (strcmp(user_answer, "да") != 0) && (strcmp(user_answer, "Да") != 0))
        {
            printf("Да заебал, введи нормально ответ, да да, нет нет\n");
            scanf("%s", user_answer);
        }
        
    } while((strcmp(user_answer, "да") == 0) || (strcmp(user_answer, "Да") == 0));

    return 0;
}


double count_roots(double first_coef, double second_coef, double third_coef)
{
    double eps = 0.0000001;

    double x_1 = 0, x_2 = 0;

    x_1 = (- second_coef + sqrt(second_coef * second_coef - 4 * first_coef * third_coef)) / (2 * first_coef);

    x_2 = (- second_coef - sqrt(second_coef * second_coef - 4 * first_coef * third_coef)) / (2 * first_coef);


    if(abs(x_1 - x_2) < eps)
    {
        return x_1;
    }
    else
    {
        return 1;
    }
}

int how_many_roots(double first_coef, double second_coef, double third_coef)
{
    double det = 0;
    double eps = 0.0000001;

    det = second_coef * second_coef - 4 * first_coef * third_coef;

    if(det > eps)
    {    
        return TWO_ROOTS;
    }
    else if(det < -eps)
    {
        return ZERO_ROOTS;
    }
    else if(det < eps && det > -eps)
    {
        return ONE_ROOT;
    }
    else
    {
        return -1;
    }
}

void buff_clean()
{
    int next_symb = 0;
    next_symb = getchar();
    while(next_symb != '\n')
    {
        next_symb = getchar();
    }
}



//void struct_konstr(double first_root, double second_root)
//{
//    roots quadratic;
//
//    quadratic = {first_root, second_root};
//
//    return quadratic;
//}

