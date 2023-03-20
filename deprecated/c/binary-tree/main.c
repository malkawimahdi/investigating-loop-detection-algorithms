#include "BinaryTree.c"

int main(void)
{
    //Head of a new binary search tree.
    node *tree = NULL;

    //Create a new node, by allocating memory from the heap.
    node *n1 = malloc(sizeof(node));

    //If malloc returns NULL then exit program
    if (n1 == NULL)
    {
        return 1;
    }

    //Modify nodes values manually such that the first node has a value of 1, and its pointers are NULL;
    n1->number = 2;
    n1->left = NULL;
    n1->right = NULL;

    //Make sure that the tree points to the first node.
    tree = n1;

    //Currently 1 node with the value of 2 and no children.

    //Use the same pointer to allocate more space for another node.
    n1 = malloc(sizeof(node));

    if (n1 == NULL)
    {
        free(tree);
        return 1;
    }

    //New nodes children are NULL.
    n1->number = 1;
    n1->left = NULL;
    n1->right = NULL;

    //Connect the tree to the current node.
    //The 1st nodes left child now points at the location that n1 occurs.
    tree->left = n1;

    n1 = malloc(sizeof(node));

    if (n1 == NULL)
    {
        free(tree);
        return 1;
    }

    n1->number = 3;
    n1->left = NULL;
    n1->right = NULL;

    tree->right = n1;


    n1 = malloc(sizeof(node));

    if (n1 == NULL)
    {
        free(tree);
        return 1;
    }

    n1->number = 5;
    n1->left = NULL;
    n1->right = NULL;

    tree->left->right = n1;


    n1 = malloc(sizeof(node));

    if (n1 == NULL)
    {
        free(tree);
        return 1;
    }

    n1->number = 9;
    n1->left = NULL;
    n1->right = NULL;

    tree->right->right = n1;
    
    bool isSearchComplete = depth_first_search(tree);

    printf("Searching the tree... ");
    printf(isSearchComplete ? "true\n" : "false\n");

    bool isVisited = depth_first_search_checker(tree);

    printf("Ensuring all nodes are visited... ");
    printf(isVisited ? "true\n" : "false\n");

    free_tree(tree);
}