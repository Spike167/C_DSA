#include <stdio.h>

void merge_sort(int array[], int length);         // O(n log n)
void merge(int left_array[], int right_array[], int array[], int length);


int main(void)
{
    printf("Merge Sort\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);

    printf("Before: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");

    merge_sort(array, length);

    printf("After: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
    return 0;
}


void merge_sort(int array[], int length)
{
    if (length <= 1)
    {
        return;
    }
    int mid = length / 2;
    int left_array[mid];
    int right_array[length - mid];

    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < mid)
        {
            left_array[i] = array[i];
        }
        else
        {
            right_array[j] = array[i];
            j++;
        }
    }
    merge_sort(left_array, mid);
    merge_sort(right_array, length - mid);
    merge(left_array, right_array, array, length);
}


void merge(int left_array[], int right_array[], int array[], int length)
{
    int left_size = length / 2;
    int right_size = length - left_size;
    int i = 0, l = 0, r = 0;
    while(l < left_size && r < right_size)
    {
        if (left_array[l] <= right_array[r])
        {
            array[i] = left_array[l];
            i++;
            l++;
        }
        else
        {
            array[i] = right_array[r];
            i++;
            r++;
        }
    }

    while (l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }

    while (r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}
