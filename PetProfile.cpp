#pragma once
#include <iostream>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents an individual pet managed by the system.
    This class stores pet-specific information such as pet
    name, feeding configuration, and associated care settings.
    It provides the structure needed to connect pets to devices,
    feeding rules, and owner managed settings.
  * Child Classes: Reptile, Fish, Cat, Dog
 *******************************************************/

class PetProfile {
private:
    int petID;
    string PetName;
    string PetType;
    int foodAmount;
    int treatLimit;
    string linkedDevices;
public:

    int getID() {return petID;}

    void setName(string name) { PetName = name; }

    void setType(string type) { PetType = type; }
};
