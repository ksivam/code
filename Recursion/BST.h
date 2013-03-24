#pragma once
#include "Node.h"

template <class T>
class BST
{
public:
	Node<T>* Root;
	void insert(Node<T>** root, T value);
	BST();
	~BST();
};

template <class T>
void BST<T>::insert(Node<T>** root, T value)
{
	if(*root == nullptr)
	{		
		*root = new Node<T>(value);
		return;
	}

	if(value <= (*root)->item)
	{
		// value <= root insert into the left sub-tree
		insert(&(*root)->left, value);
	} else
	{
		// value > root insert into the right sub-tree
		insert(&(*root)->right, value);
	}
}

template <class T>
BST<T>::BST()
{
	Root = nullptr;
}

template <class T>
BST<T>::~BST()
{
}

