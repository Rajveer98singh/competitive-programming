// leetcode/library-use/example.cpp

#include "../headers/linkedList.h"

int main() {
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);

    list.traverse(); // Output: 20->10->30->nullptr

    list.removeNode(10);

    list.traverse(); // Output: 20->30->nullptr

    return 0;
}
