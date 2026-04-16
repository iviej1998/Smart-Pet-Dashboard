#pragma once
#include <iostream>
#include <string>

class PetProfile {
private:
    int petID = 0;
    std::string petName;
    std::string petType;
    std::string otherPetType;
    double foodAmount;
    int treatLimit;
    bool hasLamp;

    void setID(int id); //Set from the database primary key
public:
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setFoodAmount(double amount);
    void setTreatLimit(int amount);
    void setLamp(bool lamp);
    void setOtherType(const std::string& other);

    int getID() const;
    std::string getName() const;
    std::string getType() const;
    double getFoodAmount() const;
    int getTreatLimit() const;
    bool getLamp() const;
    std::string getOtherType() const;

    //Modifier functions
    void editProfile(const std::string& pName, const std::string& pType, const std::string& oType, double fAmt, int tAmt, /*bool hasF,*/ bool hasL);
    //void deleteProfile(); Remove since it is already implemented
    void displayProfile();

    PetProfile(const std::string& pName, const std::string& pType, const std::string& oType, int fAmt, int tLimit, bool hasLamp)
        : petName(pName), petType(pType), otherPetType(oType), foodAmount(fAmt), treatLimit(tLimit), hasLamp(hasLamp) {}
    PetProfile() {}
    ~PetProfile() {}

    friend std::ostream& operator<<(std::ostream& os, const PetProfile& petProfile);
    friend class PetProfileManager; //Allows the use of setID()
};