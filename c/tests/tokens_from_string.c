#include <string.h>
#include <stdio.h>

int main()
{
    char str[80] = "This 'is' -, www.tutorialspoint.com%website";
    const char *delimiters = " ,.-\n:!!&@$%^&\"";
    char *token;

    /* get the first token */
    token = strtok(str, delimiters);

    /* walk through other tokens */
    while (token != NULL)
    {
        printf("%s\n", token);

        token = strtok(NULL, delimiters);
    }

    return (0);
}