//
// NOTICE: Graph.cpp utilises a significant proportion of code snippets and general structure
    // with no specified license located at:
// Title: Detect Cycle in a Directed Graph
// Author: GeeksForGeeks
// Year: 2023
// URL: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// URL Date: 22rd March 2023
//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.cpp
//

#include "Graph.h"

// This constructor is derived from (GeeksForGeeks, 2023), specifically the generation of how the diagraph is
    // represented as an adjacency list.
// Constructor takes number of nodes and generates a DLL for each node containing an entry the size of nodes.
// Reserves the maximum space that the bitset MAY require.
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->visited.reserve(this->nodes);
    this->current_visit.reserve(this->nodes);
    this->adjacent_nodes = new std::list<int>[nodes];
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes.
    // Size of 1 is used as it references up to two nodes.
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
// Follows the property of a Control Flow Graph (CFG), whereby each node can have AT MOST two other adjacent nodes.
void Graph::addEdge(int current_node, int adjacent_node)
{
    if ((this->adjacent_nodes[current_node].size() > 1))
    {
        throw std::runtime_error("Graph Can Contain AT MOST Two Children.");
    }
    else
    {
        this->adjacent_nodes[current_node].push_back(adjacent_node); // Add adjacent nodes reachable from current node.
    }
}

// This function is derived from (GeeksForGeeks, 2023), with the difference of outputting the Head and
    // back edge for detected cycles and implementing more efficient data structures of bitsets.
// Implementation of Depth First Search (DFS) from a given node.
bool Graph::recursiveDepthFirstSearch(int &node)
{
    if (!this->visited[node])
    {
        this->visited[node] = true;

        this->current_visit[node] = true;

        for (std::list<int>::iterator it = this->adjacent_nodes[node].begin(); it != this->adjacent_nodes[node].end(); ++it)
        {
            // If cycle detected, then it would be in current visit from node to what the iterator
            // is currently pointing at.
            if (current_visit[*it])
            {
                std::cout << "Back Edge From: " << node << " to " << *it << std::endl;
            }

            // If an adjacent_node has not been traversed, and it's traversal returns true then return true;
            //  If a node is located in current visit (think of tying a string to the start of a  maze, and you see the string again)
            //  then return true.
            if ((!visited[*it] && recursiveDepthFirstSearch(*it)) || current_visit[*it])
            {
                return true;
            }
        }
    }
    // Clear node from currently visited if it is not a back-edge, otherwise it is always true.
    this->current_visit[node] = false;
    return false;
}

// This function is derived from (GeeksForGeeks, 2023), with the difference in what occurs if a cycle is detected,
    // specifically counting the number of cycles and the efficiency improvements of a bitset.
bool Graph::containsCycle(void)
{
    unsigned int cycle_count = 0;

    // For each node, check if visited.
    for (int counter = 0; counter < this->nodes; ++counter)
    {
        // If a node has not been traversed, and it's traversal returns true then return true;
        // Utilises that the compiler, will determine if the first condition is true or false, before proceeding
        // to check the second condition.
        if (!this->visited[counter] && recursiveDepthFirstSearch(counter))
        {
            ++cycle_count;
        }

    }

    if (cycle_count)
    {
        std::cout << "Cycle(s): " << cycle_count << std::endl;

        return true;
    }
    else
    {
        std::cout << "No Cycle(s) Detected!" << std::endl;
        return false;
    }
}
