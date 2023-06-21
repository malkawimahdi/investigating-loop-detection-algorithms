//
// Created by Mahdi Malkawi on 14/03/2023.
//

#include "Utilities.h"

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(const std::string &string)
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
        if (current_node < 0)
        {
            throw std::runtime_error("Nodes cannot have a value less than 0!");
        }
        else
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
    }

    // Ensure that all the input is valid; every node belongs to a pair.
    if (graphEdges.size() % 2 == 0)
    {
        // Largest node + 1 to account for 0-index
        Graph graph(largest_node + 1);

        // Use Duffs device to generate graph.
        for (std::size_t counter = 0; counter < graphEdges.size(); counter += 2)
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
bool stackChecker(const unsigned int &target, std::stack<std::pair<unsigned int, unsigned int> > stack)
{
    while (!stack.empty())
    {
        unsigned int current = stack.top().first;

        if (target == current)
        {
            return true;
        }
        stack.pop();
    }
    return false;
}

// Generates output which contains nodes in the cycle specifically in the same format as CBMC.
void cbmcCycleOutput(std::map<unsigned int, std::set<unsigned int> > &cycle_nodes, std::map <unsigned int, std::set<unsigned int> > &back_edges)
{
    for (std::map<unsigned int, std::set<unsigned int> >::iterator it = cycle_nodes.begin();
    it != cycle_nodes.end(); ++it)
    {
        std::cout << it->first << " is head of { ";

        for(std::set<unsigned int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            if (it2 != it->second.begin())
            {
                std::cout << ", ";
            }

            if(isElementContained(*it2, back_edges[it->first]))
            {
                std::cout << *it2 << " (backedge)";
            }
            else
            {
                std::cout << *it2;
            }
        }
        std::cout << " }" << std::endl;
    }
}

// Checks if an element is contained within a set.
bool isElementContained(const unsigned int &parameter, const std::set<unsigned int> &set)
{
    return set.find(parameter) != set.end();
}