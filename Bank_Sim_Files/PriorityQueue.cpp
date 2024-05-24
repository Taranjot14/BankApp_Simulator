
/*
* PriorityQueue.cpp
*
* Description: Priority Queue ADT Class using a Min Binary Heap
*              as its data structure
*
* Class Invariant: Elements enqueued/dequeued in a sorted FIFO fashion.
*
* Authors: Matthias Zelleke and Taranjot Singh
* 
* Last Modification: Nov. 2023
*
*/

#include <iostream>
// #include "PriorityQueue.h" // Header file for Priority Queue class

using std::cout;
using std::endl;

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    heap = new BinaryHeap<ElementType>();
}

// Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    delete heap;
    heap = nullptr;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return (heap->getElementCount() == 0);
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement) {
    return (heap->insert(newElement));
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    try {
        heap->remove();
    }
    catch (EmptyDataCollectionException& anException) {
        throw anException;
    }
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const {
    return (heap->retrieve());
}

//Description: Prints all the elements
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(N)

template <class ElementType>
void PriorityQueue<ElementType>::printQueue() {
    heap->print();

}
	
