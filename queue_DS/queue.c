#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

#define queue_size 7

bool is_queue_full(int size);
bool is_queue_empty(int size);
int peek(node **queue);
int enqueue(node **queue, int num, int size);
int dequeue(node **queue, int size);
void display_queue(node **queue);

int main(void)
{
    printf("Queue Data Structure \n");
    node *queue = NULL;
    int size = 0;
    while (true)
    {
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Display Queue \n");
        printf("4. Queue Info \n");
        printf("5. Peek \n");
        int choice;
        printf("Please Select: ");
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input \n");
            return 1;
        }

        if (choice == 1)
        {
            printf("Enter Number: ");
            int num;
            if (scanf("%i", &num) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int enq_stat = enqueue(&queue, num, size);
            if (enq_stat == 0)
            {
                printf("Number Enqueued Successfully \n");
                size++;
            }
            else
            {
                printf("Number Enqueueing Failed! \n");
            }

            display_queue(&queue);
        }

        else if (choice == 2)
        {
            int deq_stat = dequeue(&queue, size);
            if (deq_stat == 0)
            {
                printf("Number Removed \n");
                size--;
            }
            else
            {
                printf("Number Removing Failed \n");
            }

            display_queue(&queue);
        }
        else if (choice == 3)
        {
            display_queue(&queue);
        }
        else if (choice == 4)
        {
            printf("Queue Capacity: %i\n", queue_size);
            printf("Queue Size: %i\n", size);
            char *empty;
            if (is_queue_empty(size) == true)
            {
                empty = "true";
            }
            else
            {
                empty = "false";
            }
            printf("Queue Empty: %s\n", empty);
            char *full;
            if (is_queue_full(size) == true)
            {
                full = "true";
            }
            else
            {
                full = "false";
            }
            printf("Queue Full: %s\n", full);
        }
        else if (choice == 5)
        {
            int elem = peek(&queue);
            printf("Element at front of Queue: %i\n", elem);
        }
        else
        {
            printf("Invalid Choice \n");
            return 1;

        }
    }
    return 0;
}


bool is_queue_full(int size)
{
    if (size >= queue_size)
    {
        return true;
    }
    return false;
}


bool is_queue_empty(int size)
{
    if (size <= 0)
    {
        return true;
    }
    return false;
}


int peek(node **queue)
{
    node *current_node = *queue;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    return current_node->data;
}


int enqueue(node **queue, int num, int size)
{
    if (is_queue_full(size) == true)
    {
        printf("Queue Full \n");
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

    if (*queue == NULL)
    {
        *queue = new_node;
        return 0;
    }

    new_node->next = *queue;
    *queue = new_node;
    return 0;
}


int dequeue(node **queue, int size)
{
    if (*queue == NULL)
    {
        printf("Queue Empty \n");
        return 1;
    }

    if (size == 1)
    {
        *queue = NULL;
        return 0;
    }

    node *current_node = *queue;
    node *prev_node = NULL;
    while (current_node->next != NULL)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    prev_node->next = NULL;
    return 0;
}


void display_queue(node **queue)
{
    printf("BEGIN ->[ ");
    node *current_node = *queue;
    while (current_node != NULL)
    {
        printf("%i ", current_node->data);
        current_node = current_node->next;
    }
    printf("]END \n");
}
