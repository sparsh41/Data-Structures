#include <iostream>
#include <fstream>

#include "Graph.hpp"

using namespace std;

int main() {

    Graph g = Graph("airports.csv");

    g.dijkstra("FNT", "TPA");
    g.dijkstra("ATL", "MCO");

    // g.shortestToState("ATL", "IL");

    // g.shortestPathWithStops("ATL", "UIN", 4);

    // g.printConnectivity();

    // g.createUndirectedGraph();

    // g.createMST_Prim();

    // g.createMSF_Kruskal();

    return 0;
}