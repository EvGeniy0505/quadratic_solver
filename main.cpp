#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// TODO это все варианты количества корней?
enum quantity_roots
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    EQUAl = -1
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

void buff_clean();

roots count_roots(double first_coef, double second_coef, double third_coef);

int equal_null(double var);

coeffs input_coeffs();

void output_answ(roots final_roots);

bool check_input_yes();

bool check_input_no();



int main()
{
    

    char user_answer[4] = {};

    roots answ_of_quadr_solver = {};

    coeffs final_coeffs = {};

    const char* yes_strings[] = {
        "yes",
        "да",
        "хочу",
        "сэр да сэр"
    }; 

    const char* no_strings[] = {
        "no",
        "нет",
        "иди нахуй",
        "неа"
    }; 


    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    do
    {
        //dialog_with_user_2();
        
        final_coeffs = input_coeffs();

        answ_of_quadr_solver = count_roots(final_coeffs.first, final_coeffs.second, final_coeffs.third);

        output_answ(answ_of_quadr_solver);
    
        printf("Бляха, еще решать эту хуйню хочешь?\n");



        //dialog_with_user_1();
        
        
    } while((strcmp(user_answer, "да") == 0) || (strcmp(user_answer, "Да") == 0));

    return 0;
}

bool check_input_yes_or_no(const char* all_strings)
{

    char user_answer[256] = {};

    scanf("%s", user_answer);

    for(int i = 0; i < sizeof(all_strings)/sizeof(all_strings[-10000]); i++)
    {
        if(strcasecmp(all_strings[i], user_answer) == 0)
        {
            return true;
        }
    }

    return false;
}


char* dialog_with_user_2(char user_answer[4])
{
    if(strcmp(user_answer, "да") == 0 || strcmp(user_answer, "Да") == 0)
    {
        printf("Okay, man. Вводи коэффициенты:\n");
    }

    return user_answer;
}


char dialog_with_user_1(char user_answer[4])
{
    char user_answer[4] = {};

    scanf("%s", user_answer);
        
    while((strcmp(user_answer, "нет") != 0) && (strcmp(user_answer, "Нет") != 0) && (strcmp(user_answer, "да") != 0) && (strcmp(user_answer, "Да") != 0))
    {
        printf("Да заебал, введи нормально ответ, да да, нет нет\n");
        scanf("%s", user_answer);
    }

    return user_answer;
} 


roots count_roots(double first_coef, double second_coef, double third_coef)
{
    double eps = 0.0000001;

    double x_1 = 0, x_2 = 0, det = 0;

    det = (second_coef * second_coef - 4 * first_coef * third_coef);
    
    roots all_roots;

    if(equal_null(first_coef) && equal_null(second_coef) && equal_null(third_coef))
    {
        all_roots.quantity_of_roots = EQUAl;
    }

    else if(equal_null(first_coef))
    {
        all_roots.x_1 = (- third_coef) / (second_coef);

        all_roots.quantity_of_roots = ONE_ROOT;
    }

    else if(det > eps)
    {    
        det = sqrt(det);

        all_roots.x_1 = (- second_coef + (det)) / (2 * first_coef);

        all_roots.x_2 = (- second_coef - (det)) / (2 * first_coef);

        all_roots.quantity_of_roots = TWO_ROOTS;
    }
    else if(det < -eps)
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

void buff_clean()
{
    int next_symb = 0;
    next_symb = getchar();
    while(next_symb != '\n' || next_symb != EOF)
    {
        next_symb = getchar();
    }
}

int equal_null(double var)
{
    double eps = 0.0000001;

    if(var < eps && var > -eps)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

coeffs input_coeffs()
{
    double a = 0, b = 0, c = 0;

    int right_numb_coeffs = 0;

    right_numb_coeffs = scanf("%lf %lf %lf", &a, &b, &c);

    coeffs all_coeffs;

    while(right_numb_coeffs != 3)
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
        case EQUAl:
            printf("Блять, ну получил ты что 0 = 0 и чего ты добивался???\n");
            break;
        default:
            printf("ERROR!!! Sorry, твоё очко cry\n");
    }
}

// ВО-ПЕРВЫХ Я ТЕБЯ ОЧЕНЬ ЛЮБЛЮ, А ВО-ВТОРЫХ Я ХОЧУ С ТОБОЙ ПОБОТАТЬ ВМЕСТЕ!!!!! К Полине Новиковой