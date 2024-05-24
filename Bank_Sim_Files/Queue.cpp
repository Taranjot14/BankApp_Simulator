/*
 * Queue.cpp
 * 
 * Description: Queue data collection ADT class.
 *              Circular array implementation.
 *
 * Class invariant: It is always a FIFO.
 * 
 * Author: Taranjot Singh and Matthias Zelleke
 * Date of last modification: November 17 2023
 */



// Implementation of Queue member functions



// Description: Default constructor
template<class ElementType>
Queue<ElementType>::Queue() {
    elements = new ElementType[INITIAL_CAPACITY];
    elementCount = 0;
    capacity = INITIAL_CAPACITY;
    frontindex = 0;
    backindex = 0;
}

// Description: Destructor
template<class ElementType>
Queue<ElementType>::~Queue() {
    delete[] elements;
}

// Description: Returns true if the Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue, 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    if (elementCount == capacity) {
        // Resize the array if needed
        unsigned int doubleCapacity = capacity * 2;
        ElementType* doubleElements = new ElementType[doubleCapacity];
        unsigned int newFrontIndex = frontindex;

        for (unsigned int i = frontindex; i < elementCount + frontindex; i++) {
            doubleElements[i] = elements[i % capacity];
        }

        delete[] elements;
        elements = doubleElements;
        capacity = doubleCapacity;
        frontindex = newFrontIndex;
        backindex = frontindex + elementCount;
    }

    elements[backindex] = newElement;
    elementCount++;
    backindex = (backindex + 1) % capacity;
    return true;
}

// Description: Removes the element at the "front" of this Queue 
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue() {
    if (!isEmpty()) {
        elementCount--;
        frontindex = (frontindex + 1) % capacity;
    } else {
        //if queue has no elements, can't dequeue
        throw EmptyDataCollectionException("Dequeue from empty queue.");
    }
}

// Description: Returns the element at the "front" of this Queue
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
ElementType & Queue<ElementType>::peek() const {
    if (!isEmpty()) {
        return elements[frontindex];
    } else {
        // if queue has no elements, can't peek
        throw EmptyDataCollectionException("Peek from an empty queue");
    }
}


template<class ElementType>
void Queue<ElementType>::print() const {
    std::cout << "Elements are: ";
    for (unsigned int i = frontindex; i < elementCount + frontindex; i++) {
        std::cout << elements[i % capacity] << ", ";
    }
    std::cout << std::endl;
}
