#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList(): head(nullptr) {}

    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeNode(int key){
        if(head == nullptr) return;
        if(head->data == key){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != key){
            temp = temp->next;
        }
        if(temp->next == nullptr) return;
        Node* NodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete NodeToDelete;
    }

    void traverse(){
        Node* temp = head;
        while(temp != nullptr){
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<< "nullptr"<< endl;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(): head(nullptr){};

    void insertAtBegining(int data){
        Node* newNode  = new Node(data);
        if(head != nullptr){
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int key){
        if(head == nullptr) return;
        if(head->data == key){
            Node* temp  =  head;
            head = temp->next;
            if(head != nullptr){
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp != nullptr && temp->data != key){
            temp = temp->next;
        }
        if(temp == nullptr) return;
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        if(temp->prev != nullptr){
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void traverseForward(){
        Node* temp = head;
        while(temp != nullptr){
            cout<< temp->data <<"->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }

    void traverseBackward(){
        Node* temp = head;
        if(temp == nullptr) return;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->prev;
        }
        cout<<"nullptr"<<endl;
    }

};

class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList(): head(nullptr) {}

    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
        }else{
            Node* temp  = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
        }else{
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void traverse(){
        if(head == nullptr) return;
        Node* temp = head;
        do{
            cout<<temp->data <<"->";
            temp = temp->next;
        } while(temp != head);
        cout<<"HEAD"<<endl;
    }
};



int main() {
    // singly linked list operations
    cout<< "Singly Linked List:" << endl;
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.traverse();
    list.insertAtBeginning(20);
    list.traverse();
    list.insertAtBeginning(30);
    list.traverse();
    list.removeNode(20);
    list.traverse();

    //Doubly Linked List
    cout<< "Doubly Linked List:" << endl;
    DoublyLinkedList dlist;
    dlist.insertAtBegining(10);
    dlist.insertAtBegining(60);
    dlist.insertAtEnd(40);
    dlist.insertAtBegining(70);
    dlist.traverseForward();
    dlist.traverseBackward();
    dlist.deleteNode(70);
    dlist.traverseForward();

    //Circular Singly Linked List
    cout<< "Circular Singly Linked List:" << endl;
    CircularLinkedList clist;
    clist.insertAtBeginning(10);
    clist.insertAtBeginning(20);
    clist.insertAtEnd(30);
    clist.traverse();
    clist.insertAtBeginning(60);
    clist.insertAtEnd(70);
    clist.insertAtBeginning(40);
    clist.traverse();

    return 0;
}