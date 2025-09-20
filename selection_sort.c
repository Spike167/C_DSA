#include <stdio.h>

void selection_sort(int array[], int length);  // O(n^2)

int main(void)
{
    printf("Selection Sort\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);

    printf("Before: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");

    selection_sort(array, length);

    printf("After: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
    return 0;
}


void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int  j = i + 1; j <= length; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
