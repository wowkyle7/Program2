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

    Data() : value(T()), next(nullptr) {}

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
};

#endif