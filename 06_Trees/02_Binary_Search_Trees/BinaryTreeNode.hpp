#ifndef BINARYTREENODE_HPP
#define BINARYTREENODE_HPP

template <typename T>
class BTNode {
    public:
        BTNode(const T& val = T(), BTNode<T>* l = nullptr, BTNode<T>* r = nullptr) {
            data = val; 
            left = l;
            right = r; 
        }

        // Boolean methods
        bool isLeaf() const {
            return (!left && !right);
        }
        bool hasOneChild() const {
            return (!isLeaf() && !hastwoChildren());
        }
        bool hastwoChildren() const {
            return (left && right);
        }

        T data;
        BTNode<T>* left;
        BTNode<T>* right;
        
};

#endif