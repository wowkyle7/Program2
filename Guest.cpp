/*
    AUTHOR: Kyle Schultz
    FILE:   Guest Class Functions
*/

#include "Guest.h"

Guest::Guest(){
    name = nullptr;
    age = nullptr;
    times_attended = nullptr;
    floz_bb_oil_used = nullptr;
}

Guest::Guest(string n, int a, int t, float b){
    name = &n;
    age = &a;
    times_attended = &t;
    floz_bb_oil_used = &b;
}

Guest::~Guest(){
    delete [] name;
    delete [] age;
    delete [] times_attended;
    delete [] floz_bb_oil_used;
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