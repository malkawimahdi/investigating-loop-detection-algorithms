#include "Utilities.h"

int main(int argc, const char * argv[])
{
    // Stop user error :)
    if (argc != 2)
    {
        throw std::runtime_error("Not Enough Arguments! \n"
                                 "USAGE: ./a.out Comma (,) seperated Integers");
    }
    else
    {
        Graph graph = graphParser(argv[1]);
        graph.initalise();

        std::set<int> test = graph.computeDominators(8);

        for (auto it = test.begin(); it != test.end(); it++)
        {
            std::cout << *it << std::endl;
        }

//        Graph graph2 = graph.dominatorTree();
    }
    return 0;
}
