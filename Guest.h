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

#endif