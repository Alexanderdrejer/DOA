#include <iostream>
#include "queue_class.h"

int main(int argc, char *argv[]) {
    Queue<int> *queue = new Queue<int>();
    
    queue->put(10);
    queue->put(5);
    queue->put(3);
    queue->put(7);

    std::cout << "Front element:  " << queue->front() << std::endl;
    
    while (queue->empty() == false) {
        std::cout << "Next element:   " << queue->get() << std::endl;
    }
    
    std::cout << "Queue is empty?  " << queue->empty() << std::endl;

    delete queue;
    return 0;
}