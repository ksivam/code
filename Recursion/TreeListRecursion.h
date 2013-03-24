#pragma once
#include "BST.h"

/*
Tree to doubly linked list problem: http://cslibrary.stanford.edu/109/
*/

template <class T>
class TreeListRecurion
{
public:
	Node<T>* Head;
	Node<T>* Tail;
	void TreeToList(Node<T>* root);
	TreeListRecurion();
	~TreeListRecurion();
};

template <class T>
void TreeListRecurion<T>::TreeToList(Node<T>* current)
{	
	if(current == nullptr)
	{
		return;
	}

	TreeToList(current->left);
	if(Head == nullptr)
	{
		Head = Tail = current;
		return;
	}

	if(current->item <= Head->item)
	{
		Head->left = current;
		current->right = Head;
		Head = current;
	} else
	{
		Tail->right = current;
		current->left = Tail;
		Tail = current;
	}

	TreeToList(current->right);
	if(current->item <= Head->item)
	{
		Head->left = current;
		current->right = Head;
		Head = current;
	} else
	{
		Tail->right = current;
		current->left = Tail;
		Tail = current;
	}
}

template <class T>
TreeListRecurion<T>::TreeListRecurion()
{
	Head = nullptr;
	Tail = nullptr;
}

template <class T>
TreeListRecurion<T>::~TreeListRecurion()
{
}

