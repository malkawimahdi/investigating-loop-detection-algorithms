//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{

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
    
// Dr Martin Nyx Brain loop-empty
//     Graph graph(1);
//     graph.addEdge(0, 0);
    
// Dr Martin Nyx Brain loop-sequence-of-instructions
// TODO:
//     Graph graph(1);
//     graph.addEdge(0, 0);
    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
