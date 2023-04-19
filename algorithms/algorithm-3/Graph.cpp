// NOTICE: Graph.cpp utilises a minimal proportion of code snippets for general structure
    // with no specified license located at:

// Title: Detect Cycle in a Directed Graph
// Author: GeeksForGeeks
// Year: 2023
// URL: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// URL Date: 22nd March 2023

//
// Created by Mahdi Malkawi on 05/03/2023.
//

#include "Graph.h"
#include "Utilities.h"

// This constructor is derived from (GeeksForGeeks, 2023), specifically the generation of how the diagraph is
    // represented as an adjacency list.
// Constructor takes number of nodes and generates a list containing an entry the size of nodes.
// (Doubly Linked List)
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->visited.resize(this->nodes);
    this->adjacent_nodes = new std::list<int>[nodes];
    this->backwards_predecessors = new std::list<int>[nodes];
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of limiting the number of adjacent nodes.
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
// Follows the property of a Control Flow Graph (CFG), whereby each node can have AT MOST two other adjacent nodes.
void Graph::addEdge(int current_node, int adjacent_node)
{
    // Add adjacent nodes reachable from current node.
    this->adjacent_nodes[current_node].push_back(adjacent_node);
    // Add current_node for adjacent node to allow backwards traversal of graph.
    this->backwards_predecessors[adjacent_node].push_back(current_node);
}

// Locates the entry node in the graph, which should typically be the first node in the graph that has an adjacent
    // node as the start by convention.
void Graph::initalise()
{
    for (int counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            std::cout << "First: " << counter << std::endl;
            this->first_node = counter;
            break;
        }
    }

    if (this->first_node == UINT_MAX)
    {
        throw std::runtime_error("No node(s) detected.");
    }
}

// Received assistance from Dr Martin Nyx Brain, firstly by using pseudocode representation of the algorithm required:
/*
 *  std::map <int, set>
 *
 * function(int node)
 * {
 * make sure node is not < 0
 * if it is in the map for the node return else:
 *
 * if it is the first node in the graph, and it is the first node, the set = itself and return and set in the map.
 *
 * else:
 * for loop recursively calling function from all nodes previously from current node and intersect results you get back.
 *
 * then add yourself to the set, store in the map and return.
 * }
 */

// Received significant assistance from Dr. Martin Nyx Brain
    // constructing the algorithm particularly with line 107 and lines 146 to 160.
// Compute the dominators set of a control flow graph, using memoization.
// Works partially as it over approximates the dominators for the current node if the control flow graph contains a cycle.
std::set<int> Graph::computeDominators(int node)
{
    if (! visited[node])
    {
        visited[node] = true;
    }
    else
    {
        std::set<int> all_nodes;

        for (int counter = this->first_node; counter < this->nodes; ++counter)
        {
            all_nodes.insert(counter);
        }
        return all_nodes;
    }

    // Check if dominators are already filled for this node.
    // If so just return the set.
    if (!this->dominators[node].empty())
    {
        return this->dominators[node];
    }

    // Means the set of dominators for the node is empty...
    else
    {
        // Check if the empty node is the first node...
        if (node == this->first_node)
        {
            // Current node dominates itself, so place it in the set of dominators for itself.
            this->dominators[node].insert(node);
            return this->dominators[node];
        }
        // The set of dominators is empty, and it is not the first node.
        else
        {
            // If there is one previous node, just receive results of previous node and add current node to dominators
                // to receive dominators for the current set.
            if (this->backwards_predecessors[node].size() == 1)
            {
                std::set<int> result = computeDominators(this->backwards_predecessors[node].front());

                // Insert the current node to fulfill the dominator relationship that each node dominates itself.
                result.insert(node);

                for(std::set<int>::iterator it = result.begin();
                    it != result.end(); ++it)
                {
                    this->dominators[node].insert(*it);
                }

                return this->dominators[node];
            }
            // Two or more predecessors...
            else if (this->backwards_predecessors[node].size() > 1)
            {
                std::set<int> working = computeDominators(this->backwards_predecessors[node].front());

                std::set<int> results2;

                // For each predecessor compute dominators and intersect the results returned by the first call
                    // to computeDominators stored in working2.
                // Do this for EVERY immediate predecessor.
                for (std::list<int>::iterator it = this->backwards_predecessors[node].begin();
                     it != this->backwards_predecessors[node].end(); ++it)
                {

                    std::set<int> compute = computeDominators(*it);

                    std::set_intersection(working.begin(),
                                          working.end(),
                                          compute.begin(),
                                          compute.end(),
                                          std::inserter(results2, results2.begin()));
                }

                    results2.insert(node);

                    for(std::set<int>::iterator it = results2.begin();
                        it != results2.end(); ++it)
                    {
                        this->dominators[node].insert(*it);
                    }
                    return this->dominators[node];
            }
        }
    }
}

// Generates a dominator tree based on the dominator relationship.
// Based on (Aho et al. 2006) Compilers: Principles, Techniques, and Tools (2nd Edition)
//Graph Graph::dominatorTree()
//{
//
//    std::string dominator_tree_output = "";
//
//    // Compute the dominators for every node.
//    for (int counter = this->first_node; counter < this->nodes; ++counter)
//    {
//        std::set<int> dominators_for_current_node = computeDominators(counter);
//
//        // Reverse from the tree, looking for the first index that is not the current node,
//            // ensuring that it is the immediate dominator, which is required to build the dominator tree.
//        for (std::set<int>::reverse_iterator it = dominators_for_current_node.rbegin();
//        it != dominators_for_current_node.rend(); ++it)
//        {
//            if (*it == counter)
//            {
//                continue;
//            }
//            else if (*it != counter)
//            {
//                dominator_tree_output.append(std::to_string(*it));
//                dominator_tree_output.append(",");
//                dominator_tree_output.append(std::to_string(counter));
//                dominator_tree_output.append(",");
//                break;
//            }
//        }
//    }
//
//    dominator_tree_output.pop_back();
//
//    // Debug tool.
//    std::cout << dominator_tree_output << std::endl;
//
//    Graph dominator_tree = graphParser(dominator_tree_output);
//    return dominator_tree;
//}