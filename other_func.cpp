#include "other_func.h"


bool check_input_yes_or_no(const char* all_strings, char answer[256])
{
    for(int i = 0; i < sizeof(all_strings)/sizeof(all_strings[-10000]); i++)
    {
        if(strcasecmp(&all_strings[i], answer) == 0)
        {
            return true;
        }
    }

    return false;
}




void buff_clean()
{
    int next_symb = 0;

    next_symb = getchar();

    while(next_symb != '\n' && next_symb != EOF)
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