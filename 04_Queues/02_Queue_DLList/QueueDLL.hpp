
#ifndef QUEUEDLL_H
#define QUEUEDLL_H

#include "../../02_Doubly_Linked_Lists/02_DLList/DLList.hpp"
#include "../../02_Doubly_Linked_Lists/02_DLList/DLList.cpp"

template <typename T>
class QueueDLL {

    public:
        QueueDLL();

        bool        empty() const; 
        bool        full() const;

        void        enqueue(const T& val); // Add element to the end of the queue
        const T&    front() const; // Return the first element in the queue
        const T&    dequeue(); // Remove the first element and return it
        void        clear(); // Clear the queue

        void        print() const; // Print the contents of the queue

    private:
        DLList<T>* data;
        
};

#endif