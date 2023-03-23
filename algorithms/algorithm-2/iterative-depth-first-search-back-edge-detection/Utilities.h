//
// Created by Mahdi Malkawi on 14/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stack>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(int target, std::stack<std::pair<int, int> > stack);

// Generates output which contains nodes in the cycle specifically in the same format as CBMC.
void cbmcCycleOutput(int next_node, std::stack<std::pair<int, int> > stack);

// Detects unreachable nodes from the entry node.
void unreachableNodes(unsigned int first_node, unsigned int nodes, std::vector<bool> visited);

#endif // UTILITIES_H
