#include "other_func.h"


bool check_input_yes_or_no(const char* all_strings[], char answer[], size_t quantity_of_strs)
{
    for(size_t i = 0; i < quantity_of_strs; i++)
    {
        if(strcasecmp_russ(all_strings[i], answer) == 0)  
        {
            return true;
        }
    }
    return false;
}


int strcasecmp_russ(const char* str_1, const char* str_2)
{
    while(((*str_1 == *str_2) || (abs(*str_1 - *str_2) == 32)) && *str_1 && *str_2)
    {
        str_1++;
        str_2++;

        if(*str_2 == '\0')
        {
            return 0;
        }
    }

    return *str_1 - *str_2;
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
