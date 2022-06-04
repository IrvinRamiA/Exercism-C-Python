#include "all_your_base.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/*
Input example:
int8_t input[] = {1, 0, 1, 0, 1, 0}; -> 2^5 + 2^3 + 2^1
Output example:
int8_t expected[] = {4, 2};
*/
int8_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, int8_t input_length)
{
    if (input_base <= 0 || output_base <= 1)
    {
        digits[0] = 0;
        return 0;
    }

    int16_t decimal_value = 0;

    /* Conversion from input base to decimal */
    for (int8_t i = 0; i < input_length; i++)
    {
        if (digits[i] < 0 || digits[i] >= input_base)
        {
            digits[0] = 0;
            return 0;
        }
        else if (digits[i] != 0)
        {
            decimal_value += digits[i] * round(pow(input_base, (input_length - 1) - i));
        }
    }

    /* Conversion from decimal to output base */
    int8_t index = 0;
    while (decimal_value != 0)
    {
        digits[index] = decimal_value % output_base;
        decimal_value /= output_base;

        index++;
    }

    /* Reverse output */
    for (int8_t i = 0; i < index / 2; i++)
    {
        int8_t temp = digits[i];
        digits[i] = digits[(index - 1) - i];
        digits[(index - 1) - i] = temp;
    }

    return index;
}
