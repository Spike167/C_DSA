#include <stdio.h>

void insertion_sort(int array[], int length);

int main(void)
{
    printf("Insertion Sort \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);

    insertion_sort(array, length);

    printf("[ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("]\n");
    return 0;
}


// insertion sort in ascending order
void insertion_sort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}


// insertion sort in descending order
/*
void insertion_sort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp > array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
*/
