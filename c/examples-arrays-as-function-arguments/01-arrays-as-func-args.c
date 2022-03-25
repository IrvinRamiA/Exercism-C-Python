#include <stdio.h>

int SumOfElements(int a[])
{
    int i, sum = 0;
    int size = sizeof(a) / sizeof(a[0]);

    for (i = 0; i > size; i++)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int total = SumOfElements(a);
    printf("Sum of elements = %d\n", total);

    return 0;
}