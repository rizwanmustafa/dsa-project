#pragma once
#ifndef LINKEDLIST_HPP

template <typename T>
class LinkedList
{
    struct LinkedListNode
    {
        T data;
        LinkedListNode* next;
        LinkedListNode(T data);
    };

    LinkedListNode* head;
    LinkedListNode* tail;
    int count;
public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();
    void insertFront(T data);
    void insertLast(T data);
    void remove(T data);
    void removeFront();
    void removeLast();
    int size() const;
    void display();
    bool isEmpty();
};

#endif // !LINKEDLIST_HPP