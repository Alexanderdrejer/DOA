
#include <iostream>
#include <string>
#include "implementation.h"

int main() {

    MaxHeap* heap = new implementation();

    std::cout << heap->isEmpty() << std::endl;

    heap->insert(1);
    heap->insert(2);
    heap->insert(3);
    heap->insert(4);

    std::cout << "Størrelsen: " << heap->size() << std::endl;
    std::cout << "Højeste værdi" << heap->findMax() << std::endl;

    for (int i = 0; i < heap->size(); ++i) {
        std::cout << heap->vector[i] << std::endl;
    }

    heap->deleteMax(); // Fjerner mit maks. For at teste at den virker, udskriver jeg vektoren igen.

   for (int i = 0; i < heap->size(); ++i) {
        std::cout << heap->vector[i] << std::endl;
    }

    return 0;
}
