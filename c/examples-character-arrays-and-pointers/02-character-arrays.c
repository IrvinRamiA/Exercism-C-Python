#include <stdio.h>
#include <string.h>

int main()
{
    char c[20];
    c[0] = 'J';
    c[1] = 'O';
    c[2] = 'H';
    c[3] = 'N';
    c[4] = '\0';

    printf("Size in bytes = %d\n", sizeof(c));
    int len = strlen(c);
    printf("Length = %d", len);

    return 0;
}