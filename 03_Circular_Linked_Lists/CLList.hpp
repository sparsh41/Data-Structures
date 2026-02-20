#ifndef CLList_H_
#define CLList_H_


template <typename T>
class CLList
{
    public:
        // No-arg Constructor
        CLList();

        // Copy Constructor
        CLList(const CLList<T>& other);

        // Assignment Operator
        CLList<T>& operator=(const CLList<T>& other); // Delete list, then push_back new ones

        // Destructor
        ~CLList();

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

    private:
        DLLNode<T>* tail;
        int list_size;

};


#endif