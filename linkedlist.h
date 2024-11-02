#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
#include "Guest.h"
#include "Data.h"

using namespace std;

/*
    Author:     Jackson Young
    Purpose:    Define List Class
*/
template<typename T>
class List{
private:
    Data<T>* Head;
    Data<T>* Tail;

    int numNodes;
    
public:
    //Constructor
    List(){
        Head = nullptr;
        Tail = nullptr;
        numNodes = 0;}

    //Destructor
    ~List(){
        Data<T>* current = Head;
        while (current){
            Data<T>* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
        cout << "\nAll Nodes Removed" << endl;
    }

    // Functions
    void appendNode(T);
    void pushNode(T);
    void popNode();
    void popBack();
    bool isEmpty();
    bool isOneNode();
    void selectionsort(bool);
    T getHeadNode();
    T getTailNode();
    void displayList();
};

/*
    Author:     Jackson Young
    Purpose:    Add a node to the back of the list
*/
template<typename T>
void List<T>::appendNode(T guest) // Bottom of list
{
    Data<T>* newNode = new Data<T>(guest);
    newNode->setNext(nullptr);

    if (isEmpty()) { // List is empty, set head as new value
        Head = newNode;
        Tail = newNode;
    } else {
        Data<T>* currentNode = Head;
        while (currentNode->getNext() != nullptr) { // Loop until next node is null
            currentNode = currentNode->getNext();
        }
        Tail = currentNode;
        currentNode->setNext(newNode);
    }

    numNodes++;
};

/*
    Author:     Jackson Young
    Purpose:    Add node to the front of the list
*/
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

    Data<T>* currentNode = Head;
    while (currentNode->getNext() != nullptr) { // Loop until next node is null
        currentNode = currentNode->getNext();
    }
    Tail = currentNode;

    numNodes++;
}

/*
    Author:     Jackson Young
    Purpose:    Remove node from back of list
*/
template<typename T>
void List<T>::popNode() {
    Data<T> *ptr;

    if (!isEmpty()) {
        numNodes--;
        ptr = Head;

        if (Head->getNext() != nullptr) {
            Head = Head->getNext();
            Data<T>* currentNode = Head;
            while (currentNode->getNext() != nullptr) { // Loop until next node is null
                currentNode = currentNode->getNext();
            }
            Tail = currentNode;
        } else {
            Head = nullptr;
        }

        delete ptr;
    }
}

/*
    Author:     Jackson Young
    Purpose:    Displays all elements in the list
*/
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
            cout << left << setw(26) << "    Times Attended: " << guest.getTimesAttended() << endl;
            cout << left << setw(10) << "    Fl. Oz Baby Oil Used: " << guest.getBbOilUsed() << endl;
            
            cout << "-------------------------------------" << endl << endl;
            count++;

            nodePointer = nodePointer->getNext();
        };
    }
};

/*
    Author:     Ryan Marasigan
    Purpose:    Deleting a Node from the Back
*/
template<typename T>
void List<T>::popBack(){
    if(isEmpty()){
        cout << "There is nothing to remove, the list is empty." << endl;
        return;
    }

    if (isOneNode()){
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else{
        Data<T>* current = Head;
        while (current->getNext() != Tail){
            current = current->getNext();
        }
        delete Tail;
        Tail = current;
        Tail->setNext(NULL);
    }
        numNodes--;
}

/*
    Author:     Kyle Schultz
    Function:   Returns value stored at head node
*/
template<typename T>
T List<T>::getHeadNode(){
    T val;
    Data<T> *nodePointer;
    nodePointer = Head;
    if(!isEmpty())
        val = nodePointer->getValue();
    else
        val = Guest();
    
    return val;
}


/*
    Author:     Kyle Schultz
    Function:   Returns value stored at tail node
*/
template<typename T>
T List<T>::getTailNode(){
    T val;
    Data<T> *nodePointer;
    nodePointer = Tail;
    if(!isEmpty())
        val = nodePointer->getValue();
    else
        val = Guest();
    
    return val;
}

/*
    Author:     Kyle Schultz
    Function:   Returns true if list if empty
*/
template<typename T>
bool List<T>::isEmpty(){
    if(Head == nullptr)
        return true;
    else
        return false;
}

/*
    Author:     Kyle Schultz
    Function:   Returns true if there is only 1 node in list
*/
template<typename T>
bool List<T>::isOneNode(){
    if(isEmpty())
        return false;
    else if(Head == Tail)
        return true;
    else
        return false;
}

/*
    Author:     Ryan Marasigan
    Function:   Sort list in either ascending or descending
*/
template<typename T>
void List<T>::selectionsort(bool ascending) {
    if (isEmpty()) {
        cout << "The list is empty, nothing to sort." << endl;
        return;
    }

    Data<T>* current = Head;

    while (current != nullptr) {
        Data<T>* minNode = current;
        Data<T>* nextNode = current->getNext();
        
        while (nextNode != nullptr) {
            bool condition;

            if(ascending){
                if(nextNode->getValue().getName() < minNode->getValue().getName())
                    condition = true;
                else
                    condition = false;
            }
            else{
                if(nextNode->getValue().getName() > minNode->getValue().getName())
                    condition = true;
                else
                    condition = false;
            }

            if(condition)
                minNode = nextNode;

        nextNode = nextNode->getNext();
}

        if(minNode != current){
            T temp = current->getValue();
            current->setValue(minNode->getValue());
            minNode->setValue(temp);
        }

        current = current->getNext();
    }
}

#endif