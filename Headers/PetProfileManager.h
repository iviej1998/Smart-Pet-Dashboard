//
// Created by Angel Madrigal on 4/10/26.
//
#pragma once
#include <vector>
#include <memory> //For unique_ptr
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
    void deletePetProfile(PetProfile &petProfile); //deletes from vector
    void addPetProfile(PetProfile &petProfile); //adds to vector
    void updatePetProfile(PetProfile &petProfile);
    void pullPetProfile(int userId);
    PetProfile& returnPetProfile(int petId);
    PetProfileManager(std::shared_ptr<Database> mydb);
};
