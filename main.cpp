#include "input_and_output.h"
#include "find_roots.h"

int main()
{
    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    char user_answer[256] = {};

    do
    {
        struct coeffs final_coeffs = input_coeffs(); 

        struct roots answ_of_quadr_solver = find_roots_final(final_coeffs.first, final_coeffs.second, final_coeffs.third);

        output_answ(answ_of_quadr_solver);

        printf("Бляха, еще решать эту хуйню хочешь?\n");

        user_request(user_answer);

        while(!check_input_yes(user_answer) &&
              !check_input_no (user_answer))
        {
            printf("Да заебал, введи нормально ответ, да да, нет нет\n");

            user_request(user_answer);
        }

        if(check_input_yes(user_answer))
        {
            printf("Okay, man. Вводи коэффициенты:\n");
        }
        
    } while(check_input_yes(user_answer));

    printf("Пиздец люблю Полину Новикову и котиков\n");

    return 0;
}
