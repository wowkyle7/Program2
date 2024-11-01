#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class Data{
        T value;
        Data* nextData;

public:
    Data(T val) : value(val), nextData(nullptr) {}

    Data() : value(T()), nextData(nullptr) {}

    T getValue(){
        return value;
    }

    void setValue(T givenValue){
        value = givenValue;
    }

    Data* getNext(){
        return nextData;
    }

    void setNext(Data* next){
        nextData = next;
    }
};

#endif