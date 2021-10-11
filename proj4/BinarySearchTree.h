#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include <iostream>

template <typename T>
class BinarySearchTree {
    public:
        BinarySearchTree();
        BinarySearchTree(const T & rootItem);
        BinarySearchTree(const BinarySearchTree<T> & other);
        ~BinarySearchTree();

        BinarySearchTree<T> & operator=(const BinarySearchTree<T> & rhs);

        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;

        T getRootData() const;
        void setRootData(const T & item);

        bool add(const T & item);
        bool remove (const T & item);
        void clear();

        T getEntry(const T & item);
        bool contains(const T & item) const;

        // Traversal
        void preorderTraverse() const;
        void inorderTraverse() const;
        void postorderTraverse() const;
    protected:
        std::shared_ptr<BinaryNode<T> > copyTree(const std::shared_ptr<BinaryNode<T> > oldTreeRootPtr) const;

        void preorderTraverse(std::shared_ptr<BinaryNode<T> > node) const;
        void inorderTraverse(std::shared_ptr<BinaryNode<T> > node) const;
        void postorderTraverse(std::shared_ptr<BinaryNode<T> > node) const;

        int getHeight(std::shared_ptr<BinaryNode<T> > node) const;
        int getNumberOfNodes(std::shared_ptr<BinaryNode<T> > node) const;

        std::shared_ptr<BinaryNode<T> > placeNode(std::shared_ptr<BinaryNode<T> > subtree, std::shared_ptr<BinaryNode<T> > newNode);
        std::shared_ptr<BinaryNode<T> > removeValue(std::shared_ptr<BinaryNode<T> > subtree, const T target, bool & successful);
        std::shared_ptr<BinaryNode<T> > removeNode(std::shared_ptr<BinaryNode<T> > node);
        std::shared_ptr<BinaryNode<T> > removeLeftmostNode(std::shared_ptr<BinaryNode<T> > subtree, T & inorderSuccessor);
        std::shared_ptr<BinaryNode<T> > findNode(std::shared_ptr<BinaryNode<T> > subtree, const T & target) const;

        void destroyTree(std::shared_ptr<BinaryNode<T> > node);
    private:
        std::shared_ptr<BinaryNode<T> > m_root;
};

#include "BinarySearchTree.cpp"

#endif

