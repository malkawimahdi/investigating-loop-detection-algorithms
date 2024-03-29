//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.h
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <stdexcept>
#include <vector>

class Graph
{
private:
    unsigned int nodes; // Number of nodes within graph.
    std::list<unsigned int> *adjacent_nodes; // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::vector<bool> visited; // Vector bitset checking for visited nodes.
    unsigned int entry_node;
    unsigned int cycle_count;
    unsigned int unreachable_node_count;

private:
    // Detect unreached nodes within Graph after performing cycle detection.
    void unreachableNodes(void);

    // Implementation of Depth First Search (DFS) to recursively detect cycles from a given node.
    void recursiveDepthFirstTraversalCycleDetection(const unsigned int node);

public:
    // Constructor, which takes the number of nodes for a graph.
    explicit Graph(const unsigned int nodes);

    // Add an edge to current graph currentNode -> adjacentNode
    void addEdge(const unsigned current_node,const unsigned int adjacent_node);

    void recursiveDepthFirstTraversalCycleDetectionInitialisation();
};

#endif // GRAPH_H
