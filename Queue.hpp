#pragma once
#ifndef Queue
#define Queue_Hpp

template <typename T>
class Queue
{
    struct QueueNode
    {
        T data;
        QueueNode *next;

        QueueNode(T x);
    };

    QueueNode<T> *front;
    QueueNode<T> *rear;
    int count;

public:
    Queue();
    Queue(const Queue &other);
    bool isEmpty() const;
    void enqueue(T x);
    void dequeue();
    T front() const;
    int size() const;
    ~Queue();
};

#endif // QUEUE_HPP