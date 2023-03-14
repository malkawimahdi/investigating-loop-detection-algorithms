//
// Created by Mahdi Malkawi on 14/03/2023.
//

#include "Utilities.h"

// Takes an integer and checks if the integer is contained within the stack.
// If it is found in the stack return true, else return false.
bool stackChecker(int target, std::stack<std::pair<int, int>> stack)
{
    while (!stack.empty())
    {
        int current = stack.top().first;

        if (target == current)
        {
            return true;
        }
        stack.pop();
    }
    return false;
}