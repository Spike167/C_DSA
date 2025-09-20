#include <stdio.h>

int binary_search(int array[], int length, int num);  // O(log n)
// int binary_search(int array[], int low, int high, int num);

int main(void)
{
    printf("Binary Search\n");
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(int);
    int num;
    printf("Enter number to search: ");
    if (scanf("%i", &num) != 1)
    {
        printf("could not read input\n");
        return 1;
    }

    int index = binary_search(array, length, num);
    // int index = binary_search(array, 0, length - 1, num);
    if (index == -1)
    {
        printf("Number not found\n");
    }
    else
    {
        printf("Number found at index: %i\n", index);
    }
    return 0;
}


int binary_search(int array[], int length, int num)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (num == array[mid])
        {
            return mid;
        }
        else if (num > array[mid])
        {
            low = mid + 1;
        }
        else if (num < array[mid])
        {
            high = mid - 1;
        }
    }
    return -1;
}


/*
int binary_search(int array[], int low, int high, int num)  // recursive approach
{
    if (low > high)
    {
        return -1;
    }

    int mid  = (low + high) / 2;
    if (num == array[mid])
    {
        return mid;
    }

    if (num > array[mid])
    {
        return binary_search(array, mid + 1, high, num);
    }
    else
    {
        return binary_search(array, low, mid - 1, num);
    }
}
*/
