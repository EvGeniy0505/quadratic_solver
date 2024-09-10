#ifndef OTHER_FUNC
#define OTHER_FUNC

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buff_clean();

int equal_null(double var);

bool check_input_yes_or_no(const char* all_strings[], char answer[], size_t quantity_of_strs);

void user_request(char answer[]);

#endif