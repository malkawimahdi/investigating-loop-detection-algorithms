//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{
// Cyclic graph in a square: (0 -> 1), (1 -> 2), (2 -> 3), (3 -> 0)
// Back edge is (3 -> 0)
//    Graph graph(4);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);

// Micheal Wolfe Paper G1
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(0, 4);

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
//     Graph graph(7);
//     graph.addEdge(0, 1);
//     graph.addEdge(1, 2);
//     graph.addEdge(2, 3);
//     graph.addEdge(2, 4);
//     graph.addEdge(4, 5);
//     graph.addEdge(5, 6);
//     graph.addEdge(1, 5);
//     graph.addEdge(3, 1);
//     graph.addEdge(0, 6);
    
// Dr Martin Nyx Brain loop-empty
//     Graph graph(1);
//     graph.addEdge(0, 0);
    
// Dr Martin Nyx Brain loop-sequence-of-instructions
//     Graph graph(24);
//     graph.addEdge(0, 1);
//     graph.addEdge(1, 2);
//     graph.addEdge(2, 3);
//     graph.addEdge(2, 3);
//     graph.addEdge(3, 4);
//     graph.addEdge(4, 5);
//     graph.addEdge(5, 6);
//     graph.addEdge(6, 7);
//     graph.addEdge(7, 8);
//     graph.addEdge(8, 9);
//     graph.addEdge(9, 10);
//     graph.addEdge(10, 11);
//     graph.addEdge(11, 12);
//     graph.addEdge(12, 13);
//     graph.addEdge(13, 14);
//     graph.addEdge(14, 0);
//     graph.addEdge(5, 15);
//     graph.addEdge(15, 16);
//     graph.addEdge(16, 17);
//     graph.addEdge(17, 18);
//     graph.addEdge(18, 19);
//     graph.addEdge(18, 20);
//     graph.addEdge(20, 21);
//     graph.addEdge(21, 22);
//     graph.addEdge(22, 23);

    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
