// Uzduotis 1a:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size, int *newArr);
void generateArray(int data[], int size, int low, int high);

int main()
{
    int size;
    printf("Give size of the new array:\n");
    scanf("%d", &size);
    int *newArr = (int *)calloc(size, sizeof(int));
    int *address = createArray(size, newArr);

    printf("Address of first element in the array: %d\n", address);

    for (int i = 0; i < size; i++)
    {
        printf("Element at position %d = %d\n", i, newArr[i]);
    }

    free(newArr);

    return 0;
}

int *createArray(int size, int *arr)
{
    int low, high;
    printf("Give interval start and end for values:\n");
    scanf("%d%d", &low, &high);
    if (low <= high)
    {
        generateArray(arr, size, low, high);
        return arr;
    }
    return NULL;
}

void generateArray(int *data, int size, int low, int high)
{
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        data[i] = rand() % (high + 1 - low) + low;
    }
}

//Uzduotis 1b:
/*
int *createArray(int size, int *newArr);
void generateArray(int *data, int size, int low, int high);

int main()
{
    int size;
    printf("Give size of the new array:\n");
    scanf("%d", &size);
    int *newArr = (int *)calloc(size, sizeof(int));
    int *address = createArray(size, newArr);

    printf("Address of first element in the array: %d\n", address);

    for (int i = 0; i < size; i++)
    {
        printf("Element at position %d = %d\n", i, *(newArr + i));
    }

    free(newArr);

    return 0;
}

int *createArray(int size, int *arr)
{
    int low, high;
    printf("Give interval start and end for values:\n");
    scanf("%d%d", &low, &high);
    if (low <= high)
    {
        generateArray(arr, size, low, high);
        return arr;
    }
    return NULL;
}

void generateArray(int *data, int size, int low, int high)
{
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        *(data + i) = rand() % (high + 1 - low) + low;
    }
}
*/