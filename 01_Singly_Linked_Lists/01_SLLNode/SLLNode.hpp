#ifndef SLLNODE_HPP
#define SLLNODE_HPP

template <typename T>
class SLLNode {
    public:

        SLLNode(const T& d = T(), SLLNode<T>* n = nullptr) { // T() is a default template value
            data = d;
            next = n;
        }

        T data;
        SLLNode<T>* next; // Pointer to the next node


};

#endif