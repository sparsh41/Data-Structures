#include "CLList.hpp"
#include "../02_Doubly_Linked_Lists/02_DLList/DLList.hpp"

#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}

template <typename T>
CLList<T>::~CLList() {
    clear();
}


template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
    } else {
        DLLNode<T>* newNode = new DLLNode<T>(val, tail, tail->next);
        tail->next->prev = newNode;
        tail->next = newNode;
    }
    list_size++;
}

template <typename T>
void CLList<T>::push_back(const T& val) {
    if (empty()) {
        push_front(val);
    }
    else {
        tail = new DLLNode<T>(val, tail, tail->next);
        tail->prev->next = tail;
    }
    
    list_size++;
}

template <typename T>
void CLList<T>::print_list() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
    
    std::cout << std::endl;
}

template <typename T>
void CLList<T>::print_reverse() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail;

    do {
        std::cout << cur->data;
        if (cur != tail->next) { // not the last node
            std::cout << " <- ";
        }
        cur = cur->prev;
    } while (cur != tail);
    
    std::cout << std::endl;
}


template <typename T>
bool CLList<T>::empty() const {
    return (list_size == 0);
}



template <typename T>
void CLList<T>::pop_back() {
    if (list_size == 1) {
        tail = nullptr;
        list_size = 0;
        return;
    }

    if (!empty()) {

        DLLNode<T>* cur = tail;

        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;
        tail = tail->prev;

        delete cur;
        list_size--;
    }
}

template <typename T>
void CLList<T>::pop_front() {
    if (list_size == 1) {
        tail = nullptr;
        list_size = 0;
        return;
    }

    if (!empty()) {

        DLLNode<T>* cur = tail->next;

        tail->next = cur->next;
        cur->next->prev = tail;

        delete cur;
        list_size--;
    }
}

template <typename T>
void CLList<T>::clear() {
    while (!empty()) {
        pop_back();
    }
    
}

template <typename T>
unsigned CLList<T>::size() const {
    return list_size;
}