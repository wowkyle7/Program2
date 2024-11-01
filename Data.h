#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class Data{
    public:
        T value;

    private:
        T getValue(){
            return value;
        }

        void setValue(T givenValue){
            value = givenValue;
        }
};

#endif