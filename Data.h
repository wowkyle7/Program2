#ifndef OTHERCLASS_H
#define OTHERCLASS_H

#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class Data{
    public:
        T Value;

    private:
        getValue(){
            return Value;
        }

        void setValue(T givenValue){
            value =givenValue;
        }
};

#endif