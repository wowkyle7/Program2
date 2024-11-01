#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class Data{
        T value;
        Data* nextData;

        Data(T val) : value(val), next(nullptr) {};
    public:
        T getValue(){
            return value;
        }

        void setValue(T givenValue){
            value = givenValue;
        }
};

#endif