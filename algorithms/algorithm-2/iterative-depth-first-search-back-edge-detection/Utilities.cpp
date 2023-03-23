//
// Created by Mahdi Malkawi on 14/03/2023.
//

#include "Utilities.h"

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

    for (unsigned int counter = 0; counter < vector.size(); ++counter)
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
void unreachableNodes(unsigned int first_node, unsigned int nodes, std::vector<bool> visited)
{
    unsigned int unreachable_node_count = 0;

    for (unsigned int counter = first_node; counter < visited.size(); ++counter)
    {
        if (!visited[counter])
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