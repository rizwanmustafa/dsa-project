#include "Queue.hpp"
#include <iostream>
using namespace std;

/*
    This Cpp File contain the implementation of the Queue class.
*/

// Node Constructor
template <typename T>
Queue<T>::QueueNode::QueueNode(T x)
{
    this->data = x;
    this->next = nullptr;
}

// Queue Constructor
template <typename T>
Queue<T>::Queue()
{
    this->front = this->rear = nullptr;
    this->count = 0;
}

// Copy Constructor
template <typename T>
Queue<T>::Queue(const Queue &other)
{
    this->front = this->rear = nullptr;
    this->count = 0;

    QueueNode *temp = other.front;
    QueueNode *newNode = nullptr;

    while (temp != nullptr)
    {
        newNode = new QueueNode(temp->data);
        if (this->rear == nullptr)
        {
            this->front = this->rear = newNode;
        }
        else
        {
            this->rear->next = newNode;
            this->rear = newNode;
        }
        this->count++;
        temp = temp->next;
    }
}

// Check if the Queue is Empty
template <typename T>
bool Queue<T>::isEmpty() const
{
    return this->front == nullptr;
}

// Add an element to the Queue
template <typename T>
void Queue<T>::enqueue(T x)
{
    Node *temp = new Node(x);

    if (this->rear == nullptr)
    {
        this->front = this->rear = temp;
        return;
    }

    this->rear->next = temp;
    this->rear = temp;
    this->count++;
}

// Remove an element from the Queue
template <typename T>
void Queue<T>::dequeue()
{
    if (this->isEmpty())
    {
        return;
    }

    Node *temp = this->front;
    T data = temp->data;

    this->front = this->front->next;

    if (this->front == nullptr)
    {
        this->rear = nullptr;
    }
    this->count--;
    delete temp;
}

// Queue Destructor
template <typename T>
Queue<T>::~Queue()
{
    while (!this->isEmpty())
    {
        this->dequeue();
    }
}

// Size Method
template <typename T>
int Queue<T>::size() const
{
    return this->count;
}

// Front Method
template <typename T>
T Queue<T>::front() const
{
    if (this->isEmpty())
    {
        return T();
    }
    return this->front->data;
}
