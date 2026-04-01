#include "BST.hpp"
#include <iostream>

template <typename T>
BST<T>::BST() {
    root = nullptr;
}


template <typename T>
BTNode<T>*& BST<T>::getRoot(){
    return root;
}


template <typename T>
bool BST<T>::empty() const {
    return (root == nullptr);
}


template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }
    
    // Iterative Approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = nullptr;
    
    while (cur) {
        prev = cur;
        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (val < prev->data) {
        prev->left = new BTNode<T>(val);
    }
    else {
        prev->right = new BTNode<T>(val);
    }
    
}

template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}


template <typename T>
void BST<T>::inorder(BTNode<T>* node) const{
    if (!node) {
        return;
    }
    
    inorder(node->left);
    std::cout << node->data << " ";
    
    inorder(node->right);
}

template <typename T>
void BST<T>::preorder() const {
    std::cout << "Preorder: [ ";
    preorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::preorder(BTNode<T>* node) const {}


template <typename T>
bool BST<T>::isFullTree() const {
    return isFullTree(root);
}


template <typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const {
    if (!node) {
        return true;
    }
    
    if (node->hasOneChild()) {
        return false;
    }
    
    
    return (isFullTree(node->left) && isFullTree(node->right));
}

template <typename T>
BTNode<T>* BST<T>::getMinNode() const {
    return getMinNode(root);
}


template <typename T>
BTNode<T>* BST<T>::search(const T& val) const{
    BTNode<T>* cur = root;
    while (cur)
    {
        if (cur->data == val) {
            return cur;
        }
        else if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    
    return nullptr;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const {
    BTNode<T>* cur = root;
    BTNode<T>* prev = nullptr;
    
    if (!root || (root->data == val)) {
        return nullptr;
    }
    while (cur) {
        if (cur->data == val) { // Found the value
            return prev;
        }
        else if (cur->data > val) { // Value is less than current
            prev = cur;
            cur = cur->left;
        }
        else {
            prev = cur;
            cur = cur->right;
        }
    }
    return prev;
}


template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent) {
    
    if (child == root) {
        root = nullptr;
        delete child;
        return;
    }
    
    
    if (parent->left == child) {
        parent->left = nullptr;
        delete child;
        return;
    }
    
    if (parent->right == child) {
        parent->right = nullptr;
        delete child;
        return;
    }
}


template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent) {    
    
    if (parent->left == child) {
        parent->left = child->left;
        delete child;
        return;
    }
    
    if (parent->right == child) {
        parent->right = child->right;
        delete child;
        return;
    }
}


template <typename T>
void BST<T>::print() const{
    std::cout << "\n\n===========================================" << std::endl;
    std::cout << "\t[Value, Height, Balance]  " << std::endl;
    std::cout << "===========================================" << std::endl;
    print("", root, false);
    std::cout << "===========================================" << std::endl;
}

template <typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }
    
    std::cout << prefix;
    
    if (node != root) {
        std::cout << (isRight? " R---" : " L---");
    }
    else {
        std::cout << "  ---";
    }
    
    // Print value of the current node
    std::cout << "[" << node->data << " , " << getHeight(node) << " , " << getBalance(node) << "]" << std::endl;
    
    // Go to next level of node
    print(prefix + "     ", node->right, true);
    print(prefix + "     ", node->left, false);
}

template <typename T>
void BST<T>::deleteNode(const T& val) {
    BTNode<T>* node = search(val);

    if (!node) {
        std::cout << val << " not found in tree" << std::endl;
        return;
    }
    
    BTNode<T>* parent = searchParent(val);
    
    if (node->isLeaf()) {
        deleteLeaf(node, parent);
    }
    else if (node->hasOneChild()) {
        deleteNodeWithOneChild(node, parent);
    }
    else { // Node has two children
        deleteNodeWithTwoChildren(node);
    }
}

template <typename T>
void BST<T>::deleteNodeWithTwoChildren(BTNode<T>* node) {
    
    BTNode<T>* minRightNode = getMinNode(node->right);
    T min_val = minRightNode->data;
    
    if (minRightNode->isLeaf()) {
        deleteLeaf(minRightNode, searchParent(min_val));
    }
    else {
        deleteNodeWithOneChild(minRightNode, searchParent(min_val));
    }
    node->data = min_val;
}


template <typename T>
BTNode<T>* BST<T>::getMinNode(BTNode<T>* node) const {
    if (!node) {
        return nullptr;
    }
    
    BTNode<T>* cur = node;
    
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

template <typename T>
int BST<T>::getHeight(BTNode<T>* node) const {
    if (!node) {
        return 0;
    }
    
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}


template <typename T>
int BST<T>::getBalance(const BTNode<T>* node) const {
    if (!node) {
        return 0;
    }

    return (getHeight(node->left) - getHeight(node->right));
}


template <typename T>
void BST<T>::rotateRight(BTNode<T>* & node) {
    if (!node || !node->left) {
        return;
    }

    BTNode<T>* left_child = node->left;
    node->left = left_child->right;
    left_child->right = node;
    node = left_child;
}


template <typename T>
void BST<T>::rotateLeft(BTNode<T>* & node) {
    if (!node || !node->right) {
        return;
    }

    BTNode<T>* right_child = node->right;
    node->right = right_child->left;
    right_child->left = node;
    node = right_child;
}