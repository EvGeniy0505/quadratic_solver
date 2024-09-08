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

    size_t size_yes_strings = sizeof(yes_strings) / sizeof(yes_strings[0]);

    const char* no_strings[] = {
        "no",
        "нет",
        "иди нахуй",
        "неа"
    }; 

    size_t size_no_strings = sizeof(no_strings) / sizeof(no_strings[0]);

    char user_answer[256] = {};

    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    do
    {
        if(check_input_yes_or_no(yes_strings, user_answer, size_yes_strings))
        {
            printf("Okay, man. Вводи коэффициенты:\n");
        }

        
        final_coeffs = input_coeffs();

        answ_of_quadr_solver = count_roots(final_coeffs.first, final_coeffs.second, final_coeffs.third);

        output_answ(answ_of_quadr_solver);
    
        printf("Бляха, еще решать эту хуйню хочешь?\n");

        buff_clean();

        fgets(user_answer, 256, stdin);

        delete_line_break(user_answer);

        while(!check_input_yes_or_no(no_strings,  user_answer, size_no_strings) &&
              !check_input_yes_or_no(yes_strings, user_answer, size_yes_strings))
        {
            printf("Да заебал, введи нормально ответ, да да, нет нет\n");

            fgets(user_answer, 256, stdin);

            delete_line_break(user_answer);
        }
        

    } while(check_input_yes_or_no(yes_strings, user_answer, size_yes_strings));

    printf("Пиздец люблю Полину Новикову и котиков\n");

    return 0;
}
