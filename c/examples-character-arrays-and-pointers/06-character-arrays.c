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
    char *c = "Hello";  // String gets stored as compile time constant
    print(c);

    return 0;
}