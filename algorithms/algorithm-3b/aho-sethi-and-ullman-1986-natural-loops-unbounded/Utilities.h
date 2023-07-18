//
// Created by Mahdi Malkawi on 14/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include "Graph.h"

#include <sstream>

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(const std::string &string);

// Takes a node and checks if the node is in the stack returning true, else false.
bool stackChecker(const unsigned int &target, std::stack<std::pair<unsigned int, unsigned int> > stack);

// Checks if an element is contained within a set.
bool isElementContained(const unsigned int &parameter, const std::set<unsigned int> &set);

#endif // UTILITIES_H