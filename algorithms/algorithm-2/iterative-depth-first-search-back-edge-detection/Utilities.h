//
// Created by Mahdi Malkawi on 14/03/2023.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stack>

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(int target, std::stack<std::pair<int, int> > stack);

#endif // UTILITIES_H
