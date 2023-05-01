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

// This constructor is derived from (GeeksForGeeks, 2023), specifically the generation of how the digraph is
    // represented as an adjacency list.
// Constructor takes number of nodes and generates a list containing an entry the size of nodes.
Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->visited.resize(this->nodes);
    this->adjacent_nodes = new std::list<int>[nodes];
    this->backwards_predecessors = new std::list<int>[nodes];
}

// This function is derived from (GeeksForGeeks, 2023) with the difference of creating another representation of
    // the graph which looks backwards.
// Add an edge to current graph in the directed form: currentNode -> adjacentNode.
void Graph::addEdge(int current_node, int adjacent_node)
{
    // Add adjacent nodes reachable from current node.
    this->adjacent_nodes[current_node].push_back(adjacent_node);

    // Current node points to the parent.
    this->backwards_predecessors[adjacent_node].push_back(current_node);
}

//After significant debugging and meetings with Dr Martin Nyx Brain, the previous dominators' algorithm, located
    // at the bottom had a fatal flaws which meant that the algorithm could continuously cycle over itself AND
        // that the algorithm could not detect all dominators of a given node if the node contained more than two children.
// Received assistance from Dr Martin Nyx Brain within a meeting to ,discuss pseudocode representation of the algorithm required
    // and debugging to fix intersection of nodes that have more than a single child.
void Graph::computeDominators(void)
{
    // Stack for iterative Depth First Search.
    std::stack<int> stack;

    // dom(n0) = {n0}
    this->dominators[this->first_node].insert(this->first_node);

    // Push the first node to initiate the iterative depth first traversal...
    stack.push(this->first_node);

    while (! stack.empty())
    {
        int current = stack.top();
        stack.pop();

        // Look at each child for the set of dominators...
        for (std::list<int>::iterator it = this->adjacent_nodes[current].begin();
             it != this->adjacent_nodes[current].end(); ++it)
        {
            if (this->dominators[*it].empty())
            {
                // Get the parent nodes dominators and fill it in initially.
                this->dominators[*it] = this->dominators[current];

                // Add itself to the set of dominators to fulfill the relationship that each node dominates itself.
                this->dominators[*it].insert(*it);

                // Push it onto the stack to be seen next...
                stack.push(*it);
            }
                // This node has been previously seen before...
            else
            {
                // Store the old dominators of the child temporarily...
                std::set<int> old_child_result = this->dominators[*it];

                // Receive the dominators of the parent.
                std::set<int> new_child_result = this->dominators[current];

                // Add the current node to itself as it can be removed from the set of dominators from itself
                    // in an intersection from the previous and current results.
                new_child_result.insert(*it);

                // Intersecting the parent and child each time to yield a set of dominators that is updated to represent
                    // the dominator set for each child. Each child will have to have the set of dominators of the parent
                        // and itself after intersected to ensure dominator relationship that would not be correct
                            // if nodes with multiple parents were not accounted for.
                std::set<int> intersection_result;
                
                std::set_intersection(old_child_result.begin(),
                                      old_child_result.end(),
                                      new_child_result.begin(),
                                      new_child_result.end(),
                                      std::inserter(intersection_result, intersection_result.begin()));

                // Clear previous dominators and insert new dominators for child.
                this->dominators[*it].clear();
                this->dominators[*it] = intersection_result;

                // If the dominators have changed then for the current child then propagate these changes
                    // to its descendants.
                if (this->dominators[*it].size() < old_child_result.size())
                {
                    stack.push(*it);
                }
            }
        }
    }
}

