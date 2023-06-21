//
// Created by Mahdi Malkawi on 29/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include "Graph.h"

#include <sstream>

// Graph Parser, parsing edges as pairs from 1st->2nd, 3rd->4th ...
Graph graphParser(const std::string &string);

#endif // UTILITIES_H
