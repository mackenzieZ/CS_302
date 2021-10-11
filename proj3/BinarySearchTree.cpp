#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

template <class TData> class Node
{
private:
	Node() {}
public:
	TData data;
	Node<TData> *pleft, *pright;
	Node(const TData &dataToSort);
	~Node();
	bool IsLeaf();
};

template <class TData> class BinarySearchTreeDataMembers
{
public:
	Node<TData> *ptree;
	unsigned int height, count;
	BinarySearchTreeDataMembers();
};

template <class TData> class BinarySearchTree
{
private:
	BinarySearchTreeDataMembers<TData> *dm;
	void CopyTree(const Node<TData> *tree); // this is used by the assignment operator
	void AddNode(Node<TData> *pnode); // this is used by the Balance() operation
	void AddArray(Node<TData> **parray, const unsigned int length);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<TData> &obj); // copy constructor
	~BinarySearchTree();
	const BinarySearchTree<TData> &operator=(const BinarySearchTree<TData> &obj); // assignment operator
	void Add(const TData &data);
	bool Search(const TData &data) const;
	void Forward(void ClientFunc(const TData &)) const;
	void Backward(void ClientFunc(const TData &)) const;
	const TData *MaxValue() const; // return nullptr when tree is empty; this function could be useful to overload <, >, and == operators
	const TData *MinValue() const;
	unsigned int Height() const; // tree height; returns 0 if empty
	unsigned int Count() const; // node count; returns 0 if empty
	void Balance();
	void Clear();
};

template <class TData> Node<TData>::Node(const TData &dataToSort)
{
	pleft = nullptr;
	pright = nullptr;
	data = dataToSort;
}
template <class TData> Node<TData>::~Node()
{
	if (pleft)
	{
		delete pleft;
		pleft = nullptr;
	}
	if (pright)
	{
		delete pright;
		pright = nullptr;
	}
}
template <class TData> bool Node<TData>::IsLeaf() { return (pleft == nullptr && pright == nullptr); }

template <typename TData> void forward(void client_func(const TData &), const Node<TData> *tree)
{
	if (tree)
	{
		forward(client_func, tree->pleft);
		client_func(tree->data);
		forward(client_func, tree->pright);
	}
}

template <typename TData> void backward(void client_func(const TData &), const Node<TData> *tree)
{
	if (tree)
	{
		backward(client_func, tree->pright);
		client_func(tree->data);
		backward(client_func, tree->pleft);
	}
}

template <typename TData> void FillArray(Node<TData> *tree, Node<TData> **parray, unsigned int &index)
{
	if (tree)
	{
		FillArray(tree->pleft, parray, index);
		parray[index++] = tree;
		FillArray(tree->pright, parray, index);
	}
}

template <class TData> BinarySearchTreeDataMembers<TData>::BinarySearchTreeDataMembers()
{
	ptree = nullptr;
	height = 0;
	count = 0;
}

template <class TData> BinarySearchTree<TData>::BinarySearchTree(const BinarySearchTree<TData> &obj)
{
	dm = new BinarySearchTreeDataMembers<TData>();
	this->operator=(obj);
}

template <class TData> BinarySearchTree<TData>::BinarySearchTree()
{
	dm = new BinarySearchTreeDataMembers<TData>();
}

template <class TData> BinarySearchTree<TData>::~BinarySearchTree()
{
	Clear();
	delete dm;
}

template <class TData> const BinarySearchTree<TData> &BinarySearchTree<TData>::operator=(const BinarySearchTree<TData> &obj)
{
	if (this != &obj)
	{
		Clear();
		CopyTree(obj.dm->ptree);
	}
	return (*this);
}

template <class TData> void BinarySearchTree<TData>::CopyTree(const Node<TData> *tree)
{
	if (tree)
	{
		Add(tree->data);
		CopyTree(tree->pleft);
		CopyTree(tree->pright);
	}
}

template <class TData> void BinarySearchTree<TData>::Add(const TData &data)
{
	Node<TData> **root = &dm->ptree;
	unsigned int height = 0;
	while (*root)
	{
		height++;
		if ((*root)->data == data)
		{
			if (height > dm->height)
				dm->height = height;
			return;
		}
		if ((*root)->data > data)
			root = &(*root)->pleft;
		else
			root = &(*root)->pright;
	}
	(*root) = new Node<TData>(data);
	dm->count++;
	height++;
	if (height > dm->height)
		dm->height = height;
}

template <class TData> unsigned int BinarySearchTree<TData>::Height() const
{
	return dm->height;
}

template <class TData> unsigned int BinarySearchTree<TData>::Count() const
{
	return dm->count;
}

template <class TData> void BinarySearchTree<TData>::AddNode(Node<TData> *pnode)
{
	Node<TData> **root = &dm->ptree;
	unsigned int height = 0;
	while (*root)
	{
		height++;
		if (pnode->data < (*root)->data)
			root = &(*root)->pleft;
		else
			root = &(*root)->pright;
	}
	(*root) = pnode;
	height++;
	if (height > dm->height)
		dm->height = height;
}

template <class TData> void BinarySearchTree<TData>::AddArray(Node<TData> **parray, const unsigned int length)
{
	if (length)
	{
		const unsigned int middle = length / 2;
		AddNode(parray[middle]);
		if (middle + 1 < length)
			AddArray(parray + middle + 1, length - middle - 1);
		if (middle)
			AddArray(parray, length - middle - (length & 1));
	}
}

template <class TData> void BinarySearchTree<TData>::Balance()
{
	dm->height = 0;
	const unsigned int count = dm->count;
	Node<TData> **parray = new Node<TData>*[count];
	unsigned int index = 0;
	FillArray(dm->ptree, parray, index);
	for (index = 0; index < count; index++)
		parray[index]->pleft = parray[index]->pright = nullptr;
	dm->ptree = nullptr;
	AddArray(parray, count);
	delete[]parray;
}

template <class TData> bool BinarySearchTree<TData>::Search(const TData &data) const
{
	Node<TData> *root = dm->ptree;
	while (root)
	{
		if (root->data == data)
			return true;
		if (data < root->data)
			root = root->pleft;
		else
			root = root->pright;
	}
	return false;
}

template <class TData> void BinarySearchTree<TData>::Forward(void ClientFunc(const TData &)) const
{
	forward(ClientFunc, dm->ptree);
}

template <class TData> void BinarySearchTree<TData>::Backward(void ClientFunc(const TData &)) const
{
	backward(ClientFunc, dm->ptree);
}

template <class TData> const TData *BinarySearchTree<TData>::MinValue() const
{
	Node<TData> *pnode = dm->ptree;
	while (pnode && pnode->pleft)
		pnode = pnode->pleft;
	if (pnode)
		return &pnode->data;
	return nullptr;
}

template <class TData> const TData *BinarySearchTree<TData>::MaxValue() const
{
	Node<TData> *pnode = dm->ptree;
	while (pnode && pnode->pright)
		pnode = pnode->pright;
	if (pnode)
		return &pnode->data;
	return nullptr;
}

template <class TData> void BinarySearchTree<TData>::Clear()
{
	if (dm->ptree)
	{
		delete dm->ptree;
		dm->ptree = nullptr;
		dm->count = dm->height = 0;
	}
}