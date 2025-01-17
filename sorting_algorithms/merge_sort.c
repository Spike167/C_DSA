#include <stdio.h>

void merge_sort(int array[], int length);
void merge(int array[], int length, int left_array[], int right_array[]);

int main(void)
{
    printf("Merge Sort \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);\


    merge_sort(array, length);

    printf("[ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("]\n");
    return 0;
}


void merge_sort(int array[], int length)
{
    if (length <= 1)
    {
        return;
    }

    int middle = length / 2;

    int left_array[middle];
    int right_array[length - middle];

    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < middle)
        {
            left_array[i] = array[i];
        }
        else
        {
            right_array[j] = array[i];
            j++;
        }
    }

    merge_sort(left_array, middle);
    merge_sort(right_array, length - middle);

    merge(array, length, left_array, right_array);
}


void merge(int array[], int length, int left_array[], int right_array[])
{
    int left_size = length / 2;
    int right_size = length - left_size;
    int i = 0;
    int l = 0;
    int r = 0;
    while ((l < left_size) && (r < right_size))
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

    while(r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}
