// File:MinHeap.cpp
// Heape Class implementation file (Minimum heap for graph edges)


// Member Functions
#include"MinHeap.h"

// Constructor with argument. max size is mVal elements 
// not including a[0] which will receive a weight -32767
// The constructor creates the heap array, initializes
// the end of the heap to N=0,and itmMin
MinHeap::MinHeap(int mVal)
{
	a = new Node[mVal + 1]; 	N = 0;
	MaxSize = mVal; itemMin = -32767; // Minimum Heap
	a[0].exchangeRate = itemMin;
}
// Class Destructor
MinHeap::~MinHeap()
{
	delete[] a;
}

// Heap Adjustment Functions
// upheap element at location (k) in the heap
// as long as it is less than the parent

void MinHeap::upheap(int k)
{
	Node e = a[k];
	while (e.exchangeRate <= a[k / 2].exchangeRate)
	{
		a[k] = a[k / 2];   k = k / 2;
	}
	a[k] = e;
}

// downheap element at (k) in the heap
void MinHeap::downheap(int k)
{
	int j = 2 * k;     Node e = a[k];
	while (j <= N) {
		if ((j < N) && (a[j + 1].exchangeRate < a[j].exchangeRate)) j++;
		if (e.exchangeRate <= a[j].exchangeRate) break;
		a[j / 2] = a[j];     j *= 2;
	}
	a[j / 2] = e;
}

// Insert (e) in a heap and adjust heap
void MinHeap::insert(Node e)
{
	a[++N] = e;    upheap(N);
}


// remove and return top of the heap, then adjust heap
Node MinHeap::remove()
{
	Node e = a[1];
	a[1] = a[N--]; downheap(1);
	return e;
}