// Generate the set of dominators for each node within the control flow graph.
void Graph::computeDominatorsOutput(void)
{
    std::cout << "First Node: " << this->first_node << std::endl;

    std::cout << std::endl;

    for(std::size_t counter = this->first_node; counter < this->nodes; ++counter)
    {
        std::cout << "Dominators for node: " << counter << std::endl;

        for(std::set<int>::iterator it = this->dominators[counter].begin(); it != this->dominators[counter].end(); ++it)
        {
            std::cout << *it << ",";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* Computes natural loops within a graph:
Based on (Aho et al. 2006) Compilers: Principles, Techniques, and Tools (2nd Edition)

" A natural loop is defined by two essential properties.

1. It must have a single-entry node, called the header. This entry node dominates all nodes within the loop
   or, it would not be the sole entry within the loop.

2. There must be a back edge that enters the loop header. Otherwise, it is not possible fot the flow control,
   to return to the header directly from the "loop"; i.ie., there really was no loop." (Aho et al. 2006) */

// Received assistance from Dr Martin Nyx Brain, with accessing the adjacency_list for each node iteratively
    // from an adjacency list, randomly accessing a std::list and going through the stack once more.
// Implementation of cycle detection using iterative Depth First Search using ONLY the start node to check for cycles
    // and output nodes contained within cycles.
// Ensures that inaccessible nodes (inaccessible code) is not reached.
// Outputs detected cycles in the same way as CBMC.
bool Graph::naturalLoops(void)
{
    bool cycle = false;
    bool no_cycle = true;

    // Stack for iterative Depth First Search.
    // (Current node, Index at adjacency_list for current node).
    std::stack<std::pair<int, int> > stack;

    // Locates the entry node in the graph, which should typically be the first node in the graph that has an adjacent
    // node as the start by convention.
    for (std::size_t counter = 0; counter < this->nodes; ++counter)
    {
        if (this->adjacent_nodes[counter].size() > 0)
        {
            this->first_node = counter;

            // Each node is viewed as a pair in the form of std::pair<node, index>
            stack.push(std::make_pair(counter, 0));
            break;
        }
    }

    // Are there any nodes for the graph?
    if (this->first_node == UINT_MAX)
    {
        throw std::runtime_error("No Node(s) Are Locatable.");
    }

    // Iterative Depth First Traversal.
    while (!stack.empty())
    {
        // Get the top most node and visit it.
        std::pair<int, int> current_node = stack.top();

        this->visited[(current_node.first)] = true;

        // If the index of the second node is less than the size of the elements in the adjacency list...
        if (current_node.second < this->adjacent_nodes[current_node.first].size())
        {
            // Get initial index for start of adjacency_list and get the node required by the counter.
            // Received assistance from Dr Martin Nyx Brain, randomly accessing a std::list.
            std::list<int>::iterator it = this->adjacent_nodes[current_node.first].begin();

            for (unsigned int i = 0; i < current_node.second; ++i)
            {
                ++it;
            }

            int next_node = *it;


            // If the next_node has been seen within the control flow graph, and it is currently in the stack,
                // this resolves the problem of viewing a half of the diamond commonly located within an if else
                    // statement ensuring that the whole diamond is traversed, suggested by Dr Martin Nyx Brain.

            // An additional condition required is that for a natural loop to be present, is for the set of
                // dominators for the back edge to contain the head to ensure that the loop head dominates the
                    //  tail (back edge). The secondary condition required, is that the back edge enters the loop header
                        // which this algorithm fulfills.

            // next_node is head i.e. duplicate node.
            // current_node.first points to the duplicate node meaning it is the back edge.
            // Separately checking guards was suggested by Dr Martin Nyx Brain to not incorrectly detect enter the cycle
                // condition, as it is possible to enter a loop that is not a natural loop.
            if ((this->visited[next_node]) && (stackChecker(next_node, stack)))
            {
                    cycle = true;

                    // Only compute dominators if there is a possibility of detecting a natural loop.
                    if (no_cycle)
                    {
                        this->computeDominators();
                        no_cycle = false;
                    }

                    if (isElementContained(next_node, this->dominators[current_node.first]))
                    {
                        // Required as cycle is reset after each iteration, this is used for the function output.
                        this->is_there_a_cycle = true;

                        this->cycle_count++;

                        // Generates output which contains nodes in the cycle specifically in the same format as CBMC.
                        //cbmcCycleOutput(next_node, this->stack);
                        computeNaturalLoop(next_node, current_node.first);
                    }
            }

            // Iterate the index for the current node.
            stack.top().second++;

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

    cbmcCycleOutput(this->natural_loops);
    
    unreachableNodes(this->first_node, this->visited);

    if (cycle_count > 0)
    {
        std::cout << "Cycle(s): " << this->cycle_count << std::endl;
    }
    else
    {
        std::cout << "No Cycle(s) Detected!" << std::endl;
    }

    return this->is_there_a_cycle;
}

// Computes the natural loop from a natural loop boundary such that all nodes from the back edge UP TO the
    // head are traversed and such that the nodes traversed stay within the natural region to not accidentally
        // traverse outside the natural loop region.
// (Aho et al. 2006) notes that if multiple loops have the same header, then they are treated as a single cycle.
void Graph::computeNaturalLoop(int head, int tail)
{
    std::stack<int> stack;

    this->natural_loops[head].insert(head);
    this->natural_loops[head].insert(tail);

    if (head != tail)
    {
        stack.push(tail);
    }

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        for (   std::list<int>::iterator it = this->backwards_predecessors[current].begin();
             it != this->backwards_predecessors[current].end(); ++it)
        {
            // If the node being looked at is not in the set of current nodes and the node lies bounded between the
                // head and tail and for the set of dominators in the current node, the head is contained, then
                    // add it to the set of instructions for the current loop head and add it to the stack so it can
                        // be traversed iteratively next.
            if (!isElementContained(*it, this->natural_loops[head])
            && (head < *it < tail)
            && isElementContained(head, this->dominators[*it]))
            {
                this->natural_loops[head].insert(*it);
                stack.push(*it);
            }
        }
    }
}
