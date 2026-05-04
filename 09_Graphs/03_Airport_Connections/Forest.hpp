#ifndef FOREST_HPP
#define FOREST_HPP

#include <vector>

using namespace std;


// Forest class for use in Kruskal's
// A group of trees, represented by the vector<int> trees: trees[i] = j, vertex i belongs to tree j
class Forest
{
    public:
    vector<int> trees;
    vector<int> sizes; // sizes of trees
    vector<int> costs; // costs of trees
    vector<vector<int>> mst_edges; // store all edges in the msf

    // Constructor
    Forest(int);

    // Find the tree of a vertex
    int find_tree(int);

    // Combine two trees
    void combine_trees(int, int, int);

};

#endif