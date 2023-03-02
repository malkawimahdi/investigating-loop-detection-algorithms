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
    std::cout << "Micheal Wolfe Paper G1" << std::endl;
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(0, 4);

    // Micheal Wolfe Paper G2
    // std::cout << "Micheal Wolfe Paper G2" << std::endl;
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
    // std::cout << "Micheal Wolfe Paper G3" << std::endl;
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
    // std::cout << "Micheal Wolfe Paper G4" << std::endl;
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
    // std::cout << "Micheal Wolfe Paper G5a" << std::endl;
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
    // std::cout << "Micheal Wolfe Paper G5b" << std::endl;
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
    // std::cout << "Dr Martin Nyx Brain loop-busy-wait" << std::endl;
    //     Graph graph(6);
    //     graph.addEdge(0, 1);
    //     graph.addEdge(0, 2);
    //     graph.addEdge(1, 3);
    //     graph.addEdge(2, 4);
    //     graph.addEdge(3, 5);
    //     graph.addEdge(4, 0);

    // Dr Martin Nyx Brain loop-empty
    // std::cout << "Dr Martin Nyx Brain loop-empty" << std::endl;
    //     Graph graph(1);
    //     graph.addEdge(0, 0);

    // Dr Martin Nyx Brain loop-sequence-of-instructions
    // std::cout << "Dr Martin Nyx Brain loop-sequence-of-instructions" << std::endl;
    //     Graph graph(24);
    //     graph.addEdge(0, 1);
    //     graph.addEdge(1, 2);
    //     graph.addEdge(2, 3);
    //     graph.addEdge(3, 4);
    //     graph.addEdge(4, 5);
    //     graph.addEdge(5, 6);
    //     graph.addEdge(5, 7);
    //     graph.addEdge(6, 8);
    //     graph.addEdge(7, 9);
    //     graph.addEdge(8, 10);
    //     graph.addEdge(9, 11);
    //     graph.addEdge(10, 12);
    //     graph.addEdge(11, 13);
    //     graph.addEdge(12, 14);
    //     graph.addEdge(13, 15);
    //     graph.addEdge(13, 17);
    //     graph.addEdge(14, 16);
    //     graph.addEdge(15, 17);
    //     graph.addEdge(16, 18);
    //     graph.addEdge(17, 19);
    //     graph.addEdge(18, 20);
    //     graph.addEdge(19, 21);
    //     graph.addEdge(20, 22);
    //     graph.addEdge(21, 23);
    //     graph.addEdge(2, 11);
    //     graph.addEdge(10, 15);
    //     graph.addEdge(22, 0);

    std::cout << (graph.containsCycle() ? "True" : "False") << std::endl;

    return 0;
}
