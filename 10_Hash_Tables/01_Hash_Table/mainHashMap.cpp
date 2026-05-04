#include "HashMap.hpp"
#include <iostream>

int main(void) {
    HashMap<int, int> map;
    
    std::cout << map.empty() << " " << map.full() << std::endl;
    
    map.insert(111, 1);
    map.insert(222, 2);
    map.insert(333, 3);
    map.print();
    
    return 0;
}