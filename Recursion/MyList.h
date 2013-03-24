#pragma once
#include "Node.h"

static Node<int>* BuildTree()
{
	Node<int>* n1 = new Node<int>(1);
	Node<int>* n2 = new Node<int>(2);
	Node<int>* n3 = new Node<int>(3);
	Node<int>* n4 = new Node<int>(4);
	Node<int>* n5 = new Node<int>(5);
	Node<int>* n6 = new Node<int>(6);
	Node<int>* n7 = new Node<int>(7);
	Node<int>* n8 = new Node<int>(8);
	Node<int>* n9 = new Node<int>(9);
	Node<int>* n10 = new Node<int>(10);
	Node<int>* n11 = new Node<int>(11);
	Node<int>* n12 = new Node<int>(12);
	Node<int>* n13 = new Node<int>(13);
	Node<int>* n14 = new Node<int>(14);
	Node<int>* n15 = new Node<int>(15);

	n1->left = n3;
	n1->right = n5;

	n3->left = n13;
	n3->right = n15;

	n5->left = n7;

	n15->left = n12;

	return n1;
}

template <class T>
class IList
{
public: 
	virtual T top() = 0;
	virtual void insert(T value) = 0;
	virtual bool IsEmpty() = 0;
};

/////////////////////
/// First in last out
/////////////////////
template <class T>
class Stack : public IList<T>
{
private: 
	Node<T>* head;

public:
	Stack();
	~Stack();
	void insert(T value);
	T top();
	bool IsEmpty();
};

////////////////
// Queue: First in First out
////////////////
template <class T>
class Queue : public IList<T>
{
private: 
	Node<T>* head;
	Node<T>* tail;
public:
	Queue();
	~Queue();
	void insert(T value);
	T top();
	bool IsEmpty();
};

template <class T>
Queue<T>::Queue()
{
	head = tail = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T> 
void Queue<T>::insert(T value)
{
	Node<T>* n = new Node<T>(value);
	if(head == nullptr)
	{
		head = tail = n;
	} else
	{
		tail->right = n;
		tail = n;
	}	
}

template <class T>
T Queue<T>::top()
{
	T returnValue;
	if(head != nullptr)
	{
		Node<T>* top = head;
		head = top->right;

		returnValue = top->item;
		top->left = top->right	= nullptr;
	}
	return returnValue;
}

template <class T> 
bool Queue<T>::IsEmpty()
{
	return head == nullptr;
}


template <class T> 
Stack<T>::Stack()
{
	head = nullptr;
}

template <class T> 
Stack<T>::~Stack()
{
}

template <class T> 
void Stack<T>::insert(T value)
{
	Node<T>* n = new Node<T>(value);
	n->right = head;
	head = n;	
}

template <class T> 
T Stack<T>::top()
{
	T retValue;
	if(head != nullptr)
	{
		Node<T>* top = head;
		head = top->right;
		retValue = top->item;
		
		top->left = top->right = nullptr;
	}
	return retValue;
}

template <class T> 
bool Stack<T>::IsEmpty()
{
	return head == nullptr;
}


