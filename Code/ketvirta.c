#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitData(int *arr, int size, int split, int *arr1, int *arr2);
int integer_validation();

int main()
{
    int n, split;
    printf("How many elements in array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = integer_validation();
    }
    printf("\tArray:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d. %d\n", i+1, arr[i]);
    }
    
    printf("At what position would you like to split the array:\n");
    scanf("%d", &split);
    int *arr1 = (int *) calloc(split, sizeof(int));
    int *arr2 = (int *) calloc(n-split, sizeof(int));

    int flag = splitData(arr, n, split, arr1, arr2);
    if (flag == 0)
    {
        printf("First array elements: ");
        for (int i = 0; i < split; ++i)
        {
            printf("%d ", arr1[i]);
        }
        printf("\nSecond array elements: ");
        for (int i = split; i < n; ++i)
        {
            printf("%d ", arr2[i]);
        }
    }
    else
        printf("Inputs are incorrect! Failed to split the array.\n");
    
    return 0;
}

int splitData(int *arr, int size, int split, int *arr1, int *arr2)
{
    if (size > 0 && split > 0 && size > split)
    {
        for (int i = 0; i < split; ++i)
        {
            arr1[i] = arr[i];
        }
        for (int i = split; i < size; ++i)
        {
            arr2[i] = arr[i];
        }
        return 0;
    }
    else
        return -1;
    
}

int integer_validation()
{
    int num;
    while (scanf("%d", &num) == 0 || getchar() != '\n')
    {
        printf("It is not an Integer! Try again:\n");
        while (getchar() != '\n')
            ;
    }
    printf("*Value accepted*\n");
    return num;
}