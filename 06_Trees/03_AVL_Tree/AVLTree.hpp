#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AVLNode.hpp"
#include <string>


template <typename T>
class AVLTree {
public:
    AVLTree();
    
    bool empty() const;
    void inorder() const; // Inorder traversal of the tree
    
    bool isFullTree() const; // Check if the tree is full tree
    
    void print() const;
    
    void insert(const T& val);
    void remove(const T& val); // TODO 5

    // Searching
    AVLNode<T>* search(const T& val) const;
    AVLNode<T>* searchParent(const T& val) const;
    AVLNode<T>*& searchRef(const T& val);
    AVLNode<T>* getMinNode() const;
    

    int getHeight(const AVLNode<T>* node) const;
    int getBalance(const AVLNode<T>* node) const;

    // Tree rotations
    void rotateRightAt(const T& val);
    void rotateRightRef(AVLNode<T>*& node);
    void rotateLeftRef(AVLNode<T>*& node);
    
    void rotateLeftDoubleRef(AVLNode<T>*& node);
    void rotateRightDoubleRef(AVLNode<T>*& node);
    
private:
    AVLNode<T>* root;
    void inorder(AVLNode<T>* node) const;
    bool isFullTree(AVLNode<T>* node) const;
    AVLNode<T>* getMinNode(AVLNode<T>* node) const;
    
    void deleteLeaf(AVLNode<T>* child, AVLNode<T>* parent);
    void deleteNodeWithOneChild(AVLNode<T>* child, AVLNode<T>* parent);
    void deleteNodeWithTwoChildren(AVLNode<T>* node);
    
    void print(const std::string& prefix, AVLNode<T>* node, bool isRight) const;
    
    AVLNode<T>*& searchRef(const T& val, AVLNode<T>*& node);
    AVLNode<T>* rotateRight(AVLNode<T>* node);
    
    void balance(AVLNode<T>*& node);


    void insert(T val, AVLNode<T>* & node);
    void remove(const T& val, AVLNode<T>* & node);
};

#endif