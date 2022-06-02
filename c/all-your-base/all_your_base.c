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
int64_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, int64_t input_length)
{
    int64_t decimal_value = 0;

    /* Conversion from input base to decimal */
    for (int32_t i = 0; i < input_length; i++)
    {
        if (digits[i] != 0)
        {
            decimal_value += digits[i] * pow(input_base, (input_length - 1) - i);
            printf("Value = %d\n", decimal_value);
            printf("digits[%d] = %d\n", i, digits[i]);
        }
    }

    /* Conversion from decimal to output base */
    int64_t index = 0;
    while (decimal_value != 0)
    {
        digits[index] = decimal_value % output_base;
        decimal_value /= output_base;

        index++;
    }

    /* Reverse output */
    for (int8_t i = 0; i < index / 2; i++)
    {
        int64_t temp = digits[i];
        digits[i] = digits[(index - 1) - i];
        digits[(index - 1) - i] = temp;
    }
    
    return index;
}
