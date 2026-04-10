//
// Created by Angel Madrigal on 4/6/26.
//
#include "PetProfile.h"
using std::string;
using std::cout;
using std::endl;
using std::ostream;


//Setters
void PetProfile::setID(int id) { petID = id; } //TODO: Change when database is implemented/ready

void PetProfile::setName(const string& name) { petName = name; }

void PetProfile::setType(const string& type) { petType = type; }

void PetProfile::setFoodAmount(int amount) { foodAmount = amount; }

void PetProfile::setTreatLimit(int amount) { treatLimit = amount; }

void PetProfile::setUserID(int id) { userID = id; }

void PetProfile::setFeeder(bool feeder) { hasFeeder = feeder; }

void PetProfile::setLamp(bool lamp) { hasLamp = lamp; }

//Getters
int PetProfile::getID() const { return petID; }

string PetProfile::getName() const { return petName; }

string PetProfile::getType() const { return petType; }

int PetProfile::getFoodAmount() const { return foodAmount; }

int PetProfile::getTreatLimit() const { return treatLimit; }

int PetProfile::getUserID() const { return userID; }

bool PetProfile::getFeeder() const { return hasFeeder; }

bool PetProfile::getLamp() const { return hasLamp; }

//User commands
void PetProfile::editProfile(const string& pName, const string& pType, int fAmt, int tAmt, bool hasF, bool hasL) {
    petName = pName;
    petType = pType;
    foodAmount = fAmt;
    treatLimit = tAmt;
    hasFeeder = hasF;
    hasLamp = hasL;

    cout << "Pet Profile for " << petName << "successfully changed!" << endl;
}

void PetProfile::deleteProfile() {
    //TODO: Add database query to delete record of profile

    cout << petName << " permanently deleted!" << endl;
}

void PetProfile::displayProfile() {
    cout << "Pet Name: " << petName << endl;
    cout << "Pet Type: " << petType << endl;
    cout << "Food Amount for " << petName << ": " << foodAmount << endl;
    cout << "Treat Limit for " << petName << ": " << treatLimit << endl;
    cout << "Feeder Status: " << hasFeeder << endl;
    cout << "Lamp Status: " << hasLamp << endl;
}

ostream& operator<<(ostream& os, const PetProfile& petProfile) {
    os << "Pet Name: " << petProfile.getName() << endl;
    os << "Pet Type: " << petProfile.getType() << endl;
    os << "Food Amount for " << petProfile.getName() << ": " << petProfile.getFoodAmount() << endl;
    os << "Treat Limit for " << petProfile.getName() << ": " << petProfile.getTreatLimit() << endl;
    os << "Feeder Status for " << petProfile.getName() << ": " << petProfile.getFeeder() << endl;
    os << "Lamp status for " << petProfile.getName() << ": " << petProfile.getLamp() << endl << endl;

    return os;
}