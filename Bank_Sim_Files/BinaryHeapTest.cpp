// testDriver_BinaryHeap.cpp

#include "BinaryHeap.cpp"
#include <iostream>

int main() {
    // Create a Binary Heap of integers
    BinaryHeap<int> binaryHeap;

    // Insert elements
    int elementsToInsert[] = {5, 3, 8, 2, 7, 1};
    for (int element : elementsToInsert) {
        binaryHeap.insert(element);
    }

    // Print the initial heap
    std::cout << "Initial Binary Heap: ";
    binaryHeap.print();

    // Retrieve and remove the minimum element
    try {
        std::cout << "Minimum Element: " << binaryHeap.retrieve() << std::endl;
        binaryHeap.remove();
        std::cout << "Binary Heap after removal: ";
        binaryHeap.print();
    } catch (EmptyDataCollectionException &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
