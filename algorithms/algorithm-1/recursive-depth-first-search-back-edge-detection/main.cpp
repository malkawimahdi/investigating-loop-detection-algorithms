//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{
//    std::cout << "Back Edge Present with Unreachable Nodes" << std::endl;
//    Graph graph(5);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);
//    graph.addEdge(4, 4);

    // CBMC Micheal Wolfe Paper G1
    // std::cout << "CBMC Micheal Wolfe Paper G1" << std::endl;
    Graph graph(15);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(8, 2);
    graph.addEdge(6, 9);
    graph.addEdge(9, 10);
    graph.addEdge(10, 11);
    graph.addEdge(11, 12);
    graph.addEdge(12, 13);
    graph.addEdge(13, 14);

    // CBMC Micheal Wolfe Paper G2
    // std::cout << "CBMC Micheal Wolfe Paper G2" << std::endl;
    // Graph graph(18);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(7, 8);
    // graph.addEdge(8, 5);
    // graph.addEdge(5, 9);
    // graph.addEdge(9, 10);
    // graph.addEdge(10, 11);
    // graph.addEdge(11, 12);
    // graph.addEdge(12, 2);
    // graph.addEdge(2, 13);
    // graph.addEdge(13, 14);
    // graph.addEdge(14, 15);
    // graph.addEdge(15, 16);
    // graph.addEdge(16, 17);

    // CBMC Micheal Wolfe Paper G3
    // std::cout << "CBMC Micheal Wolfe Paper G3" << std::endl;
    // Graph graph(28);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(7, 8);
    // graph.addEdge(6, 8);
    // graph.addEdge(8, 9);
    // graph.addEdge(9, 10);
    // graph.addEdge(10, 11);
    // graph.addEdge(11, 12);
    // graph.addEdge(12, 13);
    // graph.addEdge(13, 14);
    // graph.addEdge(12, 15);
    // graph.addEdge(15, 11);
    // graph.addEdge(14, 17);
    // graph.addEdge(17, 18);
    // graph.addEdge(18, 12);
    // graph.addEdge(18, 19);
    // graph.addEdge(19, 20);
    // graph.addEdge(20, 21);
    // graph.addEdge(21, 22);
    // graph.addEdge(22, 23);
    // graph.addEdge(23, 24);
    // graph.addEdge(24, 25);
    // graph.addEdge(25, 26);
    // graph.addEdge(26, 27);

    // CBMC Micheal Wolfe Paper G4
    // std::cout << "CBMC Micheal Wolfe Paper G4" << std::endl;
    // Graph graph(13);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(7, 8);
    // graph.addEdge(8, 9);
    // graph.addEdge(9, 2);
    // graph.addEdge(7, 12);
    // graph.addEdge(12, 2);

    // CBMC Micheal Wolfe Paper G5a
    // std::cout << "CBMC Micheal Wolfe Paper G5a" << std::endl;
    // Graph graph(9);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 2);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(7, 8);

    // CBMC Micheal Wolfe Paper G5b
    // std::cout << "CBMC Micheal Wolfe Paper G5b" << std::endl;
    //  Graph graph(10);
    //  graph.addEdge(0, 1);
    //  graph.addEdge(1, 2);
    //  graph.addEdge(2, 3);
    //  graph.addEdge(3, 4);
    //  graph.addEdge(4, 2);
    //  graph.addEdge(2, 5);
    //  graph.addEdge(5, 6);
    //  graph.addEdge(6, 7);
    //  graph.addEdge(7, 8);
    //  graph.addEdge(8, 9);

    // Dr Martin Nyx Brain loop-busy-wait
    // std::cout << "Dr Martin Nyx Brain loop-busy-wait" << std::endl;
    //   Graph graph(20);
    //   graph.addEdge(14, 15);
    //   graph.addEdge(15, 16);
    //   graph.addEdge(16, 14);
    //   graph.addEdge(14, 17);
    //   graph.addEdge(17, 18);
    //   graph.addEdge(18, 19);

    // Dr Martin Nyx Brain loop-empty
    // std::cout << "Dr Martin Nyx Brain loop-empty" << std::endl;
    //    Graph graph(21);
    //     graph.addEdge(20, 20);


// Dr Martin Nyx Brain loop-sequence-of-instructions
// std::cout << "Dr Martin Nyx Brain loop-sequence-of-instructions" << std::endl;
//         Graph graph(51);
//         graph.addEdge(26, 27);
//         graph.addEdge(27, 28);
//         graph.addEdge(28, 29);
//         graph.addEdge(29, 30);
//         graph.addEdge(30, 31);
//         graph.addEdge(31, 32);
//         graph.addEdge(32, 33);
//         graph.addEdge(31, 35);
//         graph.addEdge(35, 36);
//         graph.addEdge(36, 37);
//         graph.addEdge(37, 38);
//         graph.addEdge(38, 39);
//         graph.addEdge(39, 40);
//         graph.addEdge(40, 41);
//         graph.addEdge(41, 42);
//         graph.addEdge(42, 43);
//         graph.addEdge(43, 26);
//         graph.addEdge(28, 44);
//         graph.addEdge(33, 44);
//         graph.addEdge(44, 45);
//         graph.addEdge(45, 46);
//         graph.addEdge(46, 47);
//         graph.addEdge(45, 47);
//         graph.addEdge(47, 48);
//         graph.addEdge(48, 49);
//         graph.addEdge(49, 50);

// Mahdi Malkawi do-while-loop
// std::cout << "Mahdi Malkawi do-while-loop" << std::endl;
// Graph graph(13);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 4);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 11);
// graph.addEdge(11, 12);

// Mahdi Malkawi for-loop
// std::cout << "Mahdi Malkawi for-loop" << std::endl;
// Graph graph(17);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 6);
// graph.addEdge(6, 10);
// graph.addEdge(10, 11);
// graph.addEdge(11, 12);
// graph.addEdge(12, 13);
// graph.addEdge(13, 14);
// graph.addEdge(14, 15);
// graph.addEdge(15, 16);

// Mahdi Malkawi while-loop
// std::cout << "Mahdi Malkawi while-loop" << std::endl;
// Graph graph(14);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 4);
// graph.addEdge(4, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 11);
// graph.addEdge(11, 12);
// graph.addEdge(12, 13);    
    
    graph.containsCycle();
    return 0;
}
