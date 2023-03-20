#ifndef BINARYTREE_H_   /* Include guard */
#define BINARYTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    bool visited;
    struct node *left;
    struct node *right;
}
node;

// Recursively go within tree and free() the tree from the lowest level nodes upwards.
void free_tree(node *root);

// Clear terminal, to view output easier.
void clear(void);

// Search through tree, looking for a specific node, same way as a binary search tree.
// TODO: Maybe another way?
bool search(node *tree, int number);

// Depth first Search (DFS) visiting each node in the tree from the input node.
bool depth_first_search(node *tree);

// Ensures that every nodes "visited" field is true, otherwise false.
bool depth_first_search_checker(node *tree);
#endif // BINARYTREE_H_