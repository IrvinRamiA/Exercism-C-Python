#include <stdio.h>
#include <string.h>

int main()
{
    char c[] = "JOHN";

    printf("String: %s\n", c);
    printf("Size in bytes = %d\n", sizeof(c));

    int len = strlen(c);

    printf("Length = %d\n", len);

    return 0;
}