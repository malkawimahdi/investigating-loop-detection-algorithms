//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{
    
// Dr Martin Nyx Brain loop-empty
     Graph graph(1);
     graph.addEdge(0, 0);
    
// Dr Martin Nyx Brain loop-sequence-of-instructions
// TODO:
//     Graph graph(1);
//     graph.addEdge(0, 0);
    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
