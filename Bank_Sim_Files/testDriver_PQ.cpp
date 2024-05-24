/* 
 * testDriver_PQ.cpp
 *
 * Description: Priority Queue test driver.
 *
 * Author:
 * Date:
 */
#include <iostream>
#include "PriorityQueue.h"

using std::cout;
using std::endl;

int main() {
    PriorityQueue<int> priorityQueue;

    // Test case 1: Insert random elements into the priority queue
    cout << "Inserting random elements into the priority queue:" << endl;
    int randomArray1[10] = {42, 17, 78, 36, 91, 55, 23, 68, 14, 87};

    for (int i = 0; i < 10; i++) {
        cout << "Enqueue: " << randomArray1[i] << endl;
        priorityQueue.enqueue(randomArray1[i]);
        cout << "Printing the elements of the priority queue:" << endl;
        priorityQueue.printQueue();
    }

    // Test case 2: Check if the priority queue is empty
    cout << "\nChecking if the priority queue is empty:" << endl;
    if (priorityQueue.isEmpty()) {
        cout << "Priority queue is empty." << endl;
    } else {
        cout << "Priority queue is not empty." << endl;
    }

    // Test case 3: Dequeue elements from the priority queue
    cout << "\nDequeuing elements from the priority queue:" << endl;
    while (!priorityQueue.isEmpty()) {
        cout << "Peek: " << priorityQueue.peek() << " (Before dequeue)" << endl;
        priorityQueue.dequeue();
        cout << "Dequeued. New Peek: ";
        try {
            cout << priorityQueue.peek() << endl;
        } catch (const EmptyDataCollectionException& e) {
            cout << e.what() << endl;
        }
    }

    // Test case 4: Try to dequeue from an empty priority queue
    cout << "\nTrying to dequeue from an empty priority queue:" << endl;
    try {
        priorityQueue.dequeue();
    } catch (const EmptyDataCollectionException& e) {
        cout << e.what() << endl;
    }

    // Test case 5: Try to peek at an empty priority queue
    cout << "\nTrying to peek at an empty priority queue:" << endl;
    try {
        cout << priorityQueue.peek() << endl;
    } catch (const EmptyDataCollectionException& e) {
        cout << e.what() << endl;
    }

    // Test case: Print the final elements of the priority queue
    cout << "\nFinal elements of the priority queue:" << endl;
    priorityQueue.printQueue();

    return 0;
}
