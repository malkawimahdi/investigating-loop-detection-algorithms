//
// Created by Mahdi Malkawi on 14/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include "Graph.h"

#include <sstream>

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(const std::string &string);

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(const unsigned int &target, std::stack<std::pair<unsigned int, unsigned int> > stack);

// Generates output which contains nodes in the cycle specifically in the same format as CBMC.
void cbmcCycleOutput(std::map<unsigned int, std::set<unsigned int> > &cycle_nodes, std::map <unsigned int, std::set<unsigned int> > &back_edges);

// Checks if an element is contained within a set.
bool isElementContained(const unsigned int &parameter, const std::set<unsigned int> &set);
#endif // UTILITIES_H
