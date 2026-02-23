#include "QueueArray.hpp"
#include "QueueArray.cpp"


int main() {
    QueueArray<int, 10> q;

    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }


    
    // Queue in a full
    q.enqueue(10);

    q.print();

    while(!q.empty()) {
        std::cout << q.dequeue() << std::endl;
    }

    q.print();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.print();
    q.clear();
    q.print();

    try {
        q.dequeue();
    }

    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    

    return 0;
}