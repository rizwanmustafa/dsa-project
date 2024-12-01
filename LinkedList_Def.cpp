// #include "LinkedList.hpp"
// #include <iostream>
// using namespace std;

// /*
//     This Cpp file contains the implementation of the LinkedList class.
// */

// // LinkedListNode constructor
// template <typename T>
// LinkedList<T>::LinkedListNode::LinkedListNode(T data)
// {
//     this->data = data;
//     this->next = nullptr;
// }

// // Constructor
// template <typename T>
// LinkedList<T>::LinkedList()
// {
//     this->head = nullptr;
//     this->tail = nullptr;
//     this->count = 0;
// }

// // Copy Constructor
// template <typename T>
// LinkedList<T>::LinkedList(const LinkedList &other)
// {
//     this->head = this->tail = nullptr;
//     this->count = 0;

//     LinkedListNode *temp = other.head;
//     LinkedListNode *newNode = nullptr;

//     while(temp != nullptr)
//     {
//         newNode = new LinkedListNode(temp->data);
//         if(this->head == nullptr)
//         {
//             this->head = this->tail = newNode;
//         }
//         else
//         {
//             this->tail->next = newNode;
//             this->tail = newNode;
//         }
//         this->count++;
//         temp = temp->next;
//     }
// }

// // Destructor
// template <typename T>
// LinkedList<T>::~LinkedList()
// {
//     while (this->head != nullptr)
//     {
//         LinkedListNode *temp = this->head;
//         this->head = this->head->next;
//         this->count--;
//         delete temp;
//     }
// }

// // Check if the list is empty
// template <typename T>
// bool LinkedList<T>::isEmpty()
// {
//     return this->head == nullptr;
// }

// // Insert a new node with data at the start of the list
// template <typename T>
// void LinkedList<T>::insertFront(T data)
// {
//     if (this->isEmpty())
//     {
//         this->head = this->tail = new LinkedListNode(data);
//     }
//     else
//     {
//         LinkedListNode *temp = new LinkedListNode(data);
//         temp->next = this->head;
//         this->head = temp;
//     }
//     this->count++;
// }

// // Insert a new node with data at the end of the list
// template <typename T>
// void LinkedList<T>::insertLast(T data)
// {
//     if (this->isEmpty())
//     {
//         this->head = this->tail = new LinkedListNode(data);
//     }
//     else
//     {
//         this->tail->next = new LinkedListNode(data);
//         this->tail = this->tail->next;
//     }
//     this->count++;
// }

// // Remove the first node with data from the list
// template <typename T>
// void LinkedList<T>::removeFront()
// {
//     if (this->isEmpty())
//     {
//         return;
//     }
//     LinkedListNode *temp = this->head;
//     this->head = this->head->next;
//     delete temp;
//     this->count--;
// }

// // Remove the last node with data from the list
// template <typename T>
// void LinkedList<T>::removeLast()
// {
//     if (this->isEmpty())
//     {
//         return;
//     }

//     if (this->head == this->tail)
//     {
//         this->removeFront();
//         return;
//     }

//     LinkedListNode *temp = this->head;
//     while (temp->next != this->tail)
//     {
//         temp = temp->next;
//     }
//     delete this->tail;
//     this->tail = temp;
//     this->tail->next = nullptr;
//     this->count--;
// }

// // Remove the specified node with data from the list
// template <typename T>
// void LinkedList<T>::remove(T data)
// {
//     if (this->isEmpty())
//     {
//         return;
//     }

//     if (this->head->data == data)
//     {
//         this->removeFront();
//         return;
//     }

//     LinkedListNode *temp = this->head;
//     while (temp->next != nullptr && temp->next->data != data)
//     {
//         temp = temp->next;
//     }

//     if (temp->next == nullptr)
//     {
//         return;
//     }

//     LinkedListNode *toDelete = temp->next;
//     temp->next = temp->next->next;
//     delete toDelete;
//     this->count--;
// }

// // Display the list
// template <typename T>
// void LinkedList<T>::display()
// {
//     LinkedListNode *temp = this->head;
//     while (temp != nullptr)
//     {
//         cout << " " << temp->data;
//         temp = temp->next;
//     }
//     cout << endl;
// }

// // Size Method
// template <typename T>
// int LinkedList<T>::size() const
// {
//     return this->count;
// }

// // Overloaded [] operator
// template <typename T>
// T &LinkedList<T>::operator[](int index) const
// {
//     if (index < 0 || index >= this->count)
//     {
//         throw "Index out of bounds";
//     }

//     LinkedListNode *temp = this->head;
//     for (int i = 0; i < index; i++)
//     {
//         temp = temp->next;
//     }

//     return temp->data;
// }
