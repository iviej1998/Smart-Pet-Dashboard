#include "PetOwner.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements the PetOwner class functions.
 *******************************************************/

// Constructor
PetOwner::PetOwner(int petID,
                   int ownerID,
                   bool isAuth,
                   vector<PetProfile> PP,
                   string username,
                   string password,
                   string role,
                   int LinkedPetID)
    : User(petID, username, password, role, LinkedPetID)
    , OwnerID(ownerID)
    , isAuthenticated(isAuth)
    , PetProfiles(PP)
{}
// Create a new pet profile
void PetOwner::createPetProfile(PetProfile &p)
{
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

// Update an existing pet profile
void PetOwner::updatePetProfile()
{
    // TODO: implement update logic
}

// Delete an existing pet profile
void PetOwner::deletePetProfile()
{
    // TODO: implement delete logic
}