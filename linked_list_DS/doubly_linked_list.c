#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

int insert_node_at_end(node **doubly_linked_list, int data);
int insert_node_at_beginning(node **doubly_linked_list, int data);
int delete_node(node **doubly_linked_list, int data);
int search_node(node **doubly_linked_list, int data);
void display_doubly_linked_list(node **doubly_linked_list);

int main(void)
{
    printf("Doubly Linked List \n");
    node *doubly_linked_list = NULL;
    while (true)
    {
        printf("1. Insert Node at End \n");
        printf("2. Insert Node at Beginning \n");
        printf("3. Delete Node \n");
        printf("4. Search Node \n");
        printf("5. Display/Traverse Doubly Linked List \n");
        printf("Please Select: ");
        int choice;
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input \n");
            return 1;
        }

        if (choice == 1)
        {
            printf("Enter Node data: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int insert_status = insert_node_at_end(&doubly_linked_list, data);
            if (insert_status == 0)
            {
                printf("Node Inserted Successfully \n");
            }
            else
            {
                printf("Node Insertion Failed \n");
            }

            display_doubly_linked_list(&doubly_linked_list);
        }
        else if (choice == 2)
        {
            printf("Enter Node data: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int insert_status = insert_node_at_beginning(&doubly_linked_list, data);
            if (insert_status == 0)
            {
                printf("Node Inserted Successfully \n");
            }
            else
            {
                printf("Node Insertion Failed \n");
            }

            display_doubly_linked_list(&doubly_linked_list);
        }
        else if (choice == 3)
        {
            printf("Enter Node to delete: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int delete_status = delete_node(&doubly_linked_list, data);
            if (delete_status == 0)
            {
                printf("Node Deleted Successfully \n");
            }
            else
            {
                printf("Node Deletion Failed \n");
            }

            display_doubly_linked_list(&doubly_linked_list);
        }
        else if (choice == 4)
        {
            printf("Enter Node to Search: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int search_status = search_node(&doubly_linked_list, data);
            if (search_status == 0)
            {
                printf("Node Found \n");
            }
            else
            {
                printf("Node not found \n");
            }
        }
        else if (choice == 5)
        {
            display_doubly_linked_list(&doubly_linked_list);
        }
        else
        {
            printf("Invalid Choice \n");
            return 1;
        }
    }
    return 0;
}


int insert_node_at_end(node **doubly_linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*doubly_linked_list == NULL)
    {
        *doubly_linked_list = new_node;
        return 0;
    }

    node *current_node = *doubly_linked_list;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
    return 0;
}


int insert_node_at_beginning(node **doubly_linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    new_node->data = data;
    new_node->next = *doubly_linked_list;
    new_node->prev = NULL;

    if (*doubly_linked_list != NULL)
    {
        (*doubly_linked_list)->prev = new_node;
    }

    *doubly_linked_list = new_node;
    return 0;
}


int delete_node(node **doubly_linked_list, int data)
{
    node *current_node = *doubly_linked_list;
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            if (current_node->prev == NULL)
            {
                *doubly_linked_list = current_node->next;
                current_node->next->prev = NULL;
                return 0;
            }
            else if (current_node->next == NULL)
            {
                current_node->prev->next = NULL;
                return 0;
            }
            else
            {
                printf("%i\n", current_node->data);
                printf("%i\n",(current_node->next)->data);
                printf("%i\n", (current_node->prev)->data);
                printf("%i\n", (current_node->prev)->next->data);
                printf("%i\n", (current_node->next)->prev->data);
                (current_node->prev)->next = current_node->next;
                (current_node->next)->prev = current_node->prev;
                return 0;
            }
        }
        current_node = current_node->next;
    }
    return 1;
}


int search_node(node **doubly_linked_list, int data)
{
    node *current_node = *doubly_linked_list;
    while(current_node != NULL)
    {
        if (current_node->data == data)
        {
            return 0;
        }
        current_node = current_node->next;
    }
    return 1;
}


void display_doubly_linked_list(node **doubly_linked_list)
{
    node *current_node = *doubly_linked_list;
    printf("NULL <-> ");
    while (current_node != NULL)
    {
        printf("%i <-> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}
