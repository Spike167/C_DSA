#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


#define stack_size 7

bool is_stack_full(int size);
bool is_stack_empty(int size);
int push(node **stack, int num, int size);
int pop(node **stack, int size);
int peek(node **stack);
void display_stack(node **stack);

int main(void)
{
    printf("Stack Data Structure \n");
    int size = 0;
    node *stack = NULL;
    while (true)
    {
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Stack Info \n");
        printf("5. Display Stack \n");
        printf("Please Select: ");
        int choice;
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input \n");
            return 1;
        }

        if (choice == 1)
        {
            printf("Enter number: ");
            int num;
            if (scanf("%i", &num) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int push_status = push(&stack, num, size);
            if (push_status == 0)
            {
                printf("Number Pushed in stack successfully \n");
                size++;
            }
            else
            {
                printf("Pushing number in stack Failed \n");
            }

            display_stack(&stack);
        }
        else if (choice == 2)
        {
            int pop_status = pop(&stack, size);
            if (pop_status == 0)
            {
                printf("Number popped successfully \n");
                size--;
            }
            else
            {
                printf("Number Popping Failed \n");
            }

            display_stack(&stack);

        }
        else if (choice == 3)
        {
            int elem = peek(&stack);
            if (elem == -1)
            {
                printf("Stack Empty \n");
            }
            else
            {
                printf("Top Element in Stack: %i\n", elem);
            }
        }
        else if (choice == 4)
        {
            printf("Stack Capacity: %i\n", stack_size);
            printf("Stack Size: %i\n", size);

            char *empty;
            if (is_stack_empty(size))
            {
                empty = "true";
            }
            else
            {
                empty = "false";
            }
            printf("Stack Empty: %s\n", empty);

            char *full;
            if (is_stack_full(size))
            {
                full = "true";
            }
            else
            {
                full = "false";
            }
            printf("Stack Full: %s\n", full);
        }
        else if (choice == 5)
        {
            display_stack(&stack);
        }
        else
        {
            printf("Invalid Choice \n");
            return 1;
        }
    }
    return 0;
}


bool is_stack_full(int size)
{
    if (size == stack_size)
    {
        return true;
    }
    return false;
}


bool is_stack_empty(int size)
{
    if (size == 0)
    {
        return true;
    }
    return false;
}


int push(node **stack, int num, int size)
{
    if (is_stack_full(size) == true)
    {
        printf("Stack Full \n");
        return 1;
    }

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    new_node->data = num;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
        return 0;
    }

    node *current_node = *stack;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return 0;
}


int pop(node **stack, int size)
{
    if (is_stack_empty(size) == true)
    {
        printf("Stack Empty \n");
        return 1;
    }

    node *current_node = *stack;
    node *prev_node = NULL;
    while (current_node->next != NULL)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node == NULL)
    {
        *stack = NULL;
        return 0;
    }

    prev_node->next = NULL;
    return 0;
}


int peek(node **stack)
{
    if (*stack == NULL)
    {
        return -1;
    }

    node *current_node = *stack;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    return current_node->data;
}


void display_stack(node **stack)
{
    printf("[ ");
    node *current_node = *stack;
    while(current_node != NULL)
    {
        printf("%i ", current_node->data);
        current_node = current_node->next;
    }
    printf(" <-- top \n");
}
