#include <stdio.h>
#include <stdlib.h>

static char **make_diamond(const char letter)
{
    unsigned char length = 2 * (letter - 'A') + 1;
    unsigned char middle_index = length / 2;

    char **diamond = (char **)malloc(length * sizeof(char *));

    for (unsigned char i = 0; i < length; i++)
    {
        diamond[i] = (char *)malloc(length * sizeof(char));
    }

    for (unsigned char i = 0; i < length; i++)
    {
        for (unsigned char j = 0; j < length; j++)
        {
            diamond[i][j] = ' ';
        }
    }

    for (unsigned char i = 0; i < middle_index; i++)
    {
        for (unsigned char j = 0; j < length; j++)
        {
            if (j == middle_index + i || j == middle_index - i)
            {
                diamond[i][j] = 'A' + i;
            }
        }
    }

    return diamond;
}

int main(void)
{
    char **diamond = make_diamond('D');

    for (unsigned char i = 0; i < 3 + 1; i++)
    {
        for (unsigned char j = 0; j < 6; j++)
        {
            printf("%c", diamond[i][j]);
        }
        printf("\n");
    }

    return 0;
}