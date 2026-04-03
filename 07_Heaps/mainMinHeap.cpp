#include "MinHeap.hpp"
#include "MinHeap.cpp"

#include <ctime>

template <typename T>
void heap_sort(std::vector<T>& v) {
    MinHeap<T> heap(v);

    for (int i = 0; i < v.size(); i++) {
        v[i] = heap.deleteMin();
    }
}


int main() {
    MinHeap<int> heap;
    std::vector<int> v;
    //srand(time(0));

    for (int i = 0; i < 10; i++) {
        int num = rand() % 1000;
        heap.insert(num);
        v.push_back(num);
    }

    MinHeap<int> heap2(v);
    
    heap.print();
    std::cout << "\n\n";
    heap2.print();
    std::cout << "\n\n";


    /*
    for (int i = 0; i < 10; i++) {
        heap.deleteMin();
        heap.print();
        std::cout << "\n========================\n";
    }
    */


    return 0;
}