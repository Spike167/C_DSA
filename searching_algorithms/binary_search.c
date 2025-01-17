#include <stdio.h>

//int binary_search(int array[], int number, int low, int high);
int binary_search(int array[], int length, int number);

int main(void)
{
    printf("Binary Search \n");
    int array[11] = {7, 11, 16, 25, 44, 69, 70, 88, 91, 101, 2025};
    int length = sizeof(array) / sizeof(int);
    printf("Enter number to search: ");
    int number;
    if (scanf("%i", &number) != 1)
    {
        printf("could not read input \n");
        return 1;
    }

    //int index = binary_search(array, number, 0, length - 1);
    int index = binary_search(array, length, number);
    if (index == -1)
    {
        printf("Number not found! \n");
    }
    else
    {
        printf("Number found at index: %i\n", index);
    }
    return 0;
}


// Recursive Binary Search
/*
int binary_search(int array[], int number, int low, int high)
{
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (number == array[middle])
        {
            return middle;
        }
        else if (number > array[middle])
        {
            return binary_search(array, number, middle + 1, high);
        }
        else if (number < array[middle])
        {
            return binary_search(array, number, low, middle - 1);
        }
    }
    return -1;
}
*/


// Iterative Binary Search
int binary_search(int array[], int length, int number)
{
    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (number == array[middle])
        {
            return middle;
        }
        else if (number > array[middle])
        {
            low = middle + 1;
        }
        else if (number < array[middle])
        {
            high = middle - 1;
        }
    }
    return -1;
}
