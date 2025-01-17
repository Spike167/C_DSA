#include <stdio.h>

void selection_sort(int array[], int length);

int main(void)
{
    printf("Selection Sort \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);

    selection_sort(array, length);

    printf("[ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("]\n");
    return 0;
}


// selection sort in ascending order
void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
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


// selection sort in descending order
/*
void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] > array[min])
            {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
*/
