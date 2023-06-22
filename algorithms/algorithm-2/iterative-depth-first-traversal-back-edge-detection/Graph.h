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
    unsigned int nodes; // Number of nodes within graph.
    std::list<unsigned int> *adjacent_nodes; // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::vector<bool> visited; // Vector bitset checking if a node has been visited.
    unsigned int entry_node;
    unsigned int cycle_count;
    unsigned int unreachable_node_count;

private:
    void unreachableNodes();

public:
    // Constructor, taking the number of nodes for a graph.
    explicit Graph(const unsigned int nodes);

    // Add an edge to current graph currentNode -> adjacentNode
    void addEdge(const unsigned int current_node, const unsigned int adjacent_node);

    // Implementation of cycle detection using iterative depth first traversal search.
    void iterativeDepthFirstTraversalSearch(void);
};

#endif // GRAPH_H