#pragma once
#include <stdio.h>

template <class T>
class Node
{
public:
	bool visited;
	T item;
	Node<T>* nodeItem;
	Node<T>* left;
	Node<T>* right;
	Node(T item);
	Node(Node<T>* node);
	~Node();
	static void printList(Node<T>* head);
	typedef T type;
};

template <class T>
Node<T>::Node(Node<T>* node)
{
	nodeItem = node;
	visited = false;
	left = right = nullptr;
}

template <class T>
Node<T>::Node(T _item)
{
	item = _item; 
	nodeItem = nullptr;
	visited = false;
	left = right = nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template <class T> 
static void Node<T>::printList(Node<T>* head)
{
	Node<T>* current = head;
	while(current != nullptr)
	{
		printf("%d \n", current->item);
		current = current->right;
	}
}