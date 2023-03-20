#include "BinaryTree.h"

// Recursively go within tree and free() the tree from the lowest level nodes upwards.
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Clear terminal, to view output easier.
void clear(void)
{
    printf("\n\n\n\n\n\n\n\n\n");
}

// Search through tree, looking for a specific node, same way as a binary search tree.
// TODO: Maybe another way?
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }

    else if (number < (tree->number))
    {
        return search(tree->left, number);
    }

    else if (number > (tree->number))
    {
        return search(tree->right, number);
    }

    //Case that the number is equal to the tree->number
    else
    {
        return true;
    }
}

// Depth first Search (DFS) visiting each node in the tree from the input node.
// Middle node.
// Left node.
// Right node.
bool depth_first_search(node *tree)
{
    if (tree == NULL)
    {
        return false;
    }

    tree->visited = true;
    printf("Visited: %i \n", tree->number);

    depth_first_search(tree->left);
    depth_first_search(tree->right);

    return true;
}

// Ensures that every nodes "visited" field is true, otherwise false.
bool depth_first_search_checker(node *tree)
{
    if (tree == NULL)
    {
        return false;
    }

    if ((tree->visited) == true)
    {
        printf("Visited: %i \n", tree->number);
        
        depth_first_search(tree->left);
        depth_first_search(tree->right);
    }
    else
    {
        return false;
    }

    return true;
}