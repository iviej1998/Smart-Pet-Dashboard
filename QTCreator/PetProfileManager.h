//
// Created by Angel Madrigal on 4/10/26.
//
#pragma once
#include <vector>
#include <memory> //For unique_ptr
#include <algorithm>
#include <stdexcept>
#include "PetProfile.h"
#include "Database.h"

class PetProfileManager {
private:
    std::vector<std::unique_ptr<PetProfile>> petProfiles;
    std::shared_ptr<Database> mySQLdb;

    void addToDatabase(PetProfile &petProfile);
    void deleteFromDatabase(PetProfile &petProfile);
    void updateInDatabase(PetProfile &petProfile);
    void pullFromDatabase(int userId);
public:
    void deletePetProfile(PetProfile &petProfile); //deletes from vector and database
    //Return petID for UserProfileManagement to insert into UserPetAccess table
    int addPetProfile(const std::string& newName,
                      const std::string& newType, const std::string& newOtherType, double newFoodAmt,
                      int newTreatLimit, bool newHasLamp); // Adds to vector and database
    void updatePetProfile(PetProfile& petProfile, const std::string& newName,
                          const std::string& newType, const std::string& newOtherType, double newFoodAmt,
                          int newTreatLimit, bool newHasLamp);
    void pullPetProfile(int userId);
    void displayAllPetProfiles();
    PetProfile& returnPetProfile(int petId);
    PetProfileManager(const std::shared_ptr<Database>& myDb) : mySQLdb(myDb) {}
    ~PetProfileManager() {}
};