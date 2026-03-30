#include "Stack.hpp"
#include <iostream>
#include <stdexcept>

// Stack Array
template <typename T, int size>
StackArray::Stack<T, size>::Stack() : top_idx(-1){}

template <typename T, int size>
void StackArray::Stack<T, size>::push(const T& value) {
    if (full()) {
        throw std::out_of_range("Full Stack!");
        return;
    }

    data[++top_idx] = value;
}


template <typename T, int size>
bool StackArray::Stack<T, size>::empty() const {
    return (top_idx == -1);
}


template <typename T, int size>
bool StackArray::Stack<T, size>::full() const {
    return (top_idx == size);
}


template <typename T, int size>
void StackArray::Stack<T, size>::print() const {
    int i = top_idx;

    while (i >= 0) {
        std::cout << data[i--] << std::endl;
    }
    
}


template <typename T, int size>
T StackArray::Stack<T, size>::pop() {
    if (!empty()) {
        return (data[top_idx--]);
    }

    throw std::out_of_range("Empty Stack!");
}


template <typename T, int size>
const T& StackArray::Stack<T, size>::top() const {
    return data[top_idx];
}




// Stack List
template <typename T>
StackList::Stack<T>::Stack() {
    top_node = nullptr;
}


template <typename T>
StackList::Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void StackList::Stack<T>::push(const T& val) {
    top_node = new Node(val, top_node);
}

template <typename T>
bool StackList::Stack<T>::empty() const {
    return (!top_node);
}

template <typename T>
void StackList::Stack<T>::print() const {
    Node<T>* cur = top_node;
    while (cur) {
        std::cout << cur->data << std::endl;
        cur = cur->next;
    }
}


template <typename T>
T StackList::Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Empty Stack!");
    }
    else {
        Node<T>* cur = top_node;
        T temp = cur->data;
        top_node = top_node->next;
        delete cur;

        return temp;
    }
}

template <typename T>
const T& StackList::Stack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Empty Stack!");
    }
    else {
        return top_node->data;
    }
}