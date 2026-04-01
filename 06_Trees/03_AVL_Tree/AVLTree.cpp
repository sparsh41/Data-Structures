#include "AVLTree.hpp"
#include <iostream>

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}


template <typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void AVLTree<T>::insert(const T& val) {
    insert(val, root);
}

template <typename T>
void AVLTree<T>::insert(T val, AVLNode<T>* & node) {
    if (!node) {
        node = new AVLNode<T>(val);
    }

    else if (val < node->data){
        insert(val, node->left);
    }

    else {
        insert(val, node->right);
    }

    // Update node height
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    balance(node);
}

template <typename T>
void AVLTree<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}


template <typename T>
bool AVLTree<T>::isFullTree() const {
    return isFullTree(root);
}

template <typename T>
bool AVLTree<T>::isFullTree(AVLNode<T>* node) const {
    if (!node) {
        return true;
    }
    if (node->hasOneChild()) {
        return false;
    }
    return isFullTree(node->left) && isFullTree(node->right);
}

template <typename T>
AVLNode<T>* AVLTree<T>::search(const T& val) const {
    AVLNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) { // Found the value
            return cur;
        }
        else if (cur->data > val) { // Value is less than current
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return nullptr;
}


/////------------////

template <typename T>
AVLNode<T>* AVLTree<T>::getMinNode() const {
    return getMinNode(root);
}

template <typename T>
AVLNode<T>* AVLTree<T>::getMinNode(AVLNode<T>* node) const {
    if (!node) {
        return nullptr;
    }
    else if (!node->left) {
        return node;
    }
    return getMinNode(node->left);
}

template <typename T>
void AVLTree<T>::deleteLeaf(AVLNode<T>* child, AVLNode<T>* parent) {
    if (!child) {
        return;
    }
    if (!parent) { // This is the root
        delete root;
        root = nullptr;
        return;
    }
    if (parent->left == child) { //left kid
        parent->left = nullptr;
    }
    else if (parent->right == child) { //right kid
        parent->right = nullptr;
    }

    delete child;
}


template <typename T>
void AVLTree<T>::deleteNodeWithOneChild(AVLNode<T>* child, AVLNode<T>* parent) {
    if (child == root) {
        AVLNode<T>* to_delete = root;
        root = (root->left) ? root->left : root->right;
        delete to_delete;
        return;
    }
    AVLNode<T>* grand_kid = (child->right) ? child->right : child->left;
    if (parent->right == child) {
        parent->right = grand_kid;
    }
    if (parent->left == child) {
        parent->left = grand_kid;
    }

    //release the memory
    delete child;
}

template <typename T>
AVLNode<T>* AVLTree<T>::searchParent(const T& val) const {
    if(root->data == val) { // Root doesn't have a parent
        return nullptr;
    }
    
    AVLNode<T>* node = root;
    AVLNode<T>* prev = root;

    while (node) {
        if (node->data == val) {
            return prev;
        }
        prev = node;
        if (val < node->data) {
            node = node->left;
        }
        else if (val > node->data) {
            node = node->right;
        }
    }

    return nullptr;
}

template <typename T>
void AVLTree<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);    
    std::cout << "===============================\n";
}

template <typename T>
void AVLTree<T>::print(const std::string& prefix, AVLNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }
    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R----" : "L----");
    }
    else {
        std::cout << "---";
    }

    // Print the value of the node
    std::cout << '[' << node->data <<  ", " << getHeight(node) << ", " << getBalance(node) << ']' << std::endl;

    // Go to the next level of the tree
    print(prefix + "     ", node->right, true);
    print(prefix + "     ", node->left, false);

}

template <typename T>
void AVLTree<T>::remove(const T& val) {
    remove(val, root);
}


template <typename T>
void AVLTree<T>::remove(const T& val, AVLNode<T>* & node) {
    if (!node) {
        return;
    }

    else if (val < node->data) {
        remove(val, node->left);
    }

    else if (val > node->data) {
        remove(val, node->right);
    }

    else if (node->hasTwoChildren()) {
        node->data = getMinNode(node->right)->data;
        remove(node->data, node->right);
    }

    else { // leaf or one child
        AVLNode<T>* to_del = node;
        node = (node->left) ? node->left : node->right;
        delete to_del;
    }

    // Update height
    if (node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right));
    }

    balance(node);
}

template <typename T>
void AVLTree<T>::deleteNodeWithTwoChildren(AVLNode<T>* node) {
    AVLNode<T>* min_right_node = getMinNode(node->right);
    T min_val = min_right_node->data;

    if (min_right_node->isLeaf()) {
        deleteLeaf(min_right_node, searchParent(min_val));
    }
    else if (min_right_node->hasOneChild()) {
        deleteNodeWithOneChild(min_right_node, searchParent(min_val));
    }
    node->data = min_val;
}

template <typename T>
int AVLTree<T>::getHeight(const AVLNode<T>* node) const {
    return ((!node) ? 0 : node->height);
}


template <typename T>
int AVLTree<T>::getBalance(const AVLNode<T>* node) const {
    if (!node) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void AVLTree<T>::rotateRightAt(const T& val) {
    AVLNode<T>* node = search(val);
    AVLNode<T>* parent = searchParent(val);

    if (!node) {
        return;
    }
    else if (!parent) {
        root = rotateRight(root);
    }
    else if (parent->left == node) {
        parent->left = rotateRight(parent->left);
    }
    else {
        parent->right = rotateRight(parent->right);
    }
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* node) {
    if (!node || !node->left) {
        return node;
    }
    AVLNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    
    return left_kid;
}

template <typename T>
AVLNode<T>*& AVLTree<T>::searchRef(const T& val) {
    return searchRef(val, root);
}

template <typename T>
AVLNode<T>*& AVLTree<T>::searchRef(const T& val, AVLNode<T>*& node) {
    if (!node || node->data == val) {
        return node;
    }
    else if (node->data > val) {
        return searchRef(val, node->left);
    }
    else {
        return searchRef(val, node->right);
    }
}

template <typename T>
void AVLTree<T>::rotateRightRef(AVLNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    AVLNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    // Update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    left_kid->height = std::max(getHeight(left_kid->left), getHeight(node)) + 1;
    
    node = left_kid;
}

template <typename T>
void AVLTree<T>::rotateLeftRef(AVLNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    AVLNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;
    // Update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    right_kid->height = std::max(getHeight(right_kid->right), getHeight(node)) + 1;


    node = right_kid;
}


template <typename T>
void AVLTree<T>::rotateLeftDoubleRef(AVLNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    rotateRightRef(node->right);
    rotateLeftRef(node);
}

template <typename T>
void AVLTree<T>::rotateRightDoubleRef(AVLNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    rotateLeftRef(node->left);
    rotateRightRef(node);
}


template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& node) {
    if (!node) {
        return;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    if (left_height - right_height > 1) { //left unbalanced
        if(getHeight(node->left->left) >= getHeight(node->left->right)) {
            rotateRightRef(node);
        }
        else {
            rotateRightDoubleRef(node);
        }
    }
    if (right_height - left_height > 1) { //right unbalanced
        if(getHeight(node->right->right) >= getHeight(node->right->left)) {
            rotateLeftRef(node);
        }
        else {
            rotateLeftDoubleRef(node);
        }
    }
}
