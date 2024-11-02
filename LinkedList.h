#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
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
    void popNode();

    // Accessors
    void displayList();
};

template<typename T>
void List<T>::appendNode(T guest) // Bottom of list
{
    Data<T>* newNode = new Data<T>(guest);
    newNode->setNext(nullptr);

    if (Head == nullptr) { // List is empty, set head as new value
        Head = newNode;
    } else {
        Data<T>* currentNode = Head;
        while (currentNode->getNext() != nullptr) { // Loop until next node is null
            currentNode = currentNode->getNext();
        };

        currentNode->setNext(newNode);
    }

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
void List<T>::popNode() {
    Data<T> *ptr;

    if (Head) {
        numNodes--;
        ptr = Head;

        if (Head->getNext() != NULL) {
            //cout << Head->getValue().getName() << endl;
            Head = Head->getNext();
        } else {
            Head = nullptr;
        }

        delete ptr;
    };
}

// Accessors
template<typename T>
void List<T>::displayList()
{
    Data<T> *nodePointer;
    nodePointer = Head;
    int count = 1;

    cout << endl << endl;

    if (nodePointer == nullptr) {
        cout << "There are no guests to display!" << endl << endl;
    } else {
        while (nodePointer != nullptr) {

            Guest guest = nodePointer->getValue();
            cout << "Guest " << count << endl;
            cout << left << setw(26) << "    Name: " << guest.getName() << endl;
            cout << left << setw(26) << "    Age: " << guest.getAge() << endl;
            cout << left << setw(26) << "    Attendance: " << guest.getTimesAttended() << endl;
            cout << left << setw(10) << "    Fl. Oz Baby Oil Used: " << guest.getBbOilUsed() << endl;
            
            cout << "-------------------------------------" << endl << endl;
            count++;

            nodePointer = nodePointer->getNext();
        };
    }
};


#endif