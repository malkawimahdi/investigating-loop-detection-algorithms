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
    unsigned int nodes;                  // Number of nodes within graph.
    std::list<int> *adjacent_nodes;     // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::vector<bool> visited;          // Vector bitset checking for visited nodes.
    std::vector<bool> current_visit;    // Vector bitset checking for back edges.

    bool recursiveDepthFirstTraversalSingleNode(int &node); // Implementation of Depth First Search (DFS) from a given node.

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node); // Add an edge to current graph currentNode -> adjacentNode
    bool recursiveDepthTravesalSearch(void);                          // Initialising function to detect back edge loops.
};

#endif // GRAPH_H
