#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
    public:
        struct ListNode {
            string strNode;
            ListNode *next;

            ListNode(string newStr) {
                strNode = newStr;
                next = NULL;
            };
        };

        ListNode *Head;
        ListNode *Tail;

        // Mutators
        void appendNode(string txt) {
            ListNode *newNode;
            newNode = new ListNode(txt);

            if (!Head) { // No head, default to both
                Head = newNode;
                Tail = newNode;
            } else { // Otherwise push towards end
                Tail->next = newNode;
                Tail = newNode;
            }
        };

        void insertNode(string txt) {
            ListNode *newNode;
            ListNode *nodePointer;
            ListNode *prevNode;

            // New node with txt parameter
            newNode = new ListNode(txt);

            if (!Head) { // No head, make new node head
                Head = newNode;
                newNode->next = NULL;
            } else { 
                nodePointer = Head;
                prevNode = NULL;

                // if nodePointer != end & node value is less than parameter, skip
                while (nodePointer != NULL && nodePointer->strNode < txt) {
                    prevNode = nodePointer;
                    nodePointer = nodePointer->next;
                };

                // Is new node the start?
                if (prevNode == NULL) {
                    Head = newNode;
                    newNode->next = nodePointer;
                } else {
                    prevNode->next = newNode;
                    newNode->next = nodePointer;
                };
            }
        };
        void deleteNode(string txt) {
            ListNode *nodePointer;
            ListNode *prevNode;

            // Is List empty?
            if (!Head) {
                return;
            };

            // Is value to delete the head?
            if (Head->strNode == txt) {
                nodePointer = Head->next;
                delete Head;
                Head = nodePointer;
            } else { // It's not..
                nodePointer = Head;

                // NodePointer != end and val of it isn't the val to delete
                while (nodePointer != NULL && nodePointer->strNode != txt) {
                    prevNode = nodePointer;
                    nodePointer = nodePointer->next;
                };

                // does nodePointer even have a value
                if (nodePointer) {
                    if (nodePointer == Tail) {
                        Tail = prevNode;
                    };

                    prevNode->next = nodePointer->next;
                    delete nodePointer;
                }
            }
        };

        // Accessors
        void displayList() {
            ListNode *nodePointer;
            nodePointer = Head;

            while (nodePointer) {
                cout << nodePointer->strNode << endl;
                nodePointer = nodePointer->next;
            };
        };

    // Constructor
    List() {
        Head = NULL;
        Tail = NULL;
    };

    // Destructor
    ~List() {
        ListNode* nodePointer;
        ListNode* nextNode;

        nodePointer = Head;

        while (nodePointer != NULL) {
            nextNode = nodePointer->next;
            delete nodePointer;
            nodePointer = nextNode;
        };

        cout << "\nAll Nodes Removed" << endl;
    };

};


#endif