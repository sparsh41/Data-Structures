#ifndef DLList_H_
#define DLList_H_


#include "../01_DLLNode/DLLNode.hpp"

// Use a template class
template <typename T>
class DLList {
    public:
    
        // No-arg Constructor
        DLList();

        // Copy Constructor
        DLList(const DLList<T>& other);

        // Assignment Operator
        DLList<T>& operator=(const DLList<T>& other); // Delete list, then push_back new ones

        // Destructor
        ~DLList();

        // Properties
        unsigned    size() const; // Returns size of list
        bool        empty() const; // Returns true if list is empty, false if not
        
        
        // Insert Elements
        void        push_front(const T& val); // Inserts new node at the start of the list
        void        push_back(const T& val); // Insert new node at the end of list
        
        
        // Remove Elements
        void        pop_front(); // Remove the first element of the list
        void        pop_back(); // Remove the last element
        void        clear(); // Clears the list
        

        // Print List
        void        print_list() const; // Prints the List
        void        print_reverse() const; // Prints the list backwards
        

        DLLNode<T>* head; // Address of first node
        DLLNode<T>* tail; // Address of last node
        unsigned list_size;


};


#endif