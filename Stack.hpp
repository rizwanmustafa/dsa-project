#pragma once
#ifndef STACK_HPP
#define Stack_HPP

template <typename T>
class Stack
{
    struct StackNode
    {
        T data;
        StackNode* next;
        StackNode(T data);
    };

    StackNode* top;
    int count;

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    void push(T data);
    void pop();
    T peek() const;
    bool isEmpty();
    int size();
};

#endif // !STACK_HPP