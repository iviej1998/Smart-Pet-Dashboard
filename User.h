#pragma once
#include "PetProfile.h"
#include "PetOwner.h"
#include <iostream>
#include <vector>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a system user who can access Smart Pet Dashboard.
    This class stores common user information and behaviors shared by all user types,
    such as authentication related data and account identity. 
  * Child Classes: PetOwner, SystemAdmin, PetSitter
 *******************************************************/

class User {
private:
    int userID;
    int LinkedPetID;
    string username;
    string password;
    string role;
    vector<PetOwner> PetOwners;
    vector<SystemAdmin> SystemAdmins;
public:
    User(string username, string password, string role, int PetID, vector<PetOwner> p, vector<SystemAdmin> s) : 
    username(username), password(password), role(role), LinkedPetID(PetID), PetOwners(p), SystemAdmins(s) {}

    void setLinkedPetID(int ID) { ID = LinkedPetID; }

    int getLinkedPetID() { return LinkedPetID; }

    void LinkToPetProfile(PetProfile& p) {
        LinkedPetID = p.getID();
    }

    void addOwner() {

    }
    

};
