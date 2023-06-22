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

/* This constructor is similar to (GeeksForGeeks, 2023) example, specifically the generation of how the digraph is
 * represented as an adjacency list. */
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

/* This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes
 * to conform to the requirements that a control flow graph requires. */
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

/* Implementation of cycle detection using iterative Depth First Search from the entry node to check for cycles
 * and output nodes contained within cycles. */
// Ensures that inaccessible nodes (inaccessible code) is not reached.
// Outputs detected cycles in the same way as CBMC.
void Graph::iterativeDepthFirstTraversalSearch(void)
{
    // Stack for iterative Depth First Search.
    std::stack<std::pair<unsigned int, unsigned int> > stack;

    /* Locates the entry node in the graph, which should typically be the first node in the graph that has an adjacent
     * node as the start by convention. */
    for (std::size_t counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            this->entry_node = counter;

            // Each node is viewed as a pair in the form of std::pair<node, index>
            stack.push(std::make_pair(counter, 0));
            break;
        }
    }

    bool cycle = false;

    // Iterative Depth First Search.
    while (!stack.empty())
    {
        // Get the top most node and visit it.
        std::pair<unsigned int, unsigned int> current_pair = stack.top();

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

            unsigned int next_node = *it;

            // If the next_node has been seen, then there could be a cycle.
            // If the next_node is located then a cycle will form staying within current node.
            if (this->visited[next_node])
            {
                // Check if the next_node is in the stack. If it is then it is GUARANTEED to be in a cycle.
                // Required to incorrectly prevent a cycle being detected as the second half of a CFG in a diamond.
                // E.g.
//                         +-----+
//                         |     |
//                +--------+  0  +--------+
//                |        |     |        |
//                |        +-----+        |
//                |                       |
//                v                       v
//                +--+--+                 +--+--+
//                |     |                 |     |
//                |  1  |                 |  3  |
//                |     |                 |     |
//                +--+--+                 +--+--+
//                |                       |
//                |                       |
//                |        +-----+        |
//                |        |     |        |
//                +------->+  2  +<-------+
//                         |     |
//                         +-----+

                // Without it, other half, would generate: 2 is head of { 0, 3 (backedge) } as it is duplicated twice.
                // even though it is clearly incorrect. Cycle is ensured as node is not removed until all adjacent
                // nodes for a given node have been traversed, ensuring that what is contained within a
                // traversed path generating a confirmed cycle.
                // Dr Martin Nyx Brain explained why the edge case occurred to lead to a solution.
                if (stackChecker(next_node, stack))
                {
                    cycle = true;

                    ++this->cycle_count;

                    // Generates output which contains nodes in the cycle specifically in the same format as CBMC.
                    cbmcCycleOutput(next_node, stack);
                }
            }

            // Iterate the index for the current node.
            ++stack.top().second;

            // If it is a cycle, then next_node is NOT placed on the stack as it will be an infinite loop.
            if (!cycle)
            {
                stack.push(std::make_pair(next_node, 0));
            }

            // Reset cycle
            cycle = false;
        }
        else
        {
            // Remove node after it has been accessed and all elements in adjacency_list[node]
            // have been placed on the stack.
            stack.pop();
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