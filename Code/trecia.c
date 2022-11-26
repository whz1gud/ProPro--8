#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2);

int main()
{
    int num1, num2;
    printf("Give 2 numbers:\n");
    scanf("%d%d", &num1, &num2);
    printf("Before swap -> %d %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After swap -> %d %d\n", num1, num2);

    return 0;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}