#pragma once
#include <iostream>
#include <string>

class PetProfile {
private:
    int petID;
    std::string petName;
    std::string petType;
    int foodAmount;
    int treatLimit;
    int userID;
    bool hasFeeder;
    bool hasLamp;

    void setID(int id); //Set from the databse primary key
    int getID();
public:
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setFoodAmount(int amount);
    void setTreatLimit(int amount);
    void setUserID(int id);
    void setFeeder(bool feeder);
    void setLamp(bool lamp);

    int getID() const;
    std::string getName() const;
    std::string getType() const;
    int getFoodAmount() const;
    int getTreatLimit() const;
    int getUserID() const;
    bool getFeeder() const;
    bool getLamp() const;

    void editProfile(const std::string& pName, const std::string& pType, int fAmt, int tAmt, bool hasF, bool hasL);
    void deleteProfile();
    void displayProfile();

    PetProfile(int pID, const std::string& pName, const std::string& pType, int fAmt, int tLimit, int usID, bool hasF, bool hasLamp)
                : petID(pID), petName(pName), petType(pType), foodAmount(fAmt), treatLimit(tLimit), userID(usID), hasFeeder(hasF), hasLamp(hasLamp) {}
    PetProfile() {}
    ~PetProfile() {}

    friend std::ostream& operator<<(std::ostream& os, const PetProfile& petProfile);
};