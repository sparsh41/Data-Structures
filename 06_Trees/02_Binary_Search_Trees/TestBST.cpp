#include "BST.hpp"
#include "BST.cpp"

int main() {
    BST<int> tree;

    tree.insert(12);
    tree.insert(14);
    tree.insert(13);
    tree.insert(10);
    tree.insert(8);
    tree.insert(9);
    tree.insert(93);
    tree.insert(4);
    tree.insert(0);
    tree.insert(1);
    tree.insert(25);
    
    /*
    tree.inorder();

    std::cout << (tree.search(9)? "Found " : "Not Found ") << 9 << std::endl;
    std::cout << (tree.search(3)? "Found " : "Not Found ") << 9 << std::endl;

    bool full = tree.isFullTree();
    std::cout << "Full tree? " << ((full)? "Yes" : "No") << std::endl;
    */

   /*
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);

    // Deleting nodes
    tree.print();
    tree.deleteNode(2);
    tree.print();
    tree.deleteNode(3);
    tree.print();
    */

    // Rotating the tree
    tree.print();
    tree.rotateRight(tree.getRoot());
    tree.print();
    tree.rotateLeft(tree.getRoot());
    tree.rotateLeft(tree.getRoot());
    tree.print();


    return 0;
}