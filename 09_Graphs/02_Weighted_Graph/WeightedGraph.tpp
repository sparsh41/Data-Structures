#include "WeightedGraph.hpp"
#include "MinHeap.hpp"
#include <iostream>
#include <queue>
#include <climits>

template <typename T>
void WeightedGraph<T>::insertVertex(const T& v) {
    if (getVertexIndex(v) != -1) {
        std::cout << "insertVertex: vertex already exist\n";
        return;
    }

    vertices.push_back(v);
    std::vector<Edge> tmp; 
    edges.push_back(tmp); 
}


template <typename T>
void WeightedGraph<T>::insertEdge(const T& v1, const T& v2, int weight) {
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if (i1 == -1 || i2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }
    
    if (!hasEdge(i1, i2)) {
        edges[i1].push_back(Edge(weight, i2));
        if (i1 != i2) {
            edges[i2].push_back(Edge(weight, i1));
        }
    }
}   

template <typename T>
int WeightedGraph<T>::getVertexIndex(const T& ver) const {
    for(int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == ver) {
            return i;
        }
    }

    return -1;
}


template <typename T>
void WeightedGraph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "{ " << vertices[i] << ": ";
        for(int j = 0; j < edges[i].size(); j++) {
            std::cout << "{ " << vertices[edges[i][j].neighbor] << ", " << edges[i][j].weight << " } ";
        }
        std::cout << " }\n";
    }
    std::cout << std::endl;
}


template <typename T>
bool WeightedGraph<T>::hasEdge(int i1, int i2) const {
    if (i1 < 0 || i1 >= edges.size()) {
        return false;
    }

    for (const Edge& e: edges[i1]) {
        if (e.neighbor == i2) {
            return true;
        }
    }

    return false;
}

template <typename T>
void WeightedGraph<T>::DFS() const {
    if (vertices.empty()) {
        return;
    }

    std::cout << "Depth-first Search: ";

    std::vector<bool> visited_nodes(vertices.size(), false);

    for (int i = 0; i < visited_nodes.size(); i++) {
        if (!visited_nodes[i]){
            DFS(i, visited_nodes);
        }
    }

    std::cout << "\b\b\b   " << std::endl;

}


template <typename T>
void WeightedGraph<T>::DFS(int i, std::vector<bool>& visited) const {
    visited[i] = true;
    std::cout << vertices[i] << " -> ";

    // Look through all the neighbours
    for (Edge j : edges[i]) {
        if (!visited[j.neighbor]) {
            DFS(j.neighbor, visited);
        }
    }
}


template <typename T>
void WeightedGraph<T>::BFS(int start) const {
    if (vertices.empty() || start < 0 || start >= vertices.size()) {
        return;
    }

    std::vector<bool> discovered(vertices.size(), false);
    std::queue<int> where_to_go;

    where_to_go.push(start);
    discovered[start] = true;

    std::cout << "Breadth-first Search: ";

    while (!where_to_go.empty()) {
        int cur = where_to_go.front();

        std::cout << vertices[cur] << " -> ";
        where_to_go.pop();

        // Explore neighbors
        for (Edge j : edges[cur]) {
            if (!discovered[j.neighbor]) {
                where_to_go.push(j.neighbor);
                discovered[j.neighbor] = true;
            }
        }
    }
    std::cout << "\b\b\b   " << std::endl;  

}


template <typename T>
int WeightedGraph<T>::shortestPath(const T& src, const T& dest) const {
    // Find indices
    int i_src = getVertexIndex(src);
    int i_dest = getVertexIndex(dest);

    // Check edge case
    if (i_src == -1 || i_dest == -1) {
        std::cout << "shortestPath: incorrect indices";
        return -1;
    }
    if (i_src == i_dest) {
        return 0;
    }


    // Create distances vector
    std::vector<int> distances(vertices.size(), INT_MAX); // distances from source to all other nodes
    distances[i_src] = 0;


    MinHeap<Edge> heap;
    heap.insert(Edge(0, i_src));

    while (!heap.empty()) {
        // Get smallest edge from heap
        Edge smallest_edge = heap.deleteMin();


        // Go through all univisited neighbors of smallest edge
        for (Edge n : edges[smallest_edge.neighbor]) {

            // Check the distance (if dist is smaller, update distances)
            if (distances[smallest_edge.neighbor] + n.weight < distances[n.neighbor]) {
                distances[n.neighbor] = distances[smallest_edge.neighbor] + n.weight;
                heap.insert(Edge(distances[n.neighbor], n.neighbor));
            }
        }
    }
    
    return distances[i_dest];
}

template <typename T>
bool WeightedGraph<T>::isConnected() const {
    std::vector<int> paths(vertices.size());
    for (int i = 0; i < vertices.size(); i++) {
        paths[i] = shortestPath(vertices[0], vertices[i]);
    }

    for (int path : paths) {
        if (path == -1) {
            return false;
        }
    }
    return true;
}