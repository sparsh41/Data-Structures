#ifndef SLList_H_
#define SLList_H_


#include "../01_SLLNode/SLLNode.hpp"

// Use a template class
template <typename T>
class SLList {
    public:
        // No-arg Constructor
        SLList();

        // Copy Constructor
        SLList(const SLList<T>& other);

        // Assignment Operator
        SLList<T>& operator=(const SLList<T>& other); // Delete list, then push_back new ones

        // Destructor
        ~SLList();

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
        

    private:
        SLLNode<T>* head; // Address of first node
        SLLNode<T>* tail; // Address of last node
        unsigned list_size;


};


#endif