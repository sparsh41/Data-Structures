#include "SLList.hpp"
#include <iostream>


template <typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template <typename T>
SLList<T>::~SLList() {
    clear();
}

template <typename T>
SLList<T>::SLList(const SLList<T>& other) {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    
    SLLNode<T>* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
    SLList<T> temp = SLList<T>(other);
    
    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(list_size, temp.list_size);
    
    return *this;
}

template <typename T>
unsigned SLList<T>::size() const{
    return list_size;
}

template <typename T>
bool SLList<T>::empty() const {
    return (size() == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    list_size++; // Increase list size
    
    /* New node at the start
    SLLNode* new_node = new SLLNode(val);
    new_node->next = head;
    head = new_node;*/

    // Alternative method
    head = new SLLNode<T>(val, head);
    
    if (size() == 1) {
        tail = head;
    }
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    if (empty()) {
        push_front(val);
        return;
    }

    // Insert at end of list
    tail->next = new SLLNode<T>(val);
    tail = tail->next; // Update Tail
    
    // Increment list
    list_size++;
}

template <typename T>
void SLList<T>::print_list() const{
    std::cout << "{ ";
    
    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << " -> ";
        }
        cur = cur->next; // Move to the next node
    }
    
    std::cout << " }\n";
}

template <typename T>
void SLList<T>::pop_front() {
    if (!empty()) {
        
        SLLNode<T>* old_head = head;
        head = head->next;

        delete old_head; // Free memory
        
        // Decrement list
        list_size--;
        
        if (empty()) {
            tail = head;
        }
    }

}

template <typename T>
void SLList<T>::pop_back() {
    if (size() > 1) {
        
        // Decrement list
        list_size--;

        SLLNode<T>* cur = head;
        SLLNode<T>* prev = nullptr;
        
        while(cur->next) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = nullptr;
        tail = prev;

        delete cur;
        return;
    }
    
    if (size() == 1) {
        clear();
        return;
    }
}

template <typename T>
void SLList<T>::clear() {
    
    // Loop until the list is empty
    while (!empty()) {
        pop_front();
    }

    list_size = 0;
}