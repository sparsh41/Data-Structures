#include "QueueDLL.hpp"

template <typename T>
QueueDLL<T>::QueueDLL() {
    data = new DLList<T>;
}

template <typename T>
void QueueDLL<T>::enqueue(const T& val) {
    data->push_back(val);
}

template <typename T>
const T& QueueDLL<T>::dequeue() {
    T first = front();
    data->pop_front();
    return first;
}

template <typename T>
void QueueDLL<T>::print() const {
    data->print_list();
}

template <typename T>
const T& QueueDLL<T>::front() const {
    return data->head->data;
}

template <typename T>
bool QueueDLL<T>::empty() const {
    return data->empty();
}

template <typename T>
bool QueueDLL<T>::full() const {
    return data->full();
}

template <typename T>
void QueueDLL<T>::clear() {
    data->clear();
}