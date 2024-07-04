// leetcode/headers/linkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList();

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void removeNode(int key);
    void traverse();
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList();

    void insertAtBegining(int data);
    void insertAtEnd(int data);
    void deleteNode(int key);
    void traverseForward();
    void traverseBackward();
};

#endif
