#include <stdio.h>
#include <string.h>

void RemoveChars(char *s, char c)
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

int main(void)
{
    char s[16] = "one,\ntwo,\nthree";
    printf("%s\n", s);

    RemoveChars(s, '\n');
    printf("%s\n", s);

    return 0;
}