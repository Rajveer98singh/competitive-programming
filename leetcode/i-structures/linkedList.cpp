// leetcode/data-struct/linkedList.cpp

#include "../headers/linkedList.h"

// SinglyLinkedList class methods
SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

void SinglyLinkedList::insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SinglyLinkedList::removeNode(int key) {
    if (head == nullptr) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == nullptr) return;
    Node* NodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete NodeToDelete;
}

void SinglyLinkedList::traverse() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// DoublyLinkedList class methods
DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

void DoublyLinkedList::insertAtBegining(int data) {
    Node* newNode = new Node(data);
    if (head != nullptr) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::deleteNode(int key) {
    if (head == nullptr) return;
    if (head->data == key) {
        Node* temp = head;
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void DoublyLinkedList::traverseForward() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void DoublyLinkedList::traverseBackward() {
    Node* temp = head;
    if (temp == nullptr) return;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}
