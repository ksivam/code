#pragma once
#include "Graph.h"

template <class T>
class BinaryHeap
{
private: 
	int size;
	int maxSzie;
	T* arr;
	void swap(T* a, T* b);

public:
	void Insert(T item);
	T RemoveMin();
	BinaryHeap(int capacity = 100);
	~BinaryHeap();
};


template <class T>
BinaryHeap<T>::BinaryHeap(int capacity = 100)
{
	size = 0;
	arr = new T[capacity];
	maxSzie = capacity;
}

template <class T>
BinaryHeap<T>::~BinaryHeap()
{
}

template <class T>
void BinaryHeap<T>::Insert(T item)
{
	if(size < maxSzie)
	{
		arr[size++] = item;
	}

	/*
	 perform bottom up approach
	 this is zero based array

	 current = n
	 left = 2n + 1
	 right = 2n + 2
	 parent = lower of (n-1)/2
	*/
	int current = size - 1;
	while(current > 0)
	{
		int parent = (current - 1) / 2;

		// if parent is greater than child, swap
		if(arr[parent] > arr[current]) // provide > operator overloading incase of object comparison
		{
			swap(&arr[parent], &arr[current]);
			current = parent;
		} else
		{
			break;
		}
	}
}

template <class T>
T BinaryHeap<T>::RemoveMin()
{
	if(size < 0)
		return NULL;

	/*
		Perform top down approach when 
		removing the min element from the binary heap
	*/

	// min is the heap head
	T minItem = arr[0];

	/* remove the min element from the array by
		1. swap the min with last element in the array 
		2. reduce the array size by 1
	*/
	swap(&arr[0], &arr[--size]);
	int current  = 0; // perform top down approach from root
	while(current < size)
	{
		int minimum = current;
		int left = 2 * current + 1;
		int right = 2 * current + 2;

		// check the left child for min value
		if(left < size && arr[left] < arr[minimum]) // provide < operator overloading incase of object comparison
		{
			minimum = left;
		}

		// check the right child for min value
		if(right < size && arr[right] < arr[minimum]) // provide < operator overloading incase of object comparison
		{
			minimum = right;
		}

		// if min is not current
		// swap the values and move down to the next sub tree
		if(minimum != current)
		{
			swap(&arr[current], &arr[minimum]);
			current = minimum;
		} else
		{
		// if min is current value, then
		// the min heap property is restored
			break;
		}
	}

	return minItem;
}

template <class T>
void BinaryHeap<T>::swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

