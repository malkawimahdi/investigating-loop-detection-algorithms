//
// Created by Mahdi Malkawi on 05/03/2023.
//

#include "Graph.h"

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
    //Each node is viewed as a pair in the form of std::pair<node, index>
    this->stack.push(std::pair(node, 0));

    this->visited[node] = true;

// Iterative Depth First Search.
    while (! this->stack.empty())
    {
        // Get the top most node and visit it.
        std::pair<int, int> current_node = this->stack.top();
        this->visited[current_node.first] = true;

        // If the index of the second node is less than the size of the elements in the adjacency list...
        if (current_node.second < this->adjacent_nodes[current_node.first].size())
        {
            std::list<int>::iterator it;

            // Get initial index for start of adjacency_list and get the node required by the counter.
            it = this->adjacent_nodes[current_node.first].begin(); for (int i = 0; i < current_node.second; ++i) { ++it; }
            int next_node = *it;

            // If the next_node has been seen, then there is a cycle.
            // If the next_node is located then a cycle will form staying within current node.
            if (this->visited[next_node])
            {
                this->cycle = true;

                ++cycle_count;

                std::cout << next_node << " is head of { ";

                std::stack<std::pair<int, int> > stack_copy = this->stack;

                std::vector<int> vector_stack;

                // Generating CBMC format for the output...
                while (! stack_copy.empty())
                {
                    int node_copy = stack_copy.top().first;

                    vector_stack.push_back(node_copy);

                    stack_copy.pop();
                }

                std::reverse(vector_stack.begin(), vector_stack.end());

                for (int counter = 0; counter < vector_stack.size(); ++counter)
                {
                    if (counter == vector_stack.size() - 1)
                    {
                        std::cout <<  vector_stack.back() <<" (backedge) }" << std::endl;
                    }
                    else
                    {
                        std::cout << vector_stack[counter] << ", ";
                    }
                }
            }

            // Iterate the index for the current node.
            this->stack.top().second++;

            // If it is a cycle, then new node is NOT placed on the stack as it will be an infinite loop.
            if (! cycle)
            {
                this->stack.push(std::pair(next_node, 0));
            }
        }
        else
        {
            // Remove node after it has been accessed and all elements in adjacency_list[node]
            // have been placed on the stack.
            stack.pop();
            continue;
        }
    }

    if (this->cycle)
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