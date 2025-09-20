#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    int data;
    struct node *next;
} node;


int insert_node_at_beginning(node **singly_linked_list, int data);
int insert_node_at_end(node **singly_linked_list, int data);
int delete_node(node **singly_linked_list, int data);
void traversal(node **singly_linked_list);
int search_node(node **singly_linked_list, int data);


int main(void)
{
    printf("Singly Linked List\n");
    node *singly_linked_list = NULL;
    while (true)
    {
        printf("1. Insert Node at Beginning\n");
        printf("2. Insert Node at End\n");
        printf("3. Delete Node\n");
        printf("4. Traverse/Print Linked List\n");
        printf("5. Search Node\n");
        printf("Please Select: ");
        int choice;
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input\n");
            return 1;
        }

        if (choice == 1)
        {
            int data;
            printf("Enter Node Data: ");
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input\n");
                return 1;
            }
            int status = insert_node_at_beginning(&singly_linked_list, data);
            if (status == 0)
            {
                printf("Node Inserted Successfully\n");
            }
            else
            {
                printf("Node Insertion Failed\n");
            }
        }
        else if (choice == 2)
        {
            int data;
            printf("Enter Node Data: ");
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input\n");
                return 1;
            }
            int status = insert_node_at_end(&singly_linked_list, data);
            if (status == 0)
            {
                printf("Node Inserted Successfully\n");
            }
            else
            {
                printf("Node Insertion Failed\n");
            }
        }
        else if (choice == 3)
        {
            int data;
            printf("Enter Node to Delete: ");
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input\n");
                return 1;
            }
            int status = delete_node(&singly_linked_list, data);
            if (status == 0)
            {
                printf("Node Deleted Successfully\n");
            }
            else
            {
                printf("Node Deletion Failed\n");
            }
        }
        else if (choice == 4)
        {
            traversal(&singly_linked_list);
        }
        else if (choice == 5)
        {
            int data;
            printf("Enter Node to Search: ");
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input\n");
                return 1;
            }

            int found = search_node(&singly_linked_list, data);
            if (found == 0)
            {
                printf("Node Found Successfully\n");
            }
            else
            {
                printf("Node Not Found\n");
            }
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    return 0;
}


int insert_node_at_beginning(node **singly_linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory\n");
        return 1;
    }
    new_node->data = data;

    if (*singly_linked_list == NULL)
    {
        new_node->next = NULL;
        *singly_linked_list = new_node;
        return 0;
    }
    new_node->next = *singly_linked_list;
    *singly_linked_list = new_node;
    return 0;
}


int insert_node_at_end(node **singly_linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory\n");
        return 1;
    }
    new_node->data = data;

    if (*singly_linked_list == NULL)
    {
        new_node->next = NULL;
        *singly_linked_list = new_node;
        return 0;
    }

    node *current_node = *singly_linked_list;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    return 0;
}


int delete_node(node **singly_linked_list, int data)
{
    if (*singly_linked_list == NULL)
    {
        printf("Linked List Empty\n");
        return 1;
    }

    if ((*singly_linked_list)->data == data)
    {
        if ((*singly_linked_list)->next == NULL)
        {
            *singly_linked_list = NULL;
            return 0;
        }
        else
        {
            *singly_linked_list = (*singly_linked_list)->next;
            return 0;
        }
    }

    node *current_node = *singly_linked_list;
    node *prev_node;
    while(current_node != NULL)
    {
        if (current_node->data == data)
        {
            prev_node->next = current_node->next;
            return 0;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    printf("Node to be Deleted not Found\n");
    return 1;
}


void traversal(node **singly_linked_list)
{
    if (*singly_linked_list == NULL)
    {
        printf("Linked List Empty\n");
    }
    node *current_node = *singly_linked_list;
    while (current_node != NULL)
    {
        printf("%i --> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}


int search_node(node **singly_linked_list, int data)
{
    if (*singly_linked_list == NULL)
    {
        printf("Linked List Empty\n");
        return 1;
    }

    node *current_node = *singly_linked_list;
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            return 0;
        }
        current_node = current_node->next;
    }
    return 1;
}
