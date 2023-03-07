//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.h
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>

class Graph
{
private:
    int nodes;                         // Number of nodes within graph.
    std::list<int> *adjacent_nodes;    // Pointer to list containing adjacent nodes for all nodes. (Doubly Linked List)
    std::map<int, bool> visited;       // Key value pair. (Key: Node) (Value: hasNodeBeenVisited)
    std::map<int, bool> current_visit; // Key value pair. (Key: Node) (Value: hasNodeBeenVisited) differs from visited
                                       // as it keep track of the key value pairs outside of function call.

    bool depthFirstSearch(int &node); // Implementation of Depth First Search (DFS) from a given node.

public:
    explicit Graph(int nodes);                         // Constructor, which takes the number of nodes for a graph.
    void addEdge(int current_node, int adjacent_node); // Add an edge to current graph currentNode -> adjacentNode
    bool containsCycle(void);                          // Uses private function "depthFirstSearch" to locate back-edges and detect loops.
};

#endif // GRAPH_H
