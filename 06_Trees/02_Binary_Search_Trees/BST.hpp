#ifndef BST_HPP
#define BST_HPP
#include "BinaryTreeNode.hpp"
#include <string>

template <typename T>
class BST {
    public:
        BST();
    
        bool empty() const;
        bool isFullTree() const;
        void insert(const T& val); // Insert a value into the Tree
        BTNode<T>*& getRoot(); // Returns the root of the tree
        
        void print() const;
        int getHeight(BTNode<T>* node) const;
        int getBalance(const BTNode<T>* node) const;
        
        // Traversal of tree
        void inorder() const;
        void preorder() const;
        void postorder() const;

        // Searching
        BTNode<T>* search(const T& val) const;
        BTNode<T>* getMinNode() const;
        BTNode<T>* searchParent(const T& val) const;
        
        // Deleting
        void deleteNode(const T& val);

        // Balancing the Tree
        void rotateRight(BTNode<T>* & node);
        void rotateLeft(BTNode<T>* & node);
        
        private:
        BTNode<T>* root;
        void inorder(BTNode<T>* node) const;
        void preorder(BTNode<T>* node) const;
        void postorder(BTNode<T>* node) const;
        void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
        
        
        bool isFullTree(BTNode<T>* node) const;
        void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
        void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);
        void deleteNodeWithTwoChildren(BTNode<T>* node);
        
        BTNode<T>* getMinNode(BTNode<T>* node) const;
    };

#endif