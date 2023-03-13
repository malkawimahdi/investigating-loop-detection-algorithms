#include "Graph.h"

int main(void)
{
    // Cyclic graph in a square: (0 -> 1), (1 -> 2), (2 -> 3), (3 -> 0)
    // Back edge is (3 -> 0)
    //    Graph graph(4);
    //    graph.addEdge(0, 1);
    //    graph.addEdge(1, 2);
    //    graph.addEdge(2, 3);
    //    graph.addEdge(3, 0);

    // // Micheal Wolfe Paper G1
    std::cout << "Micheal Wolfe Paper G1" << std::endl;
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(0, 4);

    // CBMC Micheal Wolfe Paper G1
    // std::cout << "CBMC Micheal Wolfe Paper G1" << std::endl;
    // Graph graph(15);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(6, 8);
    // graph.addEdge(7, 9);
    // graph.addEdge(9, 11);
    // graph.addEdge(11, 12);
    // graph.addEdge(12, 13);
    // graph.addEdge(13, 14);
    // graph.addEdge(8, 10);
    // graph.addEdge(10, 2);

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

    // CBMC Micheal Wolfe Paper G2
    // std::cout << "CBMC Micheal Wolfe Paper G2" << std::endl;
    // Graph graph(18);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(2, 4);
    // graph.addEdge(3, 5);
    // graph.addEdge(5, 7);
    // graph.addEdge(7, 9);
    // graph.addEdge(4, 6);
    // graph.addEdge(6, 8);
    // graph.addEdge(8, 10);
    // graph.addEdge(8, 11);
    // graph.addEdge(9, 12);
    // graph.addEdge(10, 13);
    // graph.addEdge(13, 15);
    // graph.addEdge(15, 17);
    // graph.addEdge(17, 2);
    // graph.addEdge(11, 14);
    // graph.addEdge(14, 16);
    // graph.addEdge(16, 8);

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

    // CBMC Micheal Wolfe Paper G3
    // std::cout << "CBMC Micheal Wolfe Paper G3" << std::endl;
    // Graph graph(27);
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
    // graph.addEdge(12, 14);
    // graph.addEdge(14, 11);
    // graph.addEdge(13, 15);
    // graph.addEdge(15, 16);
    // graph.addEdge(16, 17);
    // graph.addEdge(17, 12);
    // graph.addEdge(17, 18);
    // graph.addEdge(18, 19);
    // graph.addEdge(19, 20);
    // graph.addEdge(20, 21);
    // graph.addEdge(21, 22);
    // graph.addEdge(22, 23);
    // graph.addEdge(23, 24);
    // graph.addEdge(24, 25);
    // graph.addEdge(25, 26);

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
    
    // CBMC Micheal Wolfe Paper G4
    // std::cout << "CBMC Micheal Wolfe Paper G4" << std::endl;
    // Graph graph(11);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);
    // graph.addEdge(6, 7);
    // graph.addEdge(7, 8);
    // graph.addEdge(7, 9);
    // graph.addEdge(8, 10);
    // graph.addEdge(10, 2);
    // graph.addEdge(9, 2);
    
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

    // CBMC Micheal Wolfe Paper G5b
    // std::cout << "CBMC Micheal Wolfe Paper G5b" << std::endl;
    // Graph graph(10);
    // graph.addEdge(0, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(2, 4);
    // graph.addEdge(3, 5);
    // graph.addEdge(5, 7);
    // graph.addEdge(7, 8);
    // graph.addEdge(8, 9);
    // graph.addEdge(4, 6);
    // graph.addEdge(6, 2);

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

    std::cout << (graph.depthFirstSearch(0) ? "True" : "False") << std::endl;

    return 0;
}
