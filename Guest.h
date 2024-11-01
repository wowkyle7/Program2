/*
    AUTHOR: Kyle Schultz
    FILE:   Guest Class Header
*/
#ifndef GUEST_H
#define GUEST_H

#include <iostream>

using namespace std;

class Guest{
    private:
        string* name;
        int* age;
        int* times_attended;
        float* floz_bb_oil_used;

    public:
        // Constructors
        Guest();
        Guest(string, int, int, float);

        // Deconstructor
        ~Guest();

        // Getters
        string getName();
        int getAge();
        int getTimesAttended();
        float getBbOilUsed();
};

Guest::Guest(){
    name = nullptr;
    age = nullptr;
    times_attended = nullptr;
    floz_bb_oil_used = nullptr;
}

Guest::Guest(string n, int a, int t, float b){
    name = new string(n);
    age = new int(a);
    times_attended = new int(t);
    floz_bb_oil_used = new float(b);
}

Guest::~Guest(){
    delete name;
    delete age;
    delete times_attended;
    delete floz_bb_oil_used;
}

string Guest::getName(){
    return *name;
}

int Guest::getAge(){
    return *age;
}

int Guest::getTimesAttended(){
    return *times_attended;
}

float Guest::getBbOilUsed(){
    return *floz_bb_oil_used;
}

#endif