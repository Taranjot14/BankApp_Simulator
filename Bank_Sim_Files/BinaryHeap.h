/*
 * BinaryHeap.h
 * 
 * Description: BinaryHeap data collection ADT class.
 *              Array implementation.
 *
 * Class invariant: It is always a FIFO.
 * 
 * Author: Taranjot Singh and Matthias Zelleke
 * Date of last modification: November 17 2023
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "EmptyDataCollectionException.h"

template <class ElementType>
class BinaryHeap {
    private:

        void reHeapUp(unsigned int indexOfElement);
        void reHeapDown(unsigned int indexOfRoot);

        static const unsigned int INITIAL_CAPACITY = 10;
        ElementType *elements; 
        unsigned int elementCount; 
        unsigned int capacity = INITIAL_CAPACITY; 

    public:
        // Default Constructor
        BinaryHeap();
        
        // Destructor
        ~BinaryHeap();
        
        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap.
        // It returns true if successful, otherwise false.
        // Time Efficiency: O(log2 n)
        bool insert(ElementType &newElement);

        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Time Efficiency: O(1)
        ElementType &retrieve() const;

        // Public method for testing purposes
        void print() const;


};

#include "BinaryHeap.cpp"
#endif
