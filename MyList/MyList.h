#include "Node.h"
template <class T>
class IList
{
public: 
	virtual Node<T>* top() = 0;
	virtual void insert(Node<T>* value) = 0;
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
	void insert(Node<T>* value);
	Node<T>* top();
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
	void insert(Node<T>* value);
	Node<T>* top();
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
void Queue<T>::insert(Node<T>* value)
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
Node<T>* Queue<T>::top()
{
	Node<T>* returnValue = nullptr;
	if(head != nullptr)
	{
		Node<T>* top = head;
		head = top->right;

		returnValue = top->nodeItem;
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
void Stack<T>::insert(Node<T>* value)
{
	Node<T>* n = new Node<T>(value);
	n->right = head;
	head = n;	
}

template <class T> 
Node<T>* Stack<T>::top()
{
	Node<T>* retValue = nullptr;
	if(head != nullptr)
	{
		retValue = head->nodeItem;
		head = head->right;
	}
	return retValue;
}

template <class T> 
bool Stack<T>::IsEmpty()
{
	return head == nullptr;
}


