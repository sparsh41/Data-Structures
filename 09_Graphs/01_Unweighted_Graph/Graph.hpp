#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

template <typename T>
class Graph {
    public:
        void insertVertex(const T& val);
        void insertEdge(const T& v1, const T& v2);
        
        void print() const;

        void DFS() const; // Depth-first search
        void BFS(int start = 0) const; // Breadth-first search

        int shortestPath(const T& src, const T& dest) const;

        bool isConnected() const; // true if all nodes have edges to others, false if disconnected
        
    private:
        std::vector<T> verticies;
        std::vector<std::vector<int>> edges;
        
        int getVertexIdx(const T& val) const;
        
        void DFS(int i, std::vector<bool>& vis) const;
};

#include "Graph.tpp"

#endif