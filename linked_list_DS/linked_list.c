#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


int insert_node_at_end(node **linked_list, int data);
int insert_node_at_beginning(node **linked_list, int data);
int delete_node(node **linked_list, int data);
int search_node(node **linked_list, int data);
void display_linked_list(node **linked_list);


int main(void)
{
    printf("Linked List \n");
    node *linked_list = NULL;
    while (true)
    {
        printf("1. Insert Node at End \n");
        printf("2. Insert Node at Beginning \n");
        printf("3. Delete Node \n");
        printf("4. Search Node \n");
        printf("5. Display/Traverse Linked List \n");
        printf("Please Select: ");
        int choice;
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input \n");
            return 1;
        }

        if (choice == 1)
        {
            printf("Enter node data: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }
            int insert_status = insert_node_at_end(&linked_list, data);
            if (insert_status == 0)
            {
                printf("Node Inserted Successfully \n");
            }
            else
            {
                printf("Node Insertion Failed \n");
            }

            display_linked_list(&linked_list);
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

            int insert_status = insert_node_at_beginning(&linked_list, data);
            if (insert_status == 0)
            {
                printf("Node Inserted Successfully \n");
            }
            else
            {
                printf("Node Insertion Failed \n");
            }

            display_linked_list(&linked_list);
        }
        else if (choice == 3)
        {
            printf("Enter Node to delete:");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int delete_status = delete_node(&linked_list, data);
            if (delete_status == 0)
            {
                printf("Node Deleted Successfully \n");
            }
            else
            {
                printf("Node Deletion Failed \n");
            }

            display_linked_list(&linked_list);
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

            int search_status = search_node(&linked_list, data);
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
            display_linked_list(&linked_list);
        }
        else
        {
            printf("Invalid Choice \n");
            return 1;
        }
    }
    return 0;
}


int insert_node_at_end(node **linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    (*new_node).data = data;  // new_node->data = data;
    (*new_node).next = NULL;

    if (*linked_list == NULL)
    {
        *linked_list = new_node;
        return 0;
    }
    else
    {
        node *current_node = *linked_list;
        while(current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return 0;
}


int insert_node_at_beginning(node **linked_list, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    (*new_node).data = data;
    (*new_node).next = *linked_list;

    *linked_list = new_node;
    return 0;
}


int delete_node(node **linked_list, int data)
{
    if ((*linked_list)->data == data)
    {
        *linked_list = (*linked_list)->next;
        return 0;
    }

    node *current_node = *linked_list;
    node *prev_node = NULL;
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            prev_node->next = current_node->next;
            return 0;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return 1;
}


int search_node(node **linked_list, int data)
{
    node *current_node = *linked_list;
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


void display_linked_list(node **linked_list)
{
    node *current_node = *linked_list;
    while(current_node != NULL)
    {
        printf("%i ->", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL \n");
}
