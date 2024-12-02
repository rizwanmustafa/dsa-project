#pragma once
#include <iostream>

using namespace std;

#ifndef STACK_HPP
#define Stack_HPP

template <typename T>
class Stack
{
    struct StackNode
    {
        T data;
        StackNode *next;
        StackNode(T data);
    };

    StackNode *top;
    int count;

public:
    Stack();
    Stack(const Stack &other);
    ~Stack();
    void push(T data);
    void pop();
    T peek() const;
    bool isEmpty();
    int size() const;
    T &operator[](int index) const;
};

template <typename T>
Stack<T>::StackNode::StackNode(T data)
{
    this->data = data;
    this->next = nullptr;
}

// Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack &other)
{
    this->top = nullptr;
    this->count = 0;

    StackNode *temp = other.top;
    StackNode *newNode = nullptr;

    while (temp != nullptr)
    {
        newNode = new StackNode(temp->data);
        newNode->next = this->top;
        this->top = newNode;
        this->count++;
        temp = temp->next;
    }
}

// Stack Constructor
template <typename T>
Stack<T>::Stack()
{
    this->top = nullptr;
    this->count = 0;
}

// Stack Destructor
template <typename T>
Stack<T>::~Stack()
{
    while (this->top != nullptr)
    {
        this->pop();
    }
}

// Push Method
template <typename T>
void Stack<T>::push(T data)
{
    StackNode *newNode = new StackNode(data);
    newNode->next = this->top;
    this->top = newNode;
    this->count++;
}

// Pop Method
template <typename T>
void Stack<T>::pop()
{
    if (this->isEmpty())
    {
        return;
    }

    StackNode *temp = this->top;
    this->top = this->top->next;
    delete temp;
    this->count--;
}

// Peek Method
template <typename T>
T Stack<T>::peek() const
{
    if (this->isEmpty())
    {
        return T();
    }

    return this->top->data;
}

// isEmpty Method
template <typename T>
bool Stack<T>::isEmpty()
{
    return this->top == nullptr;
}

// Size Method
template <typename T>
int Stack<T>::size() const
{
    return this->count;
}

// Overloaded [] Operator
template <typename T>
T &Stack<T>::operator[](int index) const
{
    if (index < 0 || index >= this->count)
    {
        throw out_of_range("Index out of range!");
    }

    StackNode *temp = this->top;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

#endif // !STACK_HPP