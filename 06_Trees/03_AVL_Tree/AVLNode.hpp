#ifndef AVLNODE_HPP
#define AVLNODE_HPP

template <typename T>
class AVLNode {
public:
    AVLNode(const T& val = T(), AVLNode<T>* l = nullptr, AVLNode<T>* r = nullptr) :
        data(val), left(l), right(r), height(1) { }
    
    bool isLeaf() const {
        return !left && !right;
    }
    bool hasOneChild() const {
        return !isLeaf() && !hasTwoChildren();
    }
    bool hasTwoChildren() const {
        return left && right;
    }

    T data;
    int height;
    AVLNode<T>* left;
    AVLNode<T>* right;
};

#endif