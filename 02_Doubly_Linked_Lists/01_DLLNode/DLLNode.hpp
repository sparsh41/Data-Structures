#ifndef DLLNODE_H_
#define DLLNODE_H_

template <typename T>
class DLLNode { // The class stores data, previous pointe, and next pointer
    public:
        DLLNode(const T& d = T(), DLLNode<T>* p = nullptr, DLLNode<T>* n = nullptr) {
            data = d;
            prev = p;
            next = n;
        }

        T data;
        DLLNode<T>* prev;
        DLLNode<T>* next;


};

#endif