#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;


int insert_node(node **binary_search_tree, int data);
int min_node(node **binary_search_tree);
int delete_node(node **binary_search_tree, int data);
int search_node(node **binary_search_tree, int data);
void pre_order_traversal(node **binary_search_tree);
void in_order_traversal(node **binary_search_tree);
void post_order_traversal(node **binary_search_tree);


int main(void)
{
    printf("Binary Search Tree \n");
    node *binary_search_tree = NULL;
    while (true)
    {
        printf("1. Insert Node \n");
        printf("2. Delete Node \n");
        printf("3. Search Node \n");
        printf("4. Pre-Order Traversal \n");
        printf("5. In-Order Traversal \n");
        printf("6. Post-Order Traversal \n");
        printf("7. Root Element \n");
        printf("8. Lowest Node \n");

        printf("Please Select: ");
        int choice;
        if (scanf("%i", &choice) != 1)
        {
            printf("could not read input \n");
            return 1;
        }

        if (choice == 1)
        {
            printf("Enter Node to Insert: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int insert_status = insert_node(&binary_search_tree, data);
            if (insert_status == 0)
            {
                printf("Node Inserted Successfully \n");
            }
            else
            {
                printf("Node Insertion Failed \n");
            }

            pre_order_traversal(&binary_search_tree);
            printf("\n");
        }

        else if (choice == 2)
        {
            printf("Enter Node to Delete: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }
            int delete_status = delete_node(&binary_search_tree, data);
            if (delete_status == 0)
            {
                printf("Node Deleted Successfully \n");
            }
            else
            {
                printf("Node Deletion Failed \n");
            }

            pre_order_traversal(&binary_search_tree);
            printf("\n");
        }

        else if (choice == 3)
        {
            printf("Enter Node to Search: ");
            int data;
            if (scanf("%i", &data) != 1)
            {
                printf("could not read input \n");
                return 1;
            }

            int found = search_node(&binary_search_tree, data);
            if (found == 0)
            {
                printf("Node found in BST \n");
            }
            else if (found == -1)
            {
                printf("Tree Already Empty \n");
            }
            else
            {
                printf("Node not Found \n");
            }
        }
        else if (choice == 4)
        {
            pre_order_traversal(&binary_search_tree);
            printf("\n");
        }
        else if (choice == 5)
        {
            in_order_traversal(&binary_search_tree);
            printf("\n");
        }
        else if (choice == 6)
        {
            post_order_traversal(&binary_search_tree);
            printf("\n");
        }
        else if (choice == 7)
        {
            if (binary_search_tree == NULL)
            {
                printf("tree empty \n");
            }

            printf("%i\n", binary_search_tree->data);
        }
        else if (choice == 8)
        {
            printf("%i\n", min_node(&binary_search_tree));
        }
        else
        {
            printf("Invalid Choice! \n");
            return 1;
        }
    }
    return 0;
}


int insert_node(node **binary_search_tree, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("could not allocate memory \n");
        return 1;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*binary_search_tree == NULL)
    {
        *binary_search_tree = new_node;
        return 0;
    }

    node *current_node = *binary_search_tree;
    while (current_node != NULL)
    {
        if (data < current_node->data)
        {
            if (current_node->left == NULL)
            {
                current_node->left = new_node;
                return 0;
            }
            else
            {
                current_node = current_node->left;
            }
        }
        else if (data > current_node->data)
        {
            if (current_node->right == NULL)
            {
                current_node->right = new_node;
                return 0;
            }
            else
            {
                current_node = current_node->right;
            }
        }
    }
    return 0;
}


int min_node(node **binary_search_tree)
{
    if (*binary_search_tree == NULL)
    {
        printf("tree is empty \n");
        return -1;
    }

    node *current_node = *binary_search_tree;
    while (current_node->left != NULL)
    {
        current_node = current_node->left;
    }
    return current_node->data;
}


int delete_node(node **binary_search_tree, int data)
{
    if (*binary_search_tree == NULL)
    {
        return -1;
    }

    node *current_node = *binary_search_tree;
    node *prev_node = NULL;

    while (current_node != NULL)
    {
        if (data < current_node->data)
        {
            prev_node = current_node;
            current_node = current_node->left;
        }
        else if (data > current_node->data)
        {
            prev_node = current_node;
            current_node = current_node->right;
        }
        else
        {

            if (current_node->left == NULL && current_node->right == NULL)
            {
                if (prev_node == NULL)
                {
                    *binary_search_tree = NULL;
                }
                else if (prev_node->left == current_node)
                {
                    prev_node->left = NULL;
                }

                else if (prev_node->right == current_node)
                {
                    prev_node->right = NULL;
                }
                free(current_node);
                return 0;
            }

            else if (current_node->left == NULL || current_node->right == NULL)
            {
                node *child = NULL;
                if (current_node->left != NULL)
                {
                    child = current_node->left;
                }
                else
                {
                    child = current_node->right;
                }


                if (prev_node == NULL)
                {
                    *binary_search_tree = child;
                }
                else if (prev_node->left == current_node)
                {
                    prev_node->left = child;
                }
                else
                {
                    prev_node->right = child;
                }

                free(current_node);
                return 0;
            }
            else
            {
                int in_order_succ = min_node(&(*binary_search_tree)->right);
                current_node->data = in_order_succ;
                (void)delete_node(&(*binary_search_tree)->right, in_order_succ);
                return 0;
            }
        }
    }
    return 1;
}


int search_node(node **binary_search_tree, int data)
{
    if (*binary_search_tree == NULL)
    {
        return -1;
    }

    node *current_node = *binary_search_tree;
    while (current_node != NULL)
    {
        if (data < current_node->data)
        {
            current_node = current_node->left;
        }
        else if (data > current_node->data)
        {
            current_node = current_node->right;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


void pre_order_traversal(node **binary_search_tree)
{
    node *current_node = *binary_search_tree;
    if (current_node == NULL)
    {
        return;
    }
    printf("%i ", current_node->data);
    pre_order_traversal(&current_node->left);
    pre_order_traversal(&current_node->right);
}


void in_order_traversal(node **binary_search_tree)
{
    node *current_node = *binary_search_tree;
    if (current_node == NULL)
    {
        return;
    }

    in_order_traversal(&current_node->left);
    printf("%i ", current_node->data);
    in_order_traversal(&current_node->right);
}


void post_order_traversal(node **binary_search_tree)
{
    node *current_node = *binary_search_tree;
    if (current_node == NULL)
    {
        return;
    }

    post_order_traversal(&current_node->left);
    post_order_traversal(&current_node->right);
    printf("%i ", current_node->data);
}
