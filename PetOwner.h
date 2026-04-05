#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a standard system user responsible 
    for managing pet profiles and interacting with associated devices.
    This class extends the User class by functionality specific to pet ownership,
    including pet management, device control, and monitoring pet-related activity.
 *******************************************************/

class PetOwner : public User {
private:
    int OwnerID;
    bool isAuthenticated = true;
    vector<PetProfile> PetProfiles;

public:
/* create, update, delete pet profiles
    associate devices with pet profiles
    control connected devices
    monitor feeding history and device activity
    intitiate manual feeding and configuration actions */


    void createPetProfile(PetProfile& p) {
        string name;
        cout << "Pet Name: ";
        cin >> name;
        p.setName(name);
        string type;
        cout << "Pet Type: ";
        cin >> type;
        p.setType(type);
        
        PetProfiles.push_back(p);

    }

    void updatePetProfile() {}
    void deletePetProfile() {}

    
    
};
