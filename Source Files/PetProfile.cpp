//
// Created by Angel Madrigal on 4/6/26.
//
#include "PetProfile.h"

//Setters
void PetProfile::setID(int id) { petID = id; }

void PetProfile::setName(const string& name) { petName = name; }

void PetProfile::setType(const string& type) { petType = type; }

void PetProfile::setFoodAmount(double amount) { foodAmount = amount; }

void PetProfile::setTreatLimit(int amount) { treatLimit = amount; }

//void PetProfile::setUserID(int id) { userID = id; }

void PetProfile::setLamp(bool lamp) { hasLamp = lamp; }

void PetProfile::setOtherType(const std::string &other) { otherPetType = other; }


//Getters
int PetProfile::getID() const { return petID; }

string PetProfile::getName() const { return petName; }

string PetProfile::getType() const { return petType; }

double PetProfile::getFoodAmount() const { return foodAmount; }

int PetProfile::getTreatLimit() const { return treatLimit; }

//int PetProfile::getUserID() const { return userID; }

bool PetProfile::getLamp() const { return hasLamp; }

std::string PetProfile::getOtherType() const { return otherPetType; }

//User commands
void PetProfile::editProfile(const string& pName, const string& pType, const std::string& oType, int fAmt, int tAmt, bool hasL) {
    petName = pName;
    petType = pType;
    foodAmount = fAmt;
    treatLimit = tAmt;
    hasLamp = hasL;
    otherPetType = oType;

    cout << "Pet Profile for " << petName << "succesfully changed!" << endl;
}

void PetProfile::deleteProfile() {
    //TODO: Add database query to delete record of profile

    cout << petName << " permanently deleted!" << endl;
}

void PetProfile::displayProfile() {
    cout << "Pet Name: " << petName << endl;
    cout << "Pet Type: " << petType << endl;
    cout << "Other Pet Type: " << otherPetType << endl;
    cout << "Food Amount for " << petName << ": " << foodAmount << endl;
    cout << "Treat Limit for " << petName << ": " << treatLimit << endl;
    cout << "Lamp Status: " << hasLamp << endl;
}

ostream& operator<<(ostream& os, const PetProfile& petProfile) {
    os << "Pet Name: " << petProfile.getName() << endl;
    os << "Pet Type: " << petProfile.getType() << endl;
    os << "Other Pet Type: " << petProfile.getOtherType() << endl;
    os << "Food Amount for " << petProfile.getName() << ": " << petProfile.getFoodAmount() << endl;
    os << "Treat Limit for " << petProfile.getName() << ": " << petProfile.getTreatLimit() << endl;
    os << "Lamp status for " << petProfile.getName() << ": " << petProfile.getLamp() << endl << endl;

    return os;
}