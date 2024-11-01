#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Guest.h"
#include "Data.h"

using namespace std;

class List
{
public:
    template <typename T>
    struct ListNode // https://stackoverflow.com/questions/15283195/argument-list-for-class-template-is-missing
    {
        Data<T> nodeValue;
        Data<T>* nodeValue_Head;
        Data<T>* Tail;

        ListNode(T val) : nodeValue(val), nodeValue_Head(nullptr), Tail(nullptr) {};
    };

    int numNodes; // !!!!!!REMOVE IF NOT WANTING TO USE AT END!!!!!!
    


    // Constructor  
    List()
    {
        typedef Data<T> nodeValue_Head;
        typedef Data<T> nodeValue
        Tail = NULL;
        numNodes = 0;
    }

    // Mutators
    void appendNode(Data<Guest>);
    //void insertNode(Data<Guest>);
    void deleteNode(Data<Guest>);
    void pushNode(Data<Guest>);
    void popNode(Data<Guest>&);

    // Accessors
    void displayList();

    // Overloaded
    friend ostream& operator<<(ostream& stream, List& val) {
        stream << "Guest Name: " << val.Head->nodeValue.getValue().getName() << endl;
        
        stream << "Used << operator in LinkedList Class" << endl; // Change to be whatever we need it to do
    };

    // Destructor
    template <typename T>
    ~List()
    {
        typedef Data<T> *nodePointer;
        typedef Date<T> *nextNode;

        nodePointer = Head;

        while (nodePointer != NULL)
        {
            nextNode = nodePointer->next;
            delete nodePointer;
            nodePointer = nextNode;
        };

        cout << "\nAll Nodes Removed" << endl;
    };
};

void List::appendNode(Data<Guest> guest) // Bottom of list
{
    ListNode *newNode;
    newNode = new ListNode(guest);

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
};

/*void List::insertNode(Data<Guest> guest)
{
    ListNode *newNode;
    ListNode *nodePointer;
    ListNode *prevNode;

    // New node with txt parameter
    newNode = new ListNode(guest);

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

void List::deleteNode(Data<Guest> guest)
{
    ListNode *nodePointer;
    ListNode *prevNode;

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

void List::pushNode(Data<Guest> newGuest) { // Top of list
    ListNode *nodePtr;
    nodePtr = new ListNode(newGuest);
    nodePtr->nodeValue = newGuest;

    if (!Head) {
        nodePtr->next = NULL;
    } else {
        nodePtr->next = Head;
    }

    Head = nodePtr;
    numNodes++;
}

void List::popNode(Data<Guest>& newGuest) {
    ListNode *ptr;

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
void List::displayList()
{
    ListNode *nodePointer;
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