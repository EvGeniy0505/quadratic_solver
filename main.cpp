#include "input_and_output.h"
#include "count_roots.h"


int main()
{
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

    char user_answer[256] = {"ABOBA"};

    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    do
    {
        if(check_input_yes_or_no(*yes_strings, user_answer))
        {
            printf("Okay, man. Вводи коэффициенты:\n");
        }

        
        final_coeffs = input_coeffs();

        answ_of_quadr_solver = count_roots(final_coeffs.first, final_coeffs.second, final_coeffs.third);

        output_answ(answ_of_quadr_solver);
    
        printf("Бляха, еще решать эту хуйню хочешь?\n");

        scanf("%s", user_answer);

        while(!check_input_yes_or_no(*no_strings, user_answer) && !check_input_yes_or_no(*yes_strings, user_answer))
        {
            printf("Да заебал, введи нормально ответ, да да, нет нет\n");

            scanf("%s", user_answer);
        }
        

    } while(check_input_yes_or_no(*yes_strings, user_answer));

    printf("Пиздец люблю Полину Новикову и котиков\n");

    return 0;
}
