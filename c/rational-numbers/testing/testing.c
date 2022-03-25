#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "rational_numbers.h"

static int8_t maximum_common_divisor(rational_t r)
{
    int16_t mcd = 0;
    int16_t mod = 0;
    int16_t current_num = 0;
    int16_t current_den = 0;

    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);

    if (r.numerator > r.denominator)
    {
        current_num = r.numerator;
        current_den = r.denominator;
    }
    else
    {
        current_num = r.denominator;
        current_den = r.numerator;
    }

    do
    {
        mod = current_num % current_den;
        if (mod == 0)
        {
            mcd = current_den;
        }
        current_num = current_den;
        current_den = mod;
    } while (mod != 0);

    return mcd;
}

int main(void)
{
    rational_t r = {72, 16};
    int16_t result = maximum_common_divisor(r);
    printf("Result = %d\n", result);
    
    rational_t r2 = {16, 72};
    int16_t result2 = maximum_common_divisor(r2);
    printf("Result2 = %d\n", result2);

    rational_t r3 = {656, 848};
    int16_t result3 = maximum_common_divisor(r3);
    printf("Result = %d\n", result3);
    
    rational_t r4 = {848, 656};
    int16_t result4 = maximum_common_divisor(r4);
    printf("Result2 = %d\n", result4);

    rational_t r5 = {1728, 842};
    int16_t result5 = maximum_common_divisor(r5);
    printf("Result = %d\n", result5);
    
    rational_t r6 = {842, 1728};
    int16_t result6 = maximum_common_divisor(r6);
    printf("Result2 = %d\n", result6);
    return 0;
}