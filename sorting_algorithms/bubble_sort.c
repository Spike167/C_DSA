#include <stdio.h>

void bubble_sort(int array[], int length);

int main(void)
{
    printf("Bubble Sort \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);

    bubble_sort(array, length);

    printf("[ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("]\n");
    return 0;
}


// bubble sort in ascending order
void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


// bubble sort in descending order
/*
void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
*/
