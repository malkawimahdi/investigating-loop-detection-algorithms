//
// Created by Mahdi Malkawi on 14/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include "Graph.h"

#include <sstream>

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(std::string string);

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(int target, std::stack<std::pair<int, int> > stack);

// Generates output which contains nodes in the cycle specifically in the same format as CBMC.
void cbmcCycleOutput(std::map<int, std::set<int> > cycle_nodes);

// Detects unreachable nodes from the entry node.
void unreachableNodes(unsigned int& first_node, std::vector<bool> &visited);

// Checks if an element is contained within a set.
bool isElementContained(const int &parameter, const std::set<int>& set);
#endif // UTILITIES_H
