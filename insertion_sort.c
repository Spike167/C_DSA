#include <stdio.h>

void insertion_sort(int array[], int length);  // O(n^2)

int main(void)
{
    printf("Insertion Sort\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);

    printf("Before: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");

    insertion_sort(array, length);

    printf("After:  ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
    return 0;
}


void insertion_sort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[i])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
