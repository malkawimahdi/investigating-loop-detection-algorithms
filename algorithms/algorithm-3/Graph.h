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
    std::list<int> *backwards_predecessors;  // Pointer to list for backwards adjacent nodes to compute dominators. (Doubly Linked List)
    std::vector<bool> visited;              // Vector bitset checking if a node has been visited.
    std::stack<std::pair<int, int> > stack; // Stack for iterative Depth First Search.
    unsigned int first_node = UINT_MAX;     // Keep track of first node for use in unreachableNodes.
    std::map <int, std::set<int> > dominators; // For each node, contains the set of the dominators for a given node.
    std::set<int> computeDominators(int node); // Computes the dominators from a given node and returns a std::set.

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node, bool for_dominator_tree); // Add an edge to current graph currentNode -> adjacentNode
    Graph dominatorTree(); // Generates a dominator tree based on (Aho et al. 2006).

};

#endif // GRAPH_H
