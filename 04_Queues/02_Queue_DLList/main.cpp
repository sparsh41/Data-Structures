#include "QueueDLL.hpp"
#include "QueueDLL.cpp"

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

    return 0;
}