#include <stdio.h>

void segregateEvenOdd(int *arr, int size)
{
    int even_index = 0;
    int odd_index = size - 1;
    while (even_index <= odd_index)
    {
        if (arr[even_index] % 2 != 0 && arr[odd_index] % 2 == 0)
        {
            int temp = arr[even_index];
            arr[even_index] = arr[odd_index];
            arr[odd_index] = temp;
            even_index++;
            odd_index--;
        }
        else if (arr[even_index] % 2 != 0 && arr[odd_index] % 2 != 0)
        {
            odd_index--;
        }
        else
        {
            even_index++;
        }
    }
}

void main()
{
    int size;
    printf("Enter size of array");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nbefore segregation\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    segregateEvenOdd(arr, size);
    printf("\nAfter segregation\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}