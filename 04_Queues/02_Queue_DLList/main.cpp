#include "QueueDLL.hpp"
#include "QueueDLL.cpp"

#include <stdexcept>

int main() {

    QueueDLL<int> q;

    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }

    q.print();

    q.dequeue();

    q.print();

    q.clear();

    q.print();

    try {
        q.dequeue();
    }

    catch (std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}