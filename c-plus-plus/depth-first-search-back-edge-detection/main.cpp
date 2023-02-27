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
    // Back edge is (3 -> 0)
//    Graph graph(4);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);

// Micheal Wolfe Paper G1
//    Graph graph(5);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 4);
//    graph.addEdge(0, 4);

// Micheal Wolfe Paper G2
//    Graph graph(6);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 3);
//    graph.addEdge(3, 4);
//    graph.addEdge(4, 2);
//    graph.addEdge(4, 5);
//    graph.addEdge(0, 5);

// Micheal Wolfe Paper G3
//    Graph graph(6);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 2);
//    graph.addEdge(3, 4);
//    graph.addEdge(4, 3);
//    graph.addEdge(4, 5);
//    graph.addEdge(0, 5);

// Micheal Wolfe Paper G4
//    Graph graph(6);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(2, 4);
//    graph.addEdge(4, 5);
//    graph.addEdge(3, 1);
//    graph.addEdge(4, 1);
//    graph.addEdge(0, 5);

// Micheal Wolfe Paper G5a
//    Graph graph(7);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(2, 4);
//    graph.addEdge(3, 5);
//    graph.addEdge(4, 5);
//    graph.addEdge(5, 6);
//    graph.addEdge(3, 1);
//    graph.addEdge(0, 6);

// Micheal Wolfe Paper G5b
//    Graph graph(7);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(2, 4);
//    graph.addEdge(4, 5);
//    graph.addEdge(5, 6);
//    graph.addEdge(1, 5);
//    graph.addEdge(3, 1);
//    graph.addEdge(0, 6);

// Dr Martin Nyx Brain loop-busy-wait
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(1, 5);
    graph.addEdge(3, 1);
    graph.addEdge(0, 6);
    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
