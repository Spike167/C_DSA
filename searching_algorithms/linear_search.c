#include <stdio.h>

int linear_search(int array[], int length, int number);

int main(void)
{
    printf("Linear Search \n");
    int array[11] = {25, 7, 16, 88, 69, 91, 70, 2025, 2000, 101, 501};
    int length = sizeof(array) / sizeof(int);
    printf("Enter number to search: ");
    int number;
    if (scanf("%i", &number) != 1)
    {
        printf("could not read input \n");
        return 1;
    }

    int index = linear_search(array, length, number);
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

int linear_search(int array[], int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }
    return -1;
}
