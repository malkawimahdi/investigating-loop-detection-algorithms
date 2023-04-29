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
#include <map>
#include <set>

class Graph
{
private:
    int nodes;                              // Number of nodes within graph.
    std::list<int> *adjacent_nodes;         // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::list<int> *backwards_predecessors; // Pointer to list containing adjacent nodes in reverse for all nodes. (Children point to parent instead)
    std::vector<bool> visited;              // Vector bitset checking if a node has been visited.
    unsigned int first_node = UINT_MAX;     // Keep track of first node for use in unreachableNodes.
    bool cycle = false;                     // Cycle check.
    bool is_there_a_cycle = false;          // Required as cycle is reset after each iteration, this is used for the function output.
    unsigned int cycle_count = 0;           // Cycle counter.
    std::map <int, std::set<int> > dominators; // For each node, contains the set of the dominators for a given node.
    std::map <int, std::set<int> > natural_loops; // Key is the loop head and set contains elements within the loop.
private:
    void computeNaturalLoop(int head, int tail);

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node); // Add an edge to current graph currentNode -> adjacentNode
    void computeDominators(void); // Generate the set of dominators for each node within the control flow graph.
    void computeDominatorsOutput(void); // Output the set of dominators for each node within the control flow graph.
    bool naturalLoops(void); // Computes natural loops within a graph

};

#endif // GRAPH_H
