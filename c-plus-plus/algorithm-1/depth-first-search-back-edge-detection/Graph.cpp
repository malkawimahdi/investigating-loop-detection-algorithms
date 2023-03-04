//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.cpp
//

#include "Graph.h"

#include <iostream>
#include <stdexcept>

// Constructor takes number of nodes and generates a list containing an entry the size of nodes.
// (Doubly Linked List)
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->adjacent_nodes = new std::list<int>[nodes];
}

// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
// Follows the property of a Control Flow Graph (CFG), whereby each node can have AT MOST two other adjacent nodes.
void Graph::addEdge(int current_node, int adjacent_node)
{
    if ((this->adjacent_nodes[current_node].size() > 1))
    {
        throw std::runtime_error("Graph can contain AT MOST two children.");
    }
    else
    {
        this->adjacent_nodes[current_node].push_back(adjacent_node); // Add adjacent nodes reachable from current node.
    }
}

// Implementation of Depth First Search (DFS) from a given node.
bool Graph::depthFirstSearch(int &node)
{
    if (!this->visited[node])
    {
        this->visited[node] = true;

        this->current_visit[node] = true;

        // Iterator for associative container (list)
        std::list<int>::iterator it;
        for (it = this->adjacent_nodes[node].begin(); it != this->adjacent_nodes[node].end(); ++it)
        {
            // If cycle detected, then it would be in current visit from node to what the iterator
            // is currently pointing at.
            if (current_visit[*it])
            {
                std::cout << "Back edge from: " << node << " to " << *it << std::endl;
            }

            // If an adjacent_node has not been traversed, and it's traversal returns true then return true;
            //  If a node is located in current visit (think of tying a string to the start of a  maze, and you see the string again)
            //  then return true.
            if ((!visited[*it] && depthFirstSearch(*it)) || current_visit[*it])
            {
                return true;
            }
        }
    }
    // Clear node from currently visited if it is not a back-edge, otherwise it is always true.
    this->current_visit[node] = false;
    return false;
}

bool Graph::containsCycle(void)
{
    unsigned cycle_count = 0;

    // Initalise variables inside graph to false.
    for (auto &[key, value] : this->visited)
    {
        value = false;
    }

    for (auto &[key, value] : this->current_visit)
    {
        value = false;
    }

    // For each node, check if visited.
    for (int counter = 0; counter < this->nodes; ++counter)
    {
        // If a node has not been traversed, and it's traversal returns true then return true;
        // Utilises that the compiler, will determine if the first condition is true or false, before proceeding
        // to check the second condition. (Only saves a line of code)
        if (!this->visited[counter] && depthFirstSearch(counter))
        {
            ++cycle_count;
        }
    }

    if (cycle_count)
    {
        std::cout << "Cycles: " << cycle_count << std::endl;

        std::cout << "Is Cycle Present? ";
        return true;
    }
    else
    {
        std::cout << "Is Cycle Present? ";
        return false;
    }
}