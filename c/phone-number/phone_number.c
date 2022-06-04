#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define PHONE_NUMBER_LEN 10

static void remove_chars_from_string(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader] != c)
        {
            s[writer++] = s[reader];
        }

        reader++;
    }

    s[writer] = 0;
}

static void clean_phone_number(char *phone_number)
{
    for (unsigned char i = 0; i < PHONE_NUMBER_LEN; i++)
    {
        phone_number[i] = '0';
    }
    phone_number[PHONE_NUMBER_LEN] = '\0';
}

char *phone_number_clean(const char *input)
{
    unsigned char len = strlen(input);
    char *local_input = (char *)malloc((len + 1) * sizeof(char));

    if (len <= 9)
    {
        clean_phone_number(local_input);
    }
    else
    {
        strncpy(local_input, input, len);
        local_input[len] = '\0';

        remove_chars_from_string(local_input, '(');
        remove_chars_from_string(local_input, ')');
        remove_chars_from_string(local_input, ' ');
        remove_chars_from_string(local_input, '-');
        remove_chars_from_string(local_input, '.');
        remove_chars_from_string(local_input, '+');

        len = strlen(local_input);

        if (len >= 11)
        {
            if (local_input[0] == '1')
            {
                strncpy(local_input, local_input + 1, 10);
                local_input[10] = '\0';

                if (local_input[0] == '0' || local_input[0] == '1' ||
                    local_input[3] == '0' || local_input[3] == '1')
                {
                    clean_phone_number(local_input);
                }
            }
            else
            {
                clean_phone_number(local_input);
            }
        }
        else if (len == 10)
        {
            unsigned char letter_flag = 0;
            for (unsigned char i = 0; i < 10; i++)
            {
                if (!isdigit(local_input[i]))
                {
                    letter_flag = 1;
                }
            }

            if (local_input[0] == '0' || local_input[0] == '1' ||
                local_input[3] == '0' || local_input[3] == '1' ||
                letter_flag)
            {
                clean_phone_number(local_input);
            }
        }
    }

    return local_input;
}
