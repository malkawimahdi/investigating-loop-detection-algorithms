#include <string>
#include <sstream>

#include "Graph.h"

int main(int argc, const char * argv[])
{
    // Stop user error :)
    if (argc != 2)
    {
        //Edges are assigned to as pairs from 1st->2nd, 3rd->4th ...
        throw std::runtime_error("Not Enough Arguments! \n"
                                 "USAGE: ./a.out [Comma (,) seperated Integers]");
    }
    else
    {
        // Take an input graph as a command-line argument
        std::stringstream graph_string_stream(argv[1]);

        std::vector<unsigned int> graphEdges;

        unsigned int largest_node = 0;

        // Remove commas.
        // Pair each node with the next node.
        // No additional information is required.
        // TODO: Change counter to something reasonable!!!
        for (int counter; graph_string_stream >> counter;)
        {
            if (graph_string_stream.peek() == ',')
            {
                graph_string_stream.ignore();
            }

            graphEdges.push_back(counter);

            if (largest_node < counter)
            {
                largest_node = counter;
            }
        }

        // Ensure that all the input is valid; every node belongs to a pair.
        if (graphEdges.size() % 2 == 0)
        {
            // Largest node + 1 to account for 0-index
            Graph graph(largest_node + 1);

            // Use Duffs device to generate graph.
            for (int counter = 0; counter < graphEdges.size(); counter += 2)
            {
                // std::cout << "Current:" << graphEdges[counter] << " Adj:" << graphEdges[counter+1] << std::endl;
                graph.addEdge(graphEdges[counter], graphEdges[counter+1]);
            }

            graph.iterativeDepthFirstSearch();
        }
        else
        {
            throw std::runtime_error("Pair(s) are missing values!");
        }
    }

//    std::cout << "Back Edge Present with Unreachable Nodes" << std::endl;
//    Graph graph(5);
//    graph.addEdge(0, 1);
//    graph.addEdge(1, 2);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 0);
//    graph.addEdge(4, 4);

// CBMC Micheal Wolfe Paper G1
// std::cout << "CBMC Micheal Wolfe Paper G1" << std::endl;
//Graph graph(16);
//graph.addEdge(0, 1);
//graph.addEdge(1, 2);
//graph.addEdge(2, 3);
//graph.addEdge(3, 4);
//graph.addEdge(3, 11);
//graph.addEdge(4, 5);
//graph.addEdge(5, 6);
//graph.addEdge(6, 7);
//graph.addEdge(7, 8);
//graph.addEdge(8, 8);
//graph.addEdge(8, 9);
//graph.addEdge(9, 10);
//graph.addEdge(10, 11);
//graph.addEdge(11, 12);
//graph.addEdge(12, 13);
//graph.addEdge(13, 14);
//graph.addEdge(14, 15);

// CBMC Micheal Wolfe Paper G2
// std::cout << "CBMC Micheal Wolfe Paper G2" << std::endl;
// Graph graph(21);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 7);
// graph.addEdge(7, 11);
// graph.addEdge(11, 12);
// graph.addEdge(12, 13);
// graph.addEdge(13, 14);
// graph.addEdge(14, 4);
// graph.addEdge(4, 15);
// graph.addEdge(15, 16);
// graph.addEdge(16, 17);
// graph.addEdge(17, 18);
// graph.addEdge(18, 19);
// graph.addEdge(19, 20);

// CBMC Micheal Wolfe Paper G3
// std::cout << "CBMC Micheal Wolfe Paper G3" << std::endl;
// Graph graph(26);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 11);
// graph.addEdge(10, 13);
// graph.addEdge(13, 9);
// graph.addEdge(11, 12);
// graph.addEdge(12, 15);
// graph.addEdge(15, 16);
// graph.addEdge(16, 10);
// graph.addEdge(16, 17);
// graph.addEdge(17, 18);
// graph.addEdge(18, 19);
// graph.addEdge(19, 20);
// graph.addEdge(20, 21);
// graph.addEdge(21, 22);
// graph.addEdge(22, 23);
// graph.addEdge(23, 24);
// graph.addEdge(24, 25);

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
// Graph graph(26);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 11);
// graph.addEdge(10, 18);
// graph.addEdge(11, 12);
// graph.addEdge(12, 13);
// graph.addEdge(13, 8);
// graph.addEdge(13, 14);
// graph.addEdge(14, 15);
// graph.addEdge(15, 16);
// graph.addEdge(16, 11);
// graph.addEdge(16, 17);
// graph.addEdge(17, 18);
// graph.addEdge(18, 19);
// graph.addEdge(19, 20);
// graph.addEdge(20, 21);
// graph.addEdge(21, 22);
// graph.addEdge(22, 23);
// graph.addEdge(23, 24);
// graph.addEdge(24, 25);

// CBMC Micheal Wolfe Paper G5b
// std::cout << "CBMC Micheal Wolfe Paper G5b" << std::endl;
// Graph graph(25);
// graph.addEdge(0, 1);
// graph.addEdge(1, 2);
// graph.addEdge(2, 3);
// graph.addEdge(3, 4);
// graph.addEdge(4, 5);
// graph.addEdge(5, 6);
// graph.addEdge(6, 7);
// graph.addEdge(7, 8);
// graph.addEdge(8, 9);
// graph.addEdge(9, 10);
// graph.addEdge(10, 11);
// graph.addEdge(11, 12);
// graph.addEdge(11, 14);
// graph.addEdge(12, 8);
// graph.addEdge(8, 17);
// graph.addEdge(14, 17);
// graph.addEdge(17, 18);
// graph.addEdge(18, 19);
// graph.addEdge(19, 20);
// graph.addEdge(20, 21);
// graph.addEdge(21, 22);
// graph.addEdge(22, 23);
// graph.addEdge(23, 24);

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


//    std::cout << (graph.depthFirstSearch() ? "True" : "False") << std::endl;

    return 0;
}
