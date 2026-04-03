#include "MinHeap.hpp"
using namespace std;

template <typename T>
MinHeap<T>::MinHeap(){}

template <typename T>
MinHeap<T>::MinHeap(const vector<T>& v) {
    data = v;
    heapify();
}


template <typename T>
void MinHeap<T>::insert(const T& val) {
    data.push_back(val);

    // Percolate up if greater than parent
    percolateUp();
}

template <typename T>
T MinHeap<T>::deleteMin() {
    if (data.empty()) {
        throw logic_error("deleteMin: Empty Heap");
    }

    T res = data[0];
    data[0] = data[data.size() - 1]; // Last element becomes root
    data.pop_back(); // remove last element

    percolateDown();

    return res;
}


template <typename T>
void MinHeap<T>::print() const{
    int cur_level = 0;
    int new_level = 1;

    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
        cur_level++;
        if (cur_level == new_level) {
            cout << endl;
            new_level *= 2;
            cur_level = 0;
        }
    }
}

template <typename T>
void MinHeap<T>::percolateUp() {
    int child_idx = data.size() - 1;
    int parent_idx = (child_idx - 1) / 2;
    
    while ((child_idx > 0) && (data[child_idx] < data[parent_idx])) {
        swap(data[child_idx], data[parent_idx]);
        child_idx = parent_idx;
        parent_idx = (child_idx - 1) / 2;
    }
}

template <typename T>
void MinHeap<T>::percolateDown(int idx) {
    int index = idx;
    
    while (getLeftKidIndex(index) < data.size()) {
        int left = getLeftKidIndex(index);
        int right = getRightKidIndex(index);

        int smallest = left;

        // If 2 kids
        if ((right < data.size()) && (data[right] < data[left])) {
            smallest = right;
        }
        
        if (data[index] < data[smallest]) {
            break;
        }

        swap(data[index], data[smallest]);
        index = smallest;
    }
}

template <typename T>
int MinHeap<T>::getLeftKidIndex(int index) {
    return index * 2 + 1;
}

template <typename T>
int MinHeap<T>::getRightKidIndex(int index) {
    return index * 2 + 2;
}

template <typename T>
int MinHeap<T>::getParentIndex(int index) {
    return (index - 1) / 2;
}

template <typename T>
int MinHeap<T>::getLastWithKidsIndex() {
    return data.size() / 2 - 1;
}

template <typename T>
void MinHeap<T>::heapify() {
    for (int i = getLastWithKidsIndex(); i >= 0; i--) {
        percolateDown(i);
    }
}   