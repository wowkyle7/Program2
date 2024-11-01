#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Guest.h"
#include "Data.h"

using namespace std;
template<typename T>
class List{
private:
    struct Node // https://stackoverflow.com/questions/15283195/argument-list-for-class-template-is-missing
    {
        Data<T> nodeValue;
        Node* next;

        Node(const Data<T>& val) : nodeValue(val), next(NULL) {}
    };

    Node* Head;
    Node* Tail;
    int numNodes;  // !!!!!!REMOVE IF NOT WANTING TO USE AT END!!!!!!
    
public:
    //Constructor
    List() : Head(NULL), Tail(NULL), numNodes(0) {}

    ~List(){
        Node* current = Head;
        while (current){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "\nAll Nodes Removed" << endl;
    }
    // Mutators
    void appendNode(const Data<Guest>& guest);
    //void insertNode(Data<Guest>);
    void deleteNode(Data<Guest>);
    void pushNode(Data<Guest>);
    void popNode(Data<Guest>&);

    // Accessors
    void displayList();

    // Overloaded
    friend ostream& operator<<(ostream& stream, List& val) {
        Node* current = val.Head;
        while (current){
            stream << current->nodeValue.getValue().getName() << " -> ";
            current = current -> next;
        }
        
        stream << "Used << operator in LinkedList Class" << endl; // Change to be whatever we need it to do
        return stream;
    }
};
    template<typename T>
    void List<T>::appendNode(const Data<Guest>& guest) // Bottom of list
    {
        Node *newNode;
        newNode = new Node(guest);

        if (!Head)
        { // No head, default to both
            Head = newNode;
            Tail = newNode;
        }
        else
        { // Otherwise push towards end
            Tail->next = newNode;
            Tail = newNode;
        }
        numNodes++;
    };

/*
void List::insertNode(Data<Guest> guest)
{
    nodeValue *newNode;
    nodeValue *nodePointer;
    nodeValue *prevNode;

    // New node with txt parameter
    newNode = new nodeValue(guest);

    if (!Head)
    { // No head, make new node head
        Head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePointer = Head;
        prevNode = NULL;

        // if nodePointer != end & node value is less than parameter, skip
        while (nodePointer != NULL && nodePointer->nodeValue.getValue().getName() < guest.getValue().getName())
        {
            prevNode = nodePointer;
            nodePointer = nodePointer->next;
        };

        // Is new node the start?
        if (prevNode == NULL)
        {
            Head = newNode;
            newNode->next = nodePointer;
        }
        else
        {
            prevNode->next = newNode;
            newNode->next = nodePointer;
        };
    }
};*/
template<typename T>
void List<T>::deleteNode(Data<Guest> guest)
{
    Node *nodePointer;
    Node *prevNode;

    // Is List empty?
    if (!Head)
    {
        return;
    };

    // Is value to delete the head?
    if (Head->nodeValue.getValue().getName() == guest.getValue().getName())
    {
        nodePointer = Head->next;
        delete Head;
        Head = nodePointer;
    }
    else
    { // It's not..
        nodePointer = Head;

        // NodePointer != end and val of it isn't the val to delete
        while (nodePointer != NULL && nodePointer->nodeValue.getValue().getName() != guest.getValue().getName())
        {
            prevNode = nodePointer;
            nodePointer = nodePointer->next;
        };

        // does nodePointer even have a value
        if (nodePointer)
        {
            if (nodePointer == Tail)
            {
                Tail = prevNode;
            };

            prevNode->next = nodePointer->next;
            delete nodePointer;
        }
    }
};

template<typename T>
void List<T>::pushNode(Data<Guest> newGuest) { // Top of list
    Node *nodePtr;
    nodePtr = new Node(newGuest);
    nodePtr->nodeValue = newGuest;

    if (!Head) {
        nodePtr->next = NULL;
    } else {
        nodePtr->next = Head;
    }

    Head = nodePtr;
    numNodes++;
}

template<typename T>
void List<T>::popNode(Data<Guest>& newGuest) {
    Node *ptr;

    if (Head) {
        numNodes--;
        ptr = Head;

        if (Head->next != NULL) {
            Head = Head->next;
        } else {
            Head = NULL;
        };

        newGuest = ptr->nodeValue;
        delete ptr;
    };
}

// Accessors
template<typename T>
void List<T>::displayList()
{
    Node *nodePointer;
    nodePointer = Head;

    while (nodePointer)
    {
        Guest guest = nodePointer->nodeValue.getValue();
        // temp solution for output:
        cout << nodePointer << endl;

        // Goal is to use << for nodeValue
        nodePointer = nodePointer->next;
    };
};


#endif