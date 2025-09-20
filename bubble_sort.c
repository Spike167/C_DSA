#include <stdio.h>

void bubble_sort(int array[], int length);  // O(n^2)

int main(void)
{
    printf("Bubble Sort\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);

    printf("Before: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");

    bubble_sort(array, length);

    printf("After: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
    return 0;
}


void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length -i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] =  array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
