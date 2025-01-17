#include <stdio.h>

void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(void)
{
    printf("Quick Sort \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);

    quick_sort(array, 0, length - 1);

    printf("[ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("]\n");
    return 0;
}


void quick_sort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);
}


int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int index = start - 1;

    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            index++;
            int temp = array[index];
            array[index] = array[j];
            array[j] = temp;
        }
    }
    index++;
    array[end] = array[index];
    array[index] = pivot;
    return (index);
}
