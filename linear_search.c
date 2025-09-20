#include <stdio.h>

int linear_search(int array[], int length, int num);  // O(n)

int main(void)
{
    printf("Linear Search\n");
    int array[10] = {7, 2, 5, 9, 4, 1, 6, 0, 3, 8};
    int length = sizeof(array) / sizeof(int);
    int num;
    printf("Enter number to search: ");
    if (scanf("%i", &num) != 1)
    {
        printf("could not read input\n");
        return 1;
    }

    int index = linear_search(array, length, num);
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


int linear_search(int array[], int length, int num)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == num)
        {
            return i;
        }
    }
    return -1;
}
