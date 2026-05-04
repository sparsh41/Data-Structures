#include "WeightedGraph.hpp"
#include <string>
#include <ctime>

int main(void) {

    srand(time(0));

    WeightedGraph<std::string> g;


    g.insertVertex("A");
    g.insertVertex("B");
    g.insertVertex("C");
    g.insertVertex("D");
    g.insertVertex("E");
    g.insertVertex("F");
    g.insertVertex("G");
    g.insertVertex("S");
    g.insertVertex("H");



    g.insertEdge("A", "B", rand() % 50);
    g.insertEdge("A", "S", rand() % 50);
    g.insertEdge("C", "S", rand() % 50);
    g.insertEdge("G", "S", rand() % 50);
    g.insertEdge("C", "F", rand() % 50);
    g.insertEdge("C", "E", rand() % 50);
    g.insertEdge("C", "D", rand() % 50);
    g.insertEdge("E", "H", rand() % 50);
    g.insertEdge("G", "H", rand() % 50);
    g.insertEdge("G", "F", rand() % 50);
    

    g.print();
    g.DFS();

    g.BFS();
    
    std::cout << "\nA -> F " << g.shortestPath("A", "F") << " units" << std::endl;
    std::cout << "A -> D " << g.shortestPath("A", "D") << " units" << std::endl;
    std::cout << "\nGraph is connected? " << g.isConnected() << std::endl;

    return 0;
}