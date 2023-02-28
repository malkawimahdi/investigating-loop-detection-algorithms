//
// Created by Mahdi Malkawi on 08/02/2023.
// main.cpp
//

#include "Graph.h"
#include <iostream>

int main(void)
{
    
// Dr Martin Nyx Brain loop-sequence-of-instructions
     Graph graph(24);
     graph.addEdge(0, 1);
     graph.addEdge(1, 2);
     graph.addEdge(2, 3);
     graph.addEdge(2, 3);
     graph.addEdge(3, 4);
     graph.addEdge(4, 5);
     graph.addEdge(5, 6);
     graph.addEdge(6, 7);
     graph.addEdge(7, 8);
     graph.addEdge(8, 9);
     graph.addEdge(9, 10);
     graph.addEdge(10, 11);
     graph.addEdge(11, 12);
     graph.addEdge(12, 13);
     graph.addEdge(13, 14);
     graph.addEdge(14, 0);
     graph.addEdge(5, 15);
     graph.addEdge(15, 16);
     graph.addEdge(16, 17);
     graph.addEdge(17, 18);
     graph.addEdge(18, 19);
     graph.addEdge(18, 20);
     graph.addEdge(20, 21);
     graph.addEdge(21, 22);
     graph.addEdge(22, 23);
    std::cout << (graph.containsCycle() ? "True" : "False");

    return 0;
}
