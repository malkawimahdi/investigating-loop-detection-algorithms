//
// Created by Mahdi Malkawi on 05/03/2023.
//

#include "Graph.h"
#include "Utilities.h"

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
        // Add adjacent nodes reachable from current node.
        this->adjacent_nodes[current_node].push_back(adjacent_node);
    }
}

// Received assistance from Dr Martin Nyx Brain, with accessing the adjacency_list for each node iteratively.
// Implementation of cycle detection using iterative Depth First Search using ONLY the start node to check for cycles and output
// nodes contained within cycles.
// Ensures that inaccessible nodes (inaccessible code) is not reached.
// Outputs detected cycles in the same way as CBMC.
bool Graph::depthFirstSearch(int node)
{
    // Initalise variables inside graph to false.
    for (auto &[key, value] : this->visited)
    {
        value = false;
    }

    // Each node is viewed as a pair in the form of std::pair<node, index>
    this->stack.push(std::make_pair(node, 0));

    // Iterative Depth First Search.
    while (!this->stack.empty())
    {
        // Get the top most node and visit it.
        std::pair<int, int> current_node = this->stack.top();

        this->visited[current_node.first] = true;

        // If the index of the second node is less than the size of the elements in the adjacency list...
        if (current_node.second < this->adjacent_nodes[current_node.first].size())
        {
            // Get initial index for start of adjacency_list and get the node required by the counter.
            // Received assistance from Dr Martin Nyx Brain, randomly accessing a std::list
            std::list<int>::iterator it = this->adjacent_nodes[current_node.first].begin();

            for (int i = 0; i < current_node.second; ++i)
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
                // Dr Martin Nyx Brain suggested this improvement.
                if (stackChecker(next_node, this->stack))
                {
                    this->cycle = true;

                    // Required as cycle is reset after each iteration, this is used for the function output.
                    this->is_there_a_cycle = true;

                    ++cycle_count;

                    // Generates output which contains nodes in the cycle specifically in the same format as CBMC.
                    cbmcCycleOutput(next_node, this->stack);
                }
            }

            // Iterate the index for the current node.
            this->stack.top().second++;

            // If it is a cycle, then next_node is NOT placed on the stack as it will be an infinite loop.
            if (!cycle)
            {
                this->stack.push(std::make_pair(next_node, 0));
            }

            // Reset cycle
            this->cycle = false;
        }
        else
        {
            // Remove node after it has been accessed and all elements in adjacency_list[node]
            // have been placed on the stack.
            this->stack.pop();
            continue;
        }
    }

    // Detects unreachable nodes.
    // If a node has not been visited, it means that it is not reachable from the entry node.
    for (auto &[key, value] : this->visited)
    {
        if (! this->visited[key])
        {
            std::cout << "Unreachable node: " << key << std::endl;
        }
    }

    std::cout << "Cycles: " << this->cycle_count << std::endl;
    std::cout << "Is Cycle Present? ";
    return this->is_there_a_cycle;
}
