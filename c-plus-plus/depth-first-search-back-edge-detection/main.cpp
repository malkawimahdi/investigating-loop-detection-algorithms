//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{
    // TODO: Create additional test cases.
    // Place results in comments next to the test case.
    // Cyclic graph in a square: (0 -> 1), (1 -> 2), (2 -> 3), (3 -> 0)
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
