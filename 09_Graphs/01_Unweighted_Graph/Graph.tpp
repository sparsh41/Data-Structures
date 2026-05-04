#include "Graph.hpp"
#include <iostream>
#include <queue>

template <typename T>
void Graph<T>::insertVertex(const T& val){
    if (getVertexIdx(val) != -1) {
        std::cout << "insertVertex: Vertex already exists\n";
        return;
    }

    verticies.push_back(val); // Add new vertex
    std::vector<int> tmp;
    edges.push_back(tmp); // Empty list of connections of neighbors of new node
}


template <typename T>
int Graph<T>::getVertexIdx(const T& val) const{
    int i = 0;
    for (const auto& v : verticies) {
        if (v == val) {
            return i;
        }
        i++;
    }
    return -1; // Not found
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    int v1_idx = getVertexIdx(v1);
    int v2_idx = getVertexIdx(v2);
    
    if ((v1_idx == -1) || (v2_idx == -1)) {
        std::cout << "insertEdge: incorrect verticies\n";
        return;
    }
    
    // Since undirected graph, add references to both values of matrix
    edges[v1_idx].push_back(v2_idx);
    if (v1_idx != v2_idx) {
        edges[v2_idx].push_back(v1_idx);
    }
}



template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < verticies.size(); i++) {
        std::cout << "{ " << verticies[i] << ": ";
        for (int j = 0; j < edges[i].size(); j++) {
            std::cout << verticies[edges[i][j]] << " ";
        }
        std::cout << "}\n";
    }
}

template <typename T>
void Graph<T>::DFS() const {
    if (verticies.empty()) {
        return;
    }

    std::cout << "Depth-first Search: ";

    std::vector<bool> visited_nodes(verticies.size(), false);

    for (int i = 0; i < visited_nodes.size(); i++) {
        if (!visited_nodes[i]){
            DFS(i, visited_nodes);
        }
    }

    std::cout << "\b\b\b   " << std::endl;

}


template <typename T>
void Graph<T>::DFS(int i, std::vector<bool>& vis) const{
    vis[i] = true;

    std::cout << verticies[i] << " -> ";

    // Look through all neighbors
    for (int j : edges[i]) {
        if (!vis[j]) {
            DFS(j, vis);
        }
    }
}


template <typename T>
void Graph<T>::BFS(int start) const{
    if (verticies.empty() || start < 0 || start >= verticies.size()) {
        return;
    }
    
    std::vector<bool> discovered(verticies.size(), false);
    std::queue<int> where_to_go;
    
    where_to_go.push(start);
    discovered[start] = true;
    
    std::cout << "Breadth-first Search: ";

    while (!where_to_go.empty()) {
        int cur = where_to_go.front();

        std::cout << verticies[cur] << " -> ";
        where_to_go.pop();

        // Explore neighbors
        for (int j : edges[cur]) {
            if (!discovered[j]) {
                where_to_go.push(j);
                discovered[j] = true;
            }
        }
    }
    std::cout << "\b\b\b   " << std::endl;
}


template <typename T>
int Graph<T>::shortestPath(const T& src, const T& dest) const{
    // Find indices
    int i_src = getVertexIdx(src);
    int i_dest = getVertexIdx(dest);

    // Check edge case
    if ((i_src == -1) || (i_dest == -1)) {
        std::cout << "shortestPath: incorrect indices";
        return -1;
    }
    if (i_src == i_dest) {
        return 0;
    }

    // Create distances vector
    std::vector<int> distances(verticies.size()); // Distances from source to all other nodes

    // set initial distances
    for (int i = 0; i < distances.size(); i++) {
        distances[i] = (i == i_src)? 0 : -1;
    }
    
    
    // Perform BFS and update distances
    
    std::queue<int> q;
    q.push(i_src);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // Check neighbors of node
        for (int i : edges[cur]) {
            if (distances[i] == -1) {
                distances[i] = distances[cur] + 1;
                q.push(i);
            }
            if (i == i_dest) {
                return distances[i];
            }
        }
    }
    
    return -1; // No path
}


template <typename T>
bool Graph<T>::isConnected() const {
    std::vector<int> paths(verticies.size());
    for (int i = 0; i < verticies.size(); i++) {
        paths[i] = shortestPath(verticies[0], verticies[i]);
    }

    for (int path : paths) {
        if (path == -1) {
            return false;
        }
    }
    return true;
}