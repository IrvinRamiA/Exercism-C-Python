#include <stdio.h>

static int get_number_of_digits(int candidate)
{
    int number_of_digits = 0;

    if(candidate < 10)
    {
        return 1;
    }
    else
    {
        number_of_digits++;
        return number_of_digits + get_number_of_digits(candidate / 10);
    }
}

int main()
{
    printf("Number of digits = %d", get_number_of_digits(9999));
    return 0;
}