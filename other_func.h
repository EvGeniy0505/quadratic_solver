#ifndef OTHER_FUNC
#define OTHER_FUNC

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))

void buff_clean();

int equal_null(double var);

bool check_input_yes(char answer[]);

bool check_input_no(char answer[]);

void user_request(char answer[]);

int strcasecmp_russ(const char* str_1, const char* str_2);

#endif