/*
 * BinaryHeap.cpp
 * 
 * Description: BinaryHeap data collection ADT class.
 *              Array implementation.
 *
 * Class invariant: It is always a FIFO.
 * 
 * Author: Taranjot Singh and Matthias Zelleke
 * Date of last modification: November 17 2023
 */

#include <iostream>

// Default constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() : elementCount(0), capacity(INITIAL_CAPACITY) {
    elements = new ElementType[capacity];
}

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap.
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement) {
    if (elementCount == capacity) {
        //Thats where the resize starts
        
        unsigned int doubleCapacity = capacity * 2;
        ElementType *doubleElements = new ElementType[doubleCapacity];

        for (unsigned int i = 0; i < elementCount; i++) {
            doubleElements[i] = elements[i];
        }

        delete[] elements;
        elements = doubleElements;
        capacity = doubleCapacity;
    }

    //putting the newElement into the array
    elements[elementCount] = newElement;
    reHeapUp(elementCount);
    elementCount++;
    return true;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
    if (elementCount == 0) {
        //if binary heap is empty, can't remove
        throw EmptyDataCollectionException("Empty BinaryHeap: Cant remove.");
    }

    elements[0] = elements[elementCount - 1];
    elementCount--;
    reHeapDown(0);
}

// Description: Retrieves (but does not remove) the necessary element.
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const {
    if (elementCount == 0) {
        //if binary heap is empty, can't retrieve
        throw EmptyDataCollectionException("Empty BinaryHeap: Cant retrieve.");
    }

    return elements[0];
}

// // Public method for testing purposes
// template <class ElementType>
// void BinaryHeap<ElementType>::print() const {
//     std::cout << "Binary Heap elements: ";
//     for (unsigned int i = 0; i < elementCount; i++) {
//         std::cout << elements[i] << " ";
//     }
//     std::cout << std::endl;
// }


// Utility method
// Description: Recursively put the array back into a Min Binary Heap after adding.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfElement) {
    if (indexOfElement > 0) {
        
        //Get the parent

        unsigned int indexOfParent = (indexOfElement - 1) / 2;

        if (elements[indexOfElement] <= elements[indexOfParent]) {
            // Swap with theparent
            ElementType temp = elements[indexOfElement];
            elements[indexOfElement] = elements[indexOfParent];
            elements[indexOfParent] = temp;

            // Recursively reheap up
            reHeapUp(indexOfParent);
        }
    }
}


// Utility method
// Description: Recursively put the array back into a Min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
    unsigned int indexOfMinChild = indexOfRoot;


    //Gets the child
    unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
    unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

    if (indexOfLeftChild < elementCount && elements[indexOfLeftChild] <= elements[indexOfMinChild]) {
        indexOfMinChild = indexOfLeftChild;
    }

    if (indexOfRightChild < elementCount && elements[indexOfRightChild] <= elements[indexOfMinChild]) {
        indexOfMinChild = indexOfRightChild;
    }

    if (indexOfMinChild != indexOfRoot) {
        // Swap with the smaller child
        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[indexOfMinChild];
        elements[indexOfMinChild] = temp;

        reHeapDown(indexOfMinChild);
    }
}
