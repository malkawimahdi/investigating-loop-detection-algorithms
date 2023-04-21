#include "Utilities.h"

int main(int argc, const char * argv[])
{
    // Stop user error :)
    if (argc != 2) {
        throw std::runtime_error("Not Enough Arguments! \n"
                                 "USAGE: ./a.out Comma (,) seperated Integers");
    }
    else
    {
        Graph graph = graphParser(argv[1]);

        graph.initalise();

        graph.computeDominators();

        graph.computeDominatorsOutput();

        graph.dominatorTree();

        return 0;
    }
}

//    Graph graph(9);
//    graph.addEdge(1,2);
//    graph.addEdge(1,3);
//    graph.addEdge(2,3);
//    graph.addEdge(3,4);
//    graph.addEdge(4,3);
//    graph.addEdge(4,5);
//    graph.addEdge(4,6);
//    graph.addEdge(5,7);
//    graph.addEdge(6,7);
//    graph.addEdge(7,4);
//    graph.addEdge(7,8);
//
//    Graph graph(5);
//    graph.addEdge(0,1);
//    graph.addEdge(0,2);
//    graph.addEdge(1,4);
//    graph.addEdge(2,4);
//    graph.addEdge(2,3);
//    graph.addEdge(3,4);

//    Graph graph(5);
//    graph.addEdge(0,1);
//    graph.addEdge(1,2);
//    graph.addEdge(1,3);
//    graph.addEdge(2,4);
//    graph.addEdge(3,4);