#pragma once
#include "MyList.h"

template <class T>
class PrintAncestorBinaryTree
{
private: 
	IList<T>* s;
	void printQueue();

public:
	T value;
	Node<T>* Head;
	PrintAncestorBinaryTree(T val);
	~PrintAncestorBinaryTree();
	bool PrintAncestor(Node<T>* node);
};


template <class T>
PrintAncestorBinaryTree<T>::PrintAncestorBinaryTree(T val)
{
	value = val;
	s = new Stack<T>();
	Head = nullptr;
}

template <class T>
PrintAncestorBinaryTree<T>::~PrintAncestorBinaryTree()
{
}

template <class T>
bool PrintAncestorBinaryTree<T>::PrintAncestor(Node<T>* node)
{
	if(node == nullptr)
		return false;

	s->insert(node->item);

	bool ret = PrintAncestor(node->left);
	if(ret)
		s->top();

	if(node->item == value && !s->IsEmpty())
	{
		s->top();
		printQueue();
	}

	ret = PrintAncestor(node->right);
	if(ret)
		s->top();

	if(node->item == value && !s->IsEmpty())
	{
		s->top();
		printQueue();
	}

	return true;
}

template <class T>
void PrintAncestorBinaryTree<T>::printQueue()
{
	while(!s->IsEmpty())
	{
		std::cout << s->top() << " ";
	}
}
