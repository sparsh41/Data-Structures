#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <vector>
#include <iostream>
using namespace std;


template <typename T>
class MinHeap {
    public:
        // Constructors
        MinHeap();
        MinHeap(const vector<T>& v);


        // Modifying the Heap
        void insert(const T& val);
        T deleteMin();

        // Reading the Heap
        void print() const;

    private:
        vector<T> data;

        void heapify();

        void percolateUp();
        void percolateDown(int idx = 0);
        
        int getLeftKidIndex(int index);
        int getRightKidIndex(int index);
        int getParentIndex(int index);
        int getLastWithKidsIndex();

};

#endif