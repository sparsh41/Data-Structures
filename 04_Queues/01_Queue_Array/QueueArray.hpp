#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

template <typename T, int size = 100>
class QueueArray {

    public:
        QueueArray();

        int         length() const; // Returns the length
        bool        empty() const; 
        bool        full() const;

        void        enqueue(const T& val); // Add element to the end of the queue
        const T&    front() const; // Return the first element in the queue
        const T&    dequeue(); // Remove the first element and return it
        void        clear(); // Clear the queue

        void        print() const; // Print the contents of the queue

    private:
        T data[size]; // An array of 100 elemets
        int queue_size;
        int front_idx;
        int back_idx;

};

#endif