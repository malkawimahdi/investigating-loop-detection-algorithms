// GitHub: 1 parent 5a2ff1b commit 26530c4

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
    if ((this->adjacent_nodes[current_node].size() > 1))
    {
        throw std::runtime_error("Graph can contain AT MOST two children.");
    }
    else
    {
        // Add adjacent nodes reachable from current node.
        this->adjacent_nodes[current_node].push_back(adjacent_node);
        // Add current_node for adjacent node to allow backwards traversal of graph.
        this->backwards_predecessors[adjacent_node].push_back(current_node);
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
std::set<int> Graph::computeDominators(int node)
{
    // Locates the entry node in the graph, which should typically be the first node in the graph that has an adjacent
    // node as the start by convention.
    for (int counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            this->first_node = counter;
            break;
        }
    }

    if (this->first_node == UINT_MAX)
    {
        throw std::runtime_error("No node(s) detected.");
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
            // Working set to recursively fill the previous dominators of the next node after entry.
            std::set<int> working = computeDominators(*this->backwards_predecessors[node].begin());

            // Traverse through the backwards control flow graph, looking forwards.
            std::set<int> intersection_single_parent_node;

            for (std::list<int>::iterator it = this->backwards_predecessors[node].begin();
                 it != this->backwards_predecessors[node].end(); ++it)
            {
                std::set<int> intersection_dual_parent_nodes;

                // If a node has two parents, then both sets are required to be intersected otherwise the first set
                // i.e. the left side of a control flow graph will be used. Will occur in diamond shapes
                    // analogous to if-else statements.
                if (this->backwards_predecessors[node].size() == 2)
                {
                    int first_parent_node = this->backwards_predecessors[node].front();
                    int second_parent_node = this->backwards_predecessors[node].back();

                    std::set<int> first_parent_node_set = computeDominators(first_parent_node);
                    std::set<int> second_parent_node_set = computeDominators(second_parent_node);

                    std::set_intersection(first_parent_node_set.begin(),
                                          first_parent_node_set.end(),
                                          second_parent_node_set.begin(),
                                          second_parent_node_set.end(),
                                          std::inserter(intersection_dual_parent_nodes,
                                                        intersection_dual_parent_nodes.begin()));

                    // Insert the current node to fulfill the dominator relationship that each node dominates itself.
                    intersection_dual_parent_nodes.insert(node);

                    for(auto it = intersection_dual_parent_nodes.begin();
                            it != intersection_dual_parent_nodes.end(); it++)
                    {
                        this->dominators[node].insert(*it);
                    }
                }
                else
                {
                    std::set<int> result = computeDominators(*it);

                    // Sets are required to be intersected, to ensure that the parent of the current AND the current
                    // only contain the same nodes to verify that only nodes that dominate the current node are
                    // included.
                    // Only works for a single parent.
                    std::set_intersection(result.begin(),
                                          result.end(),
                                          working.begin(),
                                          working.end(),
                                          std::inserter(intersection_single_parent_node,
                                                        intersection_single_parent_node.begin()));

                    // Insert the current node to fulfill the dominator relationship that each node dominates itself.
                    intersection_single_parent_node.insert(node);

                    for(auto it = intersection_single_parent_node.begin();
                        it != intersection_single_parent_node.end(); it++)
                    {
                        this->dominators[node].insert(*it);
                    }
                }
            }
            return this->dominators[node];
        }
    }
}
