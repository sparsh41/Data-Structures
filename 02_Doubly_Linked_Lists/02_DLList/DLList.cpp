#include "DLList.hpp"
#include <iostream>
#include <stdexcept>

// Constructors and stuff
template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>; // Sentinel Head Node
    tail = new DLLNode<T>; // Sentinel Tail Node

    // Connect the Nodes
    head->next = tail;
    tail->prev = head;

    list_size = 0;
}

template <typename T>
DLList<T>::~DLList() {
    clear();
}

template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other) {
    clear();
    head = other.head;
    tail = other.tail;
    list_size = 0;
    
    DLLNode<T>* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
   return *this; 
}

template <typename T>
DLList<T>::DLList(const DLList<T>& other) {
    head = other.head;
    tail = other.tail;
    list_size = 0;
    
    DLLNode<T>* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}


// Propoerties
template <typename T>
unsigned DLList<T>::size() const {
    return list_size;
}

template <typename T>
bool DLList<T>::empty() const {
    return (size() == 0);
}

template <typename T>
const T& DLList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Empty Queue");
    }

    return head->next->data;
}



// Printing List
template <typename T>
void DLList<T>::print_list() const {
    std::cout << "{ ";

    DLLNode<T>* cur = head->next;
    while (cur != tail) {
        std::cout << cur->data;
        if (cur->next != tail) {
            std::cout << " -> ";
        }
        cur = cur->next;
    }

    std::cout << " }\n";
}

template <typename T>
void DLList<T>::print_reverse() const {
    std::cout << "{ ";

    DLLNode<T>* cur = tail->prev;
    while (cur != head) {
        std::cout << cur->data;
        if (cur->prev != head) {
            std::cout << " -> ";
        }
        cur = cur->prev;
    }

    std::cout << " }\n";
}


// Insert Elements
template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;
}

template <typename T>
void DLList<T>::push_back(const T& val) {
    tail->prev = new DLLNode<T>(val, tail->prev, tail);
    tail->prev->prev->next = tail->prev;
}



// Remove Elements
template<typename T>
void DLList<T>::pop_front() {
    if (!empty()) {
        // Point to first node
        DLLNode<T>* first = head->next;

        head->next = first->next;
        head->next->prev = head;

        delete first;
        list_size--;
    }
}


template <typename T>
void DLList<T>::pop_back() {
    if (!empty()) {
        // Point to last node
        DLLNode<T>* last = tail->prev;

        tail->prev = last->prev;
        tail->prev->next = tail;

        delete last;
        list_size--;
    }
}

template <typename T>
void DLList<T>::clear() {
    while (!empty()) {
       pop_back();
    }
    
}