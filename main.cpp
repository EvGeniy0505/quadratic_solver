#include "input_and_output.h"
#include "find_roots.h"

int main()
{
    roots answ_of_quadr_solver = {};

    const char* yes_strings[] = {
        "yes",
        "да",
        "хочу",
        "сэр да сэр"
    };

    const size_t size_yes_strings = ARRAY_LENGTH(yes_strings);

    const char* no_strings[] = {
        "no",
        "нет",
        "иди нахуй",
        "неа"
    };

    const size_t size_no_strings = ARRAY_LENGTH(no_strings);

    char user_answer[256] = {};

    printf("Hi, man! Введи 3 числа, коэффициентов квадратного уравнения, чтобы у тебя не порвалось очко\n");

    do
    {
        struct coeffs final_coeffs = input_coeffs(); 

        answ_of_quadr_solver = find_roots_final(final_coeffs.first, final_coeffs.second, final_coeffs.third);

        output_answ(answ_of_quadr_solver);

        printf("Бляха, еще решать эту хуйню хочешь?\n");

        buff_clean();

        user_request(user_answer);
        // TODO про check_input_yes_or_no. Очень странные аргументы передаются.
        // сделай отдельно check_input_yes и check_input_no, которые уже будут вызывать вот эту страшную
        // check_input_yes_or_no, и сделай так, чтобы её саму нельзя было вызывать извне. (static)

        // TODO также ты как минимум три раза вызываешь эту довольно дорогую функицию
        // попробуй её вызывать только, если надо
        while(!check_input_yes_or_no(no_strings,  user_answer, size_no_strings) &&
              !check_input_yes_or_no(yes_strings, user_answer, size_yes_strings))
        {
            printf("Да заебал, введи нормально ответ, да да, нет нет\n");

            user_request(user_answer);
        }

        if(check_input_yes_or_no(yes_strings, user_answer, size_yes_strings))
        {
            printf("Okay, man. Вводи коэффициенты:\n");
        }

    } while(check_input_yes_or_no(yes_strings, user_answer, size_yes_strings));

    printf("Пиздец люблю Полину Новикову и котиков\n");

    return 0;
}
