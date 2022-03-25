#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

enum
{
    ZERO = 0,
    ONE,
    TEN = 10
};

static uint32_t power(uint8_t base, uint8_t exponent)
{
    uint32_t result = ONE;

    for (uint8_t i = ZERO; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

bool is_armstrong_number(uint32_t candidate)
{
    if (candidate <= ZERO)
    {
        return ONE;
    }

    uint32_t copy_candidate = candidate;
    uint8_t number_of_digits = log10(candidate) + 1;
    uint32_t sum = ZERO;

    for (uint8_t i = ZERO; i < number_of_digits; i++)
    {
        sum += power(copy_candidate % TEN, number_of_digits); // (last_digit) ^ (number_of_digits)
        copy_candidate = (uint32_t)(copy_candidate / TEN);    // Advance to next digit from left to right
    }

    return candidate == sum;
}

int main(void)
{
    clock_t start = clock();
    printf("Armstrong number %d\n", is_armstrong_number(9926315));

    sleep(1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // in seconds

    printf("time program took %f seconds to execute \n", time_taken);

    return 0;
}
