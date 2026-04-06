#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a standard system user responsible 
 * for managing pet profiles and interacting with associated devices.
 * This class extends the User class by functionality specific to pet ownership,
 * including pet management, device control, and monitoring pet-related activity.
 *******************************************************/

class PetOwner : public User {
private:
    int OwnerID;
    bool isAuthenticated = true;
    vector<PetProfile> PetProfiles;

public:
    PetOwner(int ownerID, bool isAuth, vector<PetProfile> PP, string username, string password, string role, int LinkedPetID);

    void createPetProfile(PetProfile& p);
    void updatePetProfile();
    void deletePetProfile();
};