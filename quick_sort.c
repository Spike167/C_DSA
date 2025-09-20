#include <stdio.h>

void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(void)
{
    printf("Quick Sort\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);

    printf("Before: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");

    quick_sort(array, 0, length - 1);

    printf("After: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
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
    int pivot = end;
    int i = start;
    int j = i - 1;
    while (i < pivot)
    {
        if (array[i] < array[pivot])
        {
            j++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
        i++;
    }
    j++;
    int temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;
    return j;
}
