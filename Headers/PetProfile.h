#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class PetProfile {
private:
    int petID;
    string petName;
    string petType;
    int foodAmount;
    int treatLimit;
    int userID;
    bool hasFeeder;
    bool hasLamp;

    void setID(int id); //Set from the databse primary key
    int getID();
public:
    void setName(const string& name);
    void setType(const string& type);
    void setFoodAmount(int amount);
    void setTreatLimit(int amount);
    void setUserID(int id);
    void setFeeder(bool feeder);
    void setLamp(bool lamp);

    int getID() const;
    string getName() const;
    string getType() const;
    int getFoodAmount() const;
    int getTreatLimit() const;
    int getUserID() const;
    bool getFeeder() const;
    bool getLamp() const;

    void editProfile(const string& pName, const string& pType, int fAmt, int tAmt, bool hasF, bool hasL);
    void deleteProfile();
    void displayProfile();

    PetProfile(int pID, const string& pName, const string& pType, int fAmt, int tLimit, int usID, bool hasF, bool hasLamp)
                : petID(pID), petName(pName), petType(pType), foodAmount(fAmt), treatLimit(tLimit), userID(usID), hasFeeder(hasF), hasLamp(hasLamp) {}
    PetProfile() {}
    ~PetProfile() {}

    ostream& operator<<(ostream& os, const PetProfile& petProfile);
};