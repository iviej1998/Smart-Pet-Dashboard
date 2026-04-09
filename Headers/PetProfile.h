#pragma once
#include <iostream>
using namespace std;

class PetProfile {
private:
    int petID;
    string petName;
    string petType;
    int foodAmount;
    int treatLimit;
    string linkedDevices;

public:
    int getID();

    void setName(string name);
    void setType(string type);
};