#include <stdio.h>
#include <string.h>

void print(const char *c)
{
    while(*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

int main()
{
    char c[20] = "Hello";   // String gets stored in the space for array
    print(c);

    return 0;
}