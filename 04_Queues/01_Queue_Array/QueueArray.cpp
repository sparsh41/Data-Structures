#include "QueueArray.hpp"
#include <iostream>
#include <stdexcept>


// Constructor
template<typename T, int size>
QueueArray<T, size>::QueueArray() {
    queue_size = 0;
    front_idx = 0;
    back_idx = 0;
}


template <typename T, int size>
void QueueArray<T, size>::enqueue(const T& val) {
    
    if (full()) {
        return;
    }

    
    data[back_idx] = val; // Set last element with the value;
    back_idx = (back_idx + 1) % size;
    queue_size++;
}

template <typename T, int size>
const T& QueueArray<T, size>::front() const{
    return data[front_idx];
}

template <typename T, int size>
const T& QueueArray<T, size>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Empty Queue!");
        exit(1);
    }
    
    else {
        int old_front = front_idx;
        front_idx = (front_idx + 1) % size;
        queue_size--;

        return data[old_front];
    }
}


// Properties
template<typename T, int size>
int QueueArray<T, size>::length() const {
    return queue_size;
}


template<typename T, int size>
bool QueueArray<T, size>::empty() const {
    return (length() == 0);
}


template<typename T, int size>
bool QueueArray<T, size>::full() const {
    return (length() == size);
}

// Printing
template <typename T, int size>
void QueueArray<T, size>::print() const {
    std::cout << "[ ";
        
    if (!empty()) {
        int i = front_idx;
        do  {
            std::cout << data[i];
            
            i = (i + 1) % size;

            if (i != back_idx) {
                std::cout << ", ";
            

            }
        } while (i != back_idx);
        
    }
    std::cout << " ]\n";
}

template <typename T, int size>
void QueueArray<T, size>::clear() {
    front_idx = back_idx = 0;
    queue_size = 0;
}