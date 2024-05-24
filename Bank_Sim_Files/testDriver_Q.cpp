#include "Queue.h" // Include the implementation file for template instantiation
#include "EmptyDataCollectionException.h"

int main() {
    try {
        Queue<double> myQueue;
        double x = 10;
        double y = 20;
        double z = 30;
        // Enqueue some elements
        myQueue.enqueue(x);
        myQueue.enqueue(y);
        myQueue.enqueue(z);

        // Print the elements in the queue
        myQueue.print(); // Should print: Elements are: 10, 20, 30,

        // Dequeue an element
        myQueue.dequeue();

        // Print the elements after dequeue
        myQueue.print(); // Should print: Elements are: 20, 30,

        // Peek at the front element
        std::cout << "Front element: " << myQueue.peek() << std::endl; // Should print: Front element: 20

        // Dequeue the remaining elements
        myQueue.dequeue();
        myQueue.dequeue();

        // Attempt to peek or dequeue from an empty queue (should throw EmptyDataCollectionException)
        // Uncommenting the next two lines will result in an exception being thrown.
        myQueue.peek();
        myQueue.dequeue();
    } catch (const EmptyDataCollectionException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
