#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define LENGTH(A)       (sizeof(A) / sizeof(A[0]))

int8_t rebase(int8_t digits[], int16_t input_base, size_t input_length)
{
    int8_t decimal_value = 0;

    for (int8_t i = 0; i < input_length; i++)
    {
        if (digits[i] != 0)
        {
            decimal_value += digits[i] * pow(input_base, (input_length - 1) - i);
            printf("Value = %d\n", decimal_value);
            printf("digits[%d] = %d\n", i, digits[i]);
        }
    }

    return decimal_value;
}

int main(void)
{
    int8_t input1[] = {1, 0, 1, 0, 1, 0};
    int8_t result = rebase(input1, 2, LENGTH(input1));
    printf("Result = %d\n", result);
    printf("-----\n");

    int8_t input2[] = {4, 2};
    result = rebase(input2, 10, LENGTH(input2));
    printf("Result = %d\n", result);

    return 0;
}