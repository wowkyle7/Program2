/*
    Author:     Ryan Marasigan
    Purpose:    Template Helper Class 
*/
#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class Data{
        T value;
        Data* next;
    public:
        Data(T val){
            value = val;
            next = nullptr;
        }

        Data(){
            value = T();
            next = nullptr;
        }

        ~Data(){
            delete next;
        }

        T getValue(){
            return value;
        }

        void setValue(T givenValue){
            value = givenValue;
        }

        Data* getNext(){
            return next;
        }

        void setNext(Data* n){
            next = n;
        }

        // Overloaded
        friend ostream& operator<<(ostream& stream, const Data& val) {
            stream << val.getValue();
            return stream;
        }
};

#endif