#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "BinarySearchTree.h"

// Constructors & Destructors
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_root(NULL) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T & rootItem) : m_root(rootItem) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> & other) {
    m_root = other.copyTree(other.m_root);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTree(m_root);
}

// Add
template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::placeNode(std::shared_ptr<BinaryNode<T> > subtree, std::shared_ptr<BinaryNode<T> > newNode) {
    if (subtree == nullptr) {
        return newNode;
    }
    else if (subtree->m_value > newNode->m_value) {
        subtree->m_leftChild = placeNode(subtree->m_leftChild, newNode);
    }
    else {
        subtree->m_rightChild = placeNode(subtree->m_rightChild, newNode);
    }
    return subtree;
}

template <typename T>
bool BinarySearchTree<T>::add(const T & item) {
    std::shared_ptr<BinaryNode<T> > newNode = std::make_shared<BinaryNode<T> >(item);
    m_root = placeNode(m_root, newNode);
    return true;
}

// Empty
template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return m_root == nullptr;
}

// Root
template <typename T>
T BinarySearchTree<T>::getRootData() const {
    return m_root->m_value;
}

template <typename T>
void BinarySearchTree<T>::setRootData(const T & item) {
    m_root->m_value = item;
}

// Height
template <typename T>
int BinarySearchTree<T>::getHeight() const {
    return getHeight(m_root);
}

template <typename T>
int BinarySearchTree<T>::getHeight(std::shared_ptr<BinaryNode<T> > node) const {
    if (node == nullptr) return 0;
    return 1 + std::max(getHeight(node->m_leftChild), getHeight(node->m_rightChild));
}

// Number of nodes
template <typename T>
int BinarySearchTree<T>::getNumberOfNodes() const {
    return getNumberOfNodes(m_root);
}

template <typename T>
int BinarySearchTree<T>::getNumberOfNodes(std::shared_ptr<BinaryNode<T> > node) const {
    if (node == nullptr) return 0;
    return 1 + getNumberOfNodes(node->m_leftChild) + getNumberOfNodes(node->m_rightChild);
}

// Search
template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::findNode(std::shared_ptr<BinaryNode<T> > subtree, const T & target) const {
    if (subtree == nullptr || subtree->m_value == target) {
        return subtree;
    } 
    
    if (subtree->m_value < target) {
        return findNode(subtree->m_rightChild, target);
    }
    return findNode(subtree->m_leftChild, target);
}

template <typename T>
T BinarySearchTree<T>::getEntry(const T & item) {
    std::shared_ptr<BinaryNode<T> > found = findNode(m_root, item);
    if (found == nullptr) {
        std::cout << "Entry " << item << " not found in tree.";
        return T();
    }
    return found->m_value;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T & item) const {
    return findNode(m_root, item) != nullptr;
}

// Remove
template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::removeValue(std::shared_ptr<BinaryNode<T> > subtree, const T target, bool & successful) {
    if (subtree == nullptr) {
        successful = false;
    }
    else if (subtree->m_value == target) {
        subtree = removeNode(subtree);
        successful = true;
    }
    else if (subtree->m_value > target) {
        std::shared_ptr<BinaryNode<T> > temp = removeValue(subtree->m_leftChild, target, successful);
        subtree->m_leftChild = temp;
    }
    else {
        std::shared_ptr<BinaryNode<T> > temp = removeValue(subtree->m_rightChild, target, successful);
        subtree->m_rightChild = temp;
    }
    return subtree;
}

template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::removeNode(std::shared_ptr<BinaryNode<T> > node) {
    if (node->m_leftChild == nullptr || node->m_rightChild == nullptr) {
        return node->m_leftChild != nullptr ? node->m_leftChild : node->m_rightChild;
    }
    else {
        T successorValue;
        std::shared_ptr<BinaryNode<T> > temp = removeLeftmostNode(node->m_rightChild, successorValue);
        node->m_value = successorValue;
        node->m_rightChild = temp;
        return node;
    }
}

template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::removeLeftmostNode(std::shared_ptr<BinaryNode<T> > subtree, T & inorderSuccessor) {
    if (subtree->m_leftChild == nullptr) {
        inorderSuccessor = subtree->m_value;
        return removeNode(subtree);
    }
    else {
        std::shared_ptr<BinaryNode<T> > temp = removeLeftmostNode(subtree->m_leftChild, inorderSuccessor);
        subtree->m_leftChild = temp;
        return subtree;
    }
}

template <typename T>
bool BinarySearchTree<T>::remove(const T & item) {
    bool success = false;
    removeValue(m_root, item, success);
    return success;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    destroyTree(m_root);
}

template <typename T>
void BinarySearchTree<T>::destroyTree(std::shared_ptr<BinaryNode<T> > node) {
    if (node != nullptr) {
        destroyTree(node->m_leftChild);
        destroyTree(node->m_rightChild);
        node.reset();
    }
}

// Traversal
template <typename T>
void BinarySearchTree<T>::preorderTraverse() const {
    preorderTraverse(m_root);
}

template <typename T>
void BinarySearchTree<T>::preorderTraverse(std::shared_ptr<BinaryNode<T> > node) const {
    if (node == nullptr) return;
    std::cout << node->m_value << " ";
    preorderTraverse(node->m_leftChild);
    preorderTraverse(node -> m_rightChild);
}

template <typename T>
void BinarySearchTree<T>::inorderTraverse() const {
    inorderTraverse(m_root);
}

template <typename T>
void BinarySearchTree<T>::inorderTraverse(std::shared_ptr<BinaryNode<T> > node) const {
    if (node == nullptr) return;
    inorderTraverse(node->m_leftChild);
    std::cout << node->m_value << " ";
    inorderTraverse(node -> m_rightChild);
}

template <typename T>
void BinarySearchTree<T>::postorderTraverse() const {
    postorderTraverse(m_root);
}

template <typename T>
void BinarySearchTree<T>::postorderTraverse(std::shared_ptr<BinaryNode<T> > node) const {
    if (node == nullptr) return;
    postorderTraverse(node->m_leftChild);
    postorderTraverse(node -> m_rightChild);
    std::cout << node->m_value << " ";
}

// Copy
template <typename T>
std::shared_ptr<BinaryNode<T> > BinarySearchTree<T>::copyTree(const std::shared_ptr<BinaryNode<T> > oldTreeRoot) const {
    std::shared_ptr<BinaryNode<T> > newTree;
    if (oldTreeRoot != nullptr) {
        newTree = std::make_shared<BinaryNode<T> >(oldTreeRoot->m_value);
        newTree->m_leftChild = copyTree(oldTreeRoot->m_leftChild);
        newTree->m_rightChild = copyTree(oldTreeRoot->m_rightChild);
    }
    return newTree;
}

template <typename T>
BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree<T> & rhs) {
    clear();
    m_root = rhs.copyTree(rhs.m_root);
}

#endif