#include "AVLTree.hpp"
#include "AVLTree.cpp"

#include <iostream>
#include <string>

int main(void) {
    AVLTree<int> tree;
    for (int i = 1; i < 50; i++) {
        std::cout << "Insert " << i << std::endl;
        tree.insert(i);
        tree.print();
    }
    
    std::cout << "\nDELETION\n" << std::endl;
    for (int i = 49; i >= 1; i--) {
        std::cout << "Remove " << i << std::endl;
        tree.remove(i);
        tree.print();
    }
    

    return 0;
}


