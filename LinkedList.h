#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Guest.h"
#include "Data.h"

using namespace std;
template<typename T>
class List{
private:
    Data<T>* Head;
    Data<T>* Tail;

    int numNodes;  // !!!!!!REMOVE IF NOT WANTING TO USE AT END!!!!!!
    
public:
    //Constructor
    List(){
        Head = nullptr;
        Tail = nullptr;
        numNodes = 0;}

    ~List(){
        Data<T>* current = Head;
        while (current){
            Data<T>* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
        cout << "\nAll Nodes Removed" << endl;
    }
    // Mutators
    void appendNode(T);
    // void deleteNode(T);
    void pushNode(T);
    void popNode(T);

    // Accessors
    void displayList();

    // Overloaded
    friend ostream& operator<<(ostream& stream, List& val) {
        Data<T>* current = val.Head;
        while (current){
            stream << current->nodeValue.getValue().getName() << " -> ";
            current = current -> next;
        }
        
        stream << "Used << operator in LinkedList Class" << endl; // Change to be whatever we need it to do
        return stream;
    }
};

template<typename T>
void List<T>::appendNode(T guest) // Bottom of list
{
    Data<T>* newNode;
    newNode = new Data<T>(guest);

    newNode->setNext(Head);
    Head = newNode;

    numNodes++;
};

// template<typename T>
// void List<T>::deleteNode(T guest)
// {
//     Data<T> *nodePointer;
//     Data<T> *prevNode;

//     // Is List empty?
//     if (!Head)
//     {
//         return;
//     }

//     // Is value to delete the head?
//     if (Head->nodeValue.getValue().getName() == guest.getValue().getName())
//     {
//         nodePointer = Head->next;
//         delete Head;
//         Head = nodePointer;
//     }
//     else
//     { // It's not..
//         nodePointer = Head;

//         // NodePointer != end and val of it isn't the val to delete
//         while (nodePointer != NULL && nodePointer->nodeValue.getValue().getName() != guest.getValue().getName())
//         {
//             prevNode = nodePointer;
//             nodePointer = nodePointer->next;
//         }

//         // does nodePointer even have a value
//         if (nodePointer)
//         {
//             if (nodePointer == Tail)
//             {
//                 Tail = prevNode;
//             };

//             prevNode->next = nodePointer->next;
//             delete nodePointer;
//         }
//     }
// };

template<typename T>
void List<T>::pushNode(T newGuest) { // Top of list
    Data<T> *nodePtr;
    nodePtr = new Data<T>(newGuest);
    nodePtr->setValue(newGuest);

    if (!Head) {
        nodePtr->setNext(NULL);
    } else {
        nodePtr->setNext(Head);
    }

    Head = nodePtr;
    numNodes++;
}

template<typename T>
void List<T>::popNode(T newGuest) {
    Data<T> *ptr;

    if (Head) {
        numNodes--;
        ptr = Head;

        if (Head->next != NULL) {
            Head = Head->next;
        } else {
            Head = NULL;
        }

        newGuest = ptr->nodeValue;
        delete ptr;
    };
}

// Accessors
template<typename T>
void List<T>::displayList()
{
    Data<T> *nodePointer;
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