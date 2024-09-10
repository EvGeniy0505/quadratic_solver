#include "other_func.h"


bool check_input_yes_or_no(const char* all_strings[], char answer[], size_t quantity_of_strs)
{
    for(size_t i = 0; i < quantity_of_strs; i++)
    {
        if(strcasecmp(all_strings[i], answer) == 0)   // TODO написать свою
        {
            return true;
        }
    }

    return false;
}






void buff_clean()
{
    int next_symb = getchar();

    while(next_symb != '\n' && next_symb != EOF)
    {
        next_symb = getchar();
    }
}


int equal_null(double var)
{
    double eps = 0.0000001;

    if(abs(var) < eps)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void user_request(char answer[])
{
    fgets(answer, 256, stdin);

    int i = 0;

    while(answer[i] != '\n' && answer[i] != '\0' && answer[i] != EOF)
    {
        i++;
    }

    if(answer[i] == '\n' && answer[i] != '\0' && answer[i] != EOF)
    {
        answer[i] = '\0';
    }
}
