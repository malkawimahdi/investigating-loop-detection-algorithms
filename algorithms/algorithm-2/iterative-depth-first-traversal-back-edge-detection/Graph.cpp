// NOTICE: Graph.cpp utilises a proportion of code snippets for general structure
// with no specified license located at:
    // Title: Detect Cycle in a Directed Graph
    // Author: GeeksForGeeks
    // Year: 2023
    // URL: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    // URL Access Date: 22nd March 2023

//
// Created by Mahdi Malkawi on 05/03/2023.
//

#include "Graph.h"
#include "Utilities.h"

// This constructor is similar to (GeeksForGeeks, 2023) example, specifically the generation of how the digraph is
// represented as an adjacency list.
// Constructor takes number of nodes and generates a DLL for each node.
// Reserves the maximum space that the bitset requires.
Graph::Graph(const unsigned int nodes)
{
    this->nodes = nodes;
    this->adjacent_nodes = new std::list<unsigned int>[nodes];
    this->visited.resize(this->nodes);
    this->cycle_count = 0;
    this->unreachable_node_count = 0;
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes
// to conform to the requirements that a control flow graph requires.
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
void Graph::addEdge(const unsigned int current_node, const unsigned int adjacent_node)
{
    if(adjacent_nodes[current_node].size() > 1)
    {
        throw std::runtime_error("Each node is permitted to have at most TWO children!");
    }
    else
    {
        // Add adjacent nodes reachable from current node.
        this->adjacent_nodes[current_node].push_back(adjacent_node);
    }
}

// Detect unreachable nodes from the entry node.
void Graph::unreachableNodes()
{
    for (std::size_t counter = entry_node; counter < this->visited.size(); ++counter)
    {
        if (!visited[counter])
        {
            if (this->unreachable_node_count == 0)
            {
                std::cout << "Unreachable Node(s): ";
                std::cout << counter;
                ++this->unreachable_node_count;
            }
            else
            {
                std::cout << ", " << counter;
                ++this->unreachable_node_count;
            }
        }
    }

    if (this->unreachable_node_count > 0)
    {
        std::cout << std::endl;
        std::cout << "Unreachable Node(s) Count: " << this->unreachable_node_count << std::endl;
    }
}

// Implementation of cycle detection using iterative Depth First Search from the entry node to check for cycles
    // and output nodes contained within cycles.
// Ensures that inaccessible nodes (inaccessible code) is not reached.
// Outputs detected cycles in the same way as CBMC.
void Graph::iterativeDepthTraversalSearch(void)
{
    // Locates the entry node in the graph, which should typically be the first node in the graph that has an adjacent
    // node as the start by convention.
    for (std::size_t counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            this->entry_node = counter;

            // Each node is viewed as a pair in the form of std::pair<node, index>
            this->stack.push(std::make_pair(counter, 0));
            break;
        }
    }

    bool cycle = false;

    // Iterative Depth First Search.
    while (!this->stack.empty())
    {
        // Get the top most node and visit it.
        std::pair<unsigned int, unsigned int> current_pair = this->stack.top();

        this->visited[(current_pair.first)] = true;

        // If the index of the second node is less than the size of the elements in the adjacency list...
        if (current_pair.second < this->adjacent_nodes[current_pair.first].size())
        {
            // Get initial index for start of adjacency_list and get the node required by the counter.
            // Received assistance from Dr Martin Nyx Brain, randomly accessing a std::list.
            std::list<unsigned int>::iterator it = this->adjacent_nodes[current_pair.first].begin();

            for (std::size_t i = 0; i < current_pair.second; ++i)
            {
                ++it;
            }

            int next_node = *it;

            // If the next_node has been seen, then there could be a cycle.
            // If the next_node is located then a cycle will form staying within current node.
            if (this->visited[next_node])
            {
                // Check if the next_node is in the stack. If it is then it is GUARANTEED to be in a cycle.
                // Required as if there is a control flow graph in the form of a diamond, only a half is viewed.
                // Dr Martin Nyx Brain suggested this improvement based on the problem above.
                if (stackChecker(next_node, this->stack))
                {
                    cycle = true;

                    ++this->cycle_count;

                    // Generates output which contains nodes in the cycle specifically in the same format as CBMC.
                    cbmcCycleOutput(next_node, this->stack);
                }
            }

            // Iterate the index for the current node.
            ++this->stack.top().second;

            // If it is a cycle, then next_node is NOT placed on the stack as it will be an infinite loop.
            if (!cycle)
            {
                this->stack.push(std::make_pair(next_node, 0));
            }

            // Reset cycle
            cycle = false;
        }
        else
        {
            // Remove node after it has been accessed and all elements in adjacency_list[node]
            // have been placed on the stack.
            this->stack.pop();
            continue;
        }
    }

    this->unreachableNodes();

    if (this->cycle_count > 0)
    {
        std::cout << "Cycle(s): " << this->cycle_count << std::endl;
    }
    else
    {
        std::cout << "No Cycle(s) Detected!" << std::endl;
    }
}