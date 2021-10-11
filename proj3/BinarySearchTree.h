//BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

class BinaryNode {
private:

    int item;
    BinaryNode* leftChildPtr;

    BinaryNode* rightChildPtr;

public:

    //constructors and destructors

    BinaryNode ();

    BinaryNode (const int & anItem);

    BinaryNode (const int & anItem, BinaryNode* leftPtr, BinaryNode* rightPtr);

    //public operations

    void setItem (const int & anItem);

    int getItem () const;

    bool isLeaf () const;

    BinaryNode* getLeftChildPtr () const;

    BinaryNode* getRightChildPtr () const;

    void setLeftChildPtr (BinaryNode* leftPtr);

    void setRightChildPtr (BinaryNode* rightPtr);

};

/*
Unsorted binary tree class. Uses binary nodes to build the tree. Adapted from textbook code.
*/

class BinaryNodeTree: public BinaryNode {

private:

    BinaryNode* rootPtr;

protected:

    //helper functions

    int getHeightHelper (BinaryNode* subTreePtr) const;

    int getNumberOfNodesHelper (BinaryNode* subTreePtr) const;

    void destroyTree (BinaryNode* subTreePtr);

    BinaryNode* balancedAdd (BinaryNode* subTreePtr, BinaryNode* newNodePtr);

    BinaryNode* removeValue (BinaryNode* subTreePtr, const int target, bool & success);

    BinaryNode* moveValuesUpTree (BinaryNode* subTreePtr);

    BinaryNode* findNode (BinaryNode* treePtr, const int & target, bool & success) const;

    BinaryNode* copyTree (const BinaryNode* treePtr) const;

    void preorder (void visit (int &), BinaryNode* treePtr) const;

    void inorder (void visit (int &), BinaryNode* treePtr) const;

    void postorder (void visit (int &), BinaryNode* treePtr) const;

public:

    //constructors and destructors

    BinaryNodeTree ();

    BinaryNodeTree (const int & rootItem);

    BinaryNodeTree (const int & rootItem, const BinaryNodeTree* leftTreePtr,
                    const BinaryNodeTree* rightTreePtr);

    BinaryNodeTree (const BinaryNodeTree& tree);

    virtual ~ BinaryNodeTree ();

    //public operations

    bool isEmpty () const;

    int getHeight () const;

    int getNumberOfNodes () const;

    int getRootData () const;

    void setRootData (const int & newData);

    bool add (const int & newData);

    bool remove (const int & data);

    void clear ();

    int getEntry (const int & anEntry) const;

    bool contains (const int & anEntry) const;

    void preorderTraverse (void visit (int &)) const;

    void inorderTraverse (void visit (int &)) const;

    void postorderTraverse (void visit (int &)) const;

    //overloaded operators

    BinaryNodeTree& operator= (const BinaryNodeTree & rightHandSide);

};

//Sorted binary tree class.

class BinarySearchTree: public BinaryNodeTree
{
    private:
    BinaryNode* rootPtr;

    protected:

    //helper functions

    BinaryNode* insertInorder (BinaryNode* subTreePtr, BinaryNode* newNodePtr);

    BinaryNode* removeValue (BinaryNode* subTreePtr, const int target, bool & success);

    BinaryNode* removeNode (BinaryNode* nodePtr);

    BinaryNode* removeLeftmostNode (BinaryNode* nodePtr, int & inorderSuccessor);

    BinaryNode* findNode (BinaryNode* treePtr, const int & target) const;

    public:

    //constructors and destructors

    BinarySearchTree ();

    BinarySearchTree (const int & rootItem);

    BinarySearchTree (const BinarySearchTree&tree);

    ~BinarySearchTree ();

    //public operations

    bool isEmpty () const;

    int getHeight () const;

    int getNumberOfNodes () const;

    int getRootData () const;

    void setRootData (const int & newData);

    bool add (const int & newEntry);

    bool remove (const int & anEntry);

    void clear ();

    int getEntry (const int & anEntry) const;

    bool contains (const int & anEntry) const;

    void preorderTraverse (void visit (int &)) const;

    void inorderTraverse (void visit (int &)) const;

    void postorderTraverse (void visit (int &)) const;

    //overloaded operators

    BinarySearchTree& operator= (const BinarySearchTree& rightHandSide);

};

#endif //BINARYSEARCHTREE_H