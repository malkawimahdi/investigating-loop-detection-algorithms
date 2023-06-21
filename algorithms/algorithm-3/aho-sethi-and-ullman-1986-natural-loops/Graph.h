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
    unsigned int nodes; // Number of nodes within graph.
    std::list<unsigned int> *adjacent_nodes; // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::list<unsigned int> *backwards_predecessors; // Pointer to list containing adjacent nodes in reverse for all nodes. (Children point to parent instead)
    std::vector<bool> visited; // Vector bitset checking if a node has been visited.
    unsigned int entry_node;
    bool is_there_a_cycle;
    unsigned int cycle_count;
    unsigned int unreachable_node_count;
    std::map <unsigned int, std::set<unsigned int> > dominators; // For each node, contains the set of the dominators for a given node.
    std::map <unsigned int, std::set<unsigned int> > natural_loops; // Key is the loop head and set contains elements within the loop.
    std::map <unsigned int, std::set<unsigned int> > back_edges; // Key is the loop head and set contains back edges for each loop head.

private:
    // Compute the natural loop within the bound defined by the head and tail.
    void computeNaturalLoop(const unsigned int head, const unsigned int tail);

    // Generate the set of dominators for each node within the control flow graph.
    void computeDominators(void);

    // Detects unreachable nodes from the entry node.
    void unreachableNodes();

public:
    // Constructor, which takes the number of nodes for a graph.
    explicit Graph(const unsigned int nodes);

    // Add an edge to current graph currentNode -> adjacentNode
    void addEdge(const unsigned int current_node, const unsigned int adjacent_node);

    // Output the set of dominators for each node within the control flow graph.
    void computeDominatorsOutput(void);

    // Computes natural loops within a graph
    bool naturalLoops(void);
};

#endif // GRAPH_H