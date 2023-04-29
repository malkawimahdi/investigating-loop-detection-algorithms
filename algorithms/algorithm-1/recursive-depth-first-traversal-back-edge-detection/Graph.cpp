// NOTICE: Graph.cpp utilises a significant proportion of code snippets for general structure
// with no specified license located at:

// Title: Detect Cycle in a Directed Graph
// Author: GeeksForGeeks
// Year: 2023
// URL: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// URL Date: 22nd March 2023

//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.cpp
//

#include "Graph.h"

// This constructor is derived from (GeeksForGeeks, 2023), specifically the generation of how the digraph is
    // represented as an adjacency list.
// Constructor takes number of nodes and generates a DLL for each node containing an entry the size of nodes.
// Reserves the maximum space that the bitset MAY require.
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->visited.resize(this->nodes);
    this->current_visit.resize(this->nodes);
    this->adjacent_nodes = new std::list<int>[nodes];
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes.
    // Size of 1 is used as it references up to two nodes. (Don't know why but 2 nodes = up to 3???) (1 == up to 2)
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
// Follows the property of a Control Flow Graph (CFG), whereby each node can have AT MOST two other adjacent nodes.
void Graph::addEdge(int current_node, int adjacent_node)
{
    // Add adjacent nodes reachable from current node.
    this->adjacent_nodes[current_node].push_back(adjacent_node);
}

// This function is derived from (GeeksForGeeks, 2023), with the difference of outputting the Head and
    // back edge for detected cycles and implementing more efficient data structures of bitsets.
// Dr Martin Nyx Brain also helped with the suggestion that if a node is not a back edge, it is removed from
    // current_visit, analogous to tying a string from the start of a maze. If the string is seen again,
        // a back edge is located.
// Implementation of Depth First Search (DFS) from a given node.
bool Graph::recursiveDepthFirstTraversalSingleNode(int &node)
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
                std::cout << "Head: " << *it << ", BackEdge: " << node << std::endl;
            }

            // If an adjacent_node has not been traversed, and it's traversal returns true then return true;
            //  If a node is located in current visit (think of tying a string to the start of a  maze, and you see the string again)
            //  then return true.
            if ((!visited[*it] && recursiveDepthFirstTraversalSingleNode(*it)) || current_visit[*it])
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
bool Graph::recursiveDepthTraversalSearch(void)
{
    unsigned int cycle_count = 0;

    // For each node, check if visited.
    for (std::size_t counter = 0; counter < this->nodes; ++counter)
    {
        // If a node has not been traversed, and it's traversal returns true then return true;
        // Utilises that the compiler, will determine if the first condition is true or false, before proceeding
        // to check the second condition.
        if (!this->visited[counter] && recursiveDepthFirstTraversalSingleNode(reinterpret_cast<int &>(counter)))
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
