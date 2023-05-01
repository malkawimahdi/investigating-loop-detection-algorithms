//
// Created by Mahdi Malkawi on 05/03/2023.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Graph
{
private:
    int nodes;                              // Number of nodes within graph.
    std::list<int> *adjacent_nodes;         // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::vector<bool> visited;              // Vector bitset checking if a node has been visited.
    std::stack<std::pair<int, int> > stack; // Stack for iterative Depth First Search.
    unsigned int first_node = UINT_MAX;     // Keep track of first node for use in unreachableNodes.
    bool cycle = false;                     // Cycle check.
    bool is_there_a_cycle = false;          // Required as cycle is reset after each iteration, this is used for the function output.
    unsigned int cycle_count = 0;           // Cycle counter.

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node); // Add an edge to current graph currentNode -> adjacentNode
    bool iterativeDepthTraversalSearch(void); // Implementation of cycle detection using iterative depth first traversal search.
};

#endif // GRAPH_H