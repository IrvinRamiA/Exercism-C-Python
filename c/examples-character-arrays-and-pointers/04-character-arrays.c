#include <stdio.h>
#include <string.h>

int main()
{
    char c[] = {'J', 'O', 'H', 'N', '\0'};

    printf("String: %s\n", c);
    printf("Size in bytes = %d\n", sizeof(c));

    int len = strlen(c);

    printf("Length = %d\n", len);

    return 0;
}