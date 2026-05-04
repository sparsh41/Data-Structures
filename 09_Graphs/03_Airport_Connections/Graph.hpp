#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Flight.hpp"

using namespace std;

class Graph {
    public:

        Graph();
        Graph(string fileName); // Graph from fileName

        // Add an airport to the list
        int addAirport(string code, string city); 

        // Add a flight to the graph
        void addEdge(string from, string from_city, string to, string to_city, int dist, int cost); 

        // Print a graph
        void printGraph(); // DELETE BEFORE SUBMITTING

        // Print connectivity stats
        void printConnectivity();

        // Algorithms
        void dijkstra(string startCode, string endCode);
        void shortestPathWithStops(string startCode, string endCode, int stops);
        void shortestToState (string startCode, string state); // Get airports in a certain state, then call fromSource for the paths
        void createMST_Prim(); // Create MST using Prim's Algorithm
        void createMSF_Kruskal(); // Create MST using Kruskal's Algorithm

        // Creates an undirected graph from the given directed graph
        void createUndirectedGraph();
        
        // Map indicies to codes
        vector<string> airport_codes;
        
        // Map indicies to cities
        vector<string> airport_cities;
        
        // Graph
        vector<vector<Flight>> matrix;
    
    private:
        // Check if a string vector contains a certain string value
        int contains(vector<string> v, string code);
        
        void shortestPathsFromSource(string startCode, string state, vector<string> targets);

        // Helper for prim's, get the min vertex not in keys
        int getMinVertex(vector<int> keys, vector<bool> mst_set);

        // Maps an existing airport's number to its code
        string numToCode(int num);
};

#endif