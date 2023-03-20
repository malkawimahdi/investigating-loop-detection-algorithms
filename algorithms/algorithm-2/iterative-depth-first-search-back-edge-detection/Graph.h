//
// Created by Mahdi Malkawi on 05/03/2023.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Graph
{
private:
    int nodes;                             // Number of nodes within graph.
    std::list<int> *adjacent_nodes;        // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::map<int, bool> visited;           // Key value pair. (Key: Node) (Value: has that node been visited?)
    std::stack<std::pair<int, int> > stack; // Stack for iterative Depth First Search.
    bool cycle = false;                    // Cycle check.
    bool is_there_a_cycle = false;        // Required as cycle is reset after each iteration, this is used for the function output.
    unsigned int cycle_count = 0;          // Cycle counter.

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node); // Add an edge to current graph currentNode -> adjacentNode
    bool depthFirstSearch(void);                   // Implementation of cycle detection using iterative Depth First Search.
};

#endif // GRAPH_H
