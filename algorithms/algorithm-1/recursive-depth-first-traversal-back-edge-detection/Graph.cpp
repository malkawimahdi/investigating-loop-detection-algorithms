// NOTICE: Graph.cpp utilises a proportion of code snippets for general structure
// with no specified license located at:
    // Title: Detect Cycle in a Directed Graph
    // Author: GeeksForGeeks
    // Year: 2023
    // URL: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    // URL Access Date: 22nd March 2023

//
// Created by Mahdi Malkawi on 08/02/2023.
// Graph.cpp
//

#include "Graph.h"

// This constructor is similar to (GeeksForGeeks, 2023) example, specifically the generation of how the digraph is
    // represented as an adjacency list.
// Constructor takes number of nodes and generates a DLL for each node.
// Reserves the maximum space that the bitset requires.
Graph::Graph(unsigned const int nodes)
{
    this->nodes = nodes;
    this->adjacent_nodes = new std::list<int>[nodes];
    this->visited.resize(this->nodes);
    this->cycle_count = 0;
    this->unreachable_node_count = 0;
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes
    // to conform to the requirements that a control flow graph requires.
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
void Graph::addEdge(unsigned const int current_node, unsigned const int adjacent_node)
{
    // If an attempt is made to give the current node more than two children...
    if (this->adjacent_nodes[current_node].size() > 1)
    {
        std::runtime_error("Each node is permitted to have TWO children!");
    }
    else
    {
        this->adjacent_nodes[current_node].push_back(adjacent_node);
    }
}

// The idea to recursively access each node was derived from (GeeksForGeeks, 2023) example. This function is different
    // as this function recursively iterates through all nodes accessible from the entry, reviewing each outgoing arc
        // associated with the current node and checking if the outgoing arc points to a previously visited node.
void Graph::recursiveDepthFirstTraversalCycleDetection(unsigned const int node)
{
    this->visited[node] = true;

    for (std::list<int>::iterator it = this->adjacent_nodes[node].begin();
    it != this->adjacent_nodes[node].end(); ++it)
    {
        // A cycle is detected if the same node is visited more than once.
        if (visited[*it])
        {
            this->cycle_count++;
            std::cout << *it << " is head of { " << *it << ", " << node << " (backedge) }" << std::endl;
        }

        if (!visited[*it])
        {
            recursiveDepthFirstTraversalCycleDetection(*it);
        }
    }
}

void Graph::unreachableNodes()
{
    for (std::size_t counter = this->entry_node; counter < this->visited.size(); ++counter)
    {
        if (!this->visited[counter])
        {
            if (this->unreachable_node_count == 0)
            {
                std::cout << "Unreachable Node(s): ";
                std::cout << counter;
                ++unreachable_node_count;
            }
            else
            {
                std::cout << ", " << counter;
                ++unreachable_node_count;
            }
        }
    }

    if (this->unreachable_node_count > 0)
    {
        std::cout << std::endl;
        std::cout << "Unreachable Node(s) Count: " << this->unreachable_node_count << std::endl;
    }
}

void Graph::recursiveDepthFirstTraversalCycleDetectionInitialisation()
{
    for (std::size_t counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            this->entry_node = counter;
            break;
        }
    }

    this->recursiveDepthFirstTraversalCycleDetection(entry_node);

    this->unreachableNodes();

    if (this->cycle_count)
    {
        std::cout << "Cycle(s): " << this->cycle_count << std::endl;
    }
    else
    {
        std::cout << "No Cycle(s) Detected!" << std::endl;
    }
}