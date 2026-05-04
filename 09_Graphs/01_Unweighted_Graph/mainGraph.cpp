#include "Graph.hpp"
#include <iostream>

int main() {
    Graph<std::string> g;

    g.insertVertex("A");
    g.insertVertex("B");
    g.insertVertex("C");
    g.insertVertex("D");
    g.insertVertex("E");
    g.insertVertex("F");
    g.insertVertex("G");
    g.insertVertex("H");
    g.insertVertex("S");

    g.insertEdge("A", "B");
    g.insertEdge("A", "S");
    g.insertEdge("S", "C");
    g.insertEdge("S", "G");
    g.insertEdge("C", "D");
    g.insertEdge("C", "E");
    g.insertEdge("C", "F");
    g.insertEdge("F", "G");
    g.insertEdge("E", "H");
    g.insertEdge("G", "H");

    g.print();
    g.DFS();
    g.BFS();

    std::cout << "A -> F: " << g.shortestPath("A", "F") << " steps\n";
    std::cout << "A -> D: " << g.shortestPath("A", "D") << " steps\n";
    std::cout << "Graph g is connected? " << g.isConnected() << std::endl;
    
    /*
    Graph<char> g2;

    g2.insertVertex('A');
    g2.insertVertex('B');
    g2.insertVertex('C');
    g2.insertVertex('D');
    g2.insertVertex('E');
    g2.insertVertex('F');
    
    g2.insertEdge('A', 'D');
    g2.insertEdge('B', 'D');
    g2.insertEdge('C', 'D');
    g2.insertEdge('E', 'F');

    g2.print();
    g2.DFS();
    */
    
    /*
    Graph<char> g3;
    
    g3.insertVertex('A');
    g3.insertVertex('B');
    g3.insertVertex('C');
    g3.insertVertex('D');
    g3.insertVertex('E');
    g3.insertVertex('F');
    g3.insertVertex('G');
    g3.insertVertex('H');
    g3.insertVertex('I');
    g3.insertVertex('J');
    g3.insertVertex('K');
    g3.insertVertex('L');
    g3.insertVertex('M');
    g3.insertVertex('N');
    g3.insertVertex('O');
    g3.insertVertex('P');
    g3.insertVertex('Q');
    g3.insertVertex('R');
    
    g3.insertEdge('A', 'H');
    g3.insertEdge('B', 'E');
    g3.insertEdge('G', 'E');
    g3.insertEdge('G', 'F');
    g3.insertEdge('G', 'P');
    g3.insertEdge('Q', 'P');
    g3.insertEdge('I', 'G');
    g3.insertEdge('I', 'C');
    g3.insertEdge('D', 'C');
    g3.insertEdge('G', 'O');
    g3.insertEdge('N', 'N');
    g3.insertEdge('O', 'L');
    g3.insertEdge('P', 'Q');
    g3.insertEdge('J', 'K');
    g3.insertEdge('M', 'M');
    
    g3.DFS();
    std::cout << "Graph g3 is connected? " << g3.isConnected() << std::endl;
    */
    
    return 0;
}