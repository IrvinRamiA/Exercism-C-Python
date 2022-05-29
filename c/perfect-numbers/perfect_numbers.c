#include "perfect_numbers.h"

kind classify_number(int number)
{
    kind result;
    if (number <= 0)
    {
        result = ERROR;
        return result;
    }

    int sum = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    if (sum == number)
    {
        result = PERFECT_NUMBER;
    }
    else if (sum > number)
    {
        result = ABUNDANT_NUMBER;
    }
    else
    {
        result = DEFICIENT_NUMBER;
    }

    return result;
}
