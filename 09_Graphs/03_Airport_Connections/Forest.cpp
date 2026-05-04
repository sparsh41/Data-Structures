#include "Forest.hpp"

// Constructor
Forest::Forest(int size) {
    // resize vectors
    trees.resize(size);
    sizes.resize(size);

    for (int i = 0; i < size; i++) {
        trees[i] = i; // each vector gets its own tree at first
        sizes[i] = 1; // of size 1
    }
}

// Find the tree for a node
int Forest::find_tree(int node) {
    // find the tree that a node belongs to
    while(trees[node] != node) {
        node = trees[node]; // not using path compression
    }
    return node;
}

// Combine two trees using an edge
void Forest::combine_trees(int node_1, int node_2, int cost) {

    int tree_1 = find_tree(node_1);
    int tree_2 = find_tree(node_2);

    vector<int> to_add = {node_1, node_2, cost};

    // decide which tree to absorb into other 
    if (sizes[tree_1] < sizes[tree_2]) {
        trees[tree_1] = tree_2;
    }
    else if (sizes[tree_1] > sizes[tree_2]) {
        trees[tree_2] = tree_1;
    }
    else {
        trees[tree_1] = tree_2;
        sizes[tree_2]++;
    }

    // keep track of edge
    mst_edges.push_back(to_add);
}
