//
// Created by Mahdi Malkawi on 14/03/2023.
//

#include "Utilities.h"

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(std::string string)
{
    // Take an input graph as a command-line argument
    std::stringstream graph_string_stream(string);

    std::vector<unsigned int> graphEdges;

    unsigned int largest_node = 0;

    // Remove commas and whitespace.
    // Pair each node with the next node.
    // No additional information is required.
    // Remember that to parse that command-line arguments on zsh with whitespace,
        // need to be escaped in order to be accepted to argv as a single command.
    // Arguments can be escaped with "ARGUMENT_GOES_HERE".
    for (int current_node; graph_string_stream >> current_node;)
    {
        if (graph_string_stream.peek() == (',' | ' '))
        {
            graph_string_stream.ignore();
        }

        graphEdges.push_back(current_node);

        if (largest_node < current_node)
        {
            largest_node = current_node;
        }
    }

    // Ensure that all the input is valid; every node belongs to a pair.
    if (graphEdges.size() % 2 == 0)
    {
        // Largest node + 1 to account for 0-index
        Graph graph(largest_node + 1);

        // Use Duffs device to generate graph.
        for (int counter = 0; counter < graphEdges.size(); counter += 2)
        {
            // std::cout << "Current:" << graphEdges[counter] << " Adj:" << graphEdges[counter+1] << std::endl;
            graph.addEdge(graphEdges[counter], graphEdges[counter+1]);
        }

        return graph;
    }
    else
    {
        throw std::runtime_error("Pair(s) are missing values!");
    }
}

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(int target, std::stack<std::pair<int, int> > stack)
{
    while (!stack.empty())
    {
        int current = stack.top().first;

        if (target == current)
        {
            return true;
        }
        stack.pop();
    }
    return false;
}

// Generates output which contains nodes in the cycle specifically in the same format as CBMC.
void cbmcCycleOutput(int next_node, std::stack<std::pair<int, int> > stack)
{
    std::cout << next_node << " is head of { ";

    std::vector<int> vector;

    while (!stack.empty())
    {
        int node_copy = stack.top().first;

        if (node_copy == next_node)
        {
            vector.push_back(node_copy);
            break;
        }
        vector.push_back(node_copy);
        stack.pop();
    }

    std::reverse(vector.begin(), vector.end());

    for (std::size_t counter = 0; counter < vector.size(); ++counter)
    {
        if (counter == vector.size() - 1)
        {
            std::cout << vector.back() << " (backedge) }" << std::endl;
        }
        else
        {
            std::cout << vector[counter] << ", ";
        }
    }
}

// Detects unreachable nodes from the entry node.
// Formatted to look good :)
void unreachableNodes(unsigned int first_node, std::vector<bool> &visited)
{
    unsigned int unreachable_node_count = 0;

    for (std::size_t counter = first_node; counter < visited.size(); ++counter)
    {
        if (visited[counter] == false)
        {
            if (unreachable_node_count == 0)
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

    if (unreachable_node_count > 0)
    {
        std::cout << std::endl;
        std::cout << "Unreachable Node(s) Count: " << unreachable_node_count << std::endl;
    }
}