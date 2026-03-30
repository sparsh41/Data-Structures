#ifndef STACK_H_
#define STACK_H_

namespace StackArray {

    template <typename T, int size = 10>
    class Stack {
        private:
            T data[size]; // Array of Elements
            int top_idx; // Index of the top element

        public:
            Stack();

            void        push(const T& value); // Add element to top
            bool        empty() const; // Determine if empty
            bool        full() const; // Determine if full
            void        print() const; // Print Stack
            T           pop(); // Remove and return top value
            const T&    top() const; // Return top value
    };
}


namespace StackList {

    template <typename T>
    class Stack {
        private:
            class Node {
                public:
                    T data;
                    Node* next;
                    Node(const T& value = T()) : data(value), next(nullptr) {}
            };
            Node* top_node;
    
        public:
            Stack();
            ~Stack();
    
            void        push(const T& value); // Add element to top
            bool        empty() const; // Determine if empty
            void        print() const; // Print Stack
            T           pop(); // Remove and return top value
            const T&    top() const; // Return top value
    };
}


#endif