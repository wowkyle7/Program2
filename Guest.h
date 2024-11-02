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
        string name;
        int age;
        int times_attended;
        float floz_bb_oil_used;

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
    name = "";
    age = 0;
    times_attended = 0;
    floz_bb_oil_used = 0.0;
}

Guest::Guest(string n, int a, int t, float b){
    name = n;
    age = a;
    times_attended = t;
    floz_bb_oil_used = b;
}

Guest::~Guest(){}

string Guest::getName(){
    return name;
}

int Guest::getAge(){
    return age;
}

int Guest::getTimesAttended(){
    return times_attended;
}

float Guest::getBbOilUsed(){
    return floz_bb_oil_used;
}

#endif