#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *convert_number_to_binary_5_bits(unsigned char number)
{
    char *binary_result = (char *)malloc(5 * sizeof(char));
    unsigned char index = 0;
    unsigned char remainder = number % 2;
    unsigned char quotient = number /= 2;
    char temp = ' ';

    memset(binary_result, '0', 5);

    do
    {
        if (remainder == 1)
        {
            binary_result[index++] = '1';
        }
        else
        {
            binary_result[index++] = '0';
        }

        remainder = quotient % 2;
        quotient /= 2;
    } while (quotient != 0);

    if (remainder == 1)
    {
        binary_result[index++] = '1';
    }

    binary_result[index] = '\0';
    /*    for (unsigned char i = 0; i < 5 / 2; i++)
        {
            temp = binary_result[i];
            binary_result[i] = binary_result[5 - i - 1];
            binary_result[5 - i - 1] = temp;
        }*/

    return binary_result;
}

int main(void)
{
    unsigned char number = 8;

    //char *binary = (char *)malloc(5 * sizeof(char));
    char * binary = convert_number_to_binary_5_bits(number);
    printf("%s\n", binary);

    return 0;
}
