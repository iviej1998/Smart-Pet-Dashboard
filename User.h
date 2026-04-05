#pragma once
#include "PetProfile.h"
#include <iostream>
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
    string username;
    string password;
    string role;
    int LinkedPetID;
public:
    User(string username, string password, string role, int PetID) : username(username), password(password), role(role), LinkedPetID(PetID){}

    void setLinkedPetID(int ID) { ID = LinkedPetID; }

    int getLinkedPetID() { return LinkedPetID; }

    void LinkToPetProfile(PetProfile& p) {
        LinkedPetID = p.getID();
    }

};
