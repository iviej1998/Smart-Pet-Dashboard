#include "PetProfile.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements PetProfile class functions
 *******************************************************/

// Getter
int PetProfile::getID() {
    return petID;
}

// Setters
void PetProfile::setName(string name) {
    PetName = name;
}

void PetProfile::setType(string type) {
    PetType = type;
}