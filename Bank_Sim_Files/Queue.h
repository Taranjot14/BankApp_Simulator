/*
 * Queue.h
 * 
 * Description: Queue data collection ADT class.
 *              Circular array implementation.
 *
 * Class invariant: It is always a FIFO.
 * 
 * Author: Taranjot Singh and Matthias Zelleke
 * Date of last modification: November 17 2023
 */

#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {

private:
    static const unsigned int INITIAL_CAPACITY = 6;
    ElementType* elements;
    unsigned int elementCount;
    unsigned int capacity;
    unsigned int frontindex;
    unsigned int backindex;

public:

    // Description: Default constructor
    Queue();

    // Description: Destructor
    ~Queue();

    // Description: Returns true if the Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue, 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType& newElement);

    // Description: Removes (but doesn't return) the element at the "front" of this Queue 
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    ElementType& peek() const;

    // Description: Prints the elements in the Queue
    // Time Efficiency: O(N)
    void print() const;

};

#include "Queue.cpp"
#endif
