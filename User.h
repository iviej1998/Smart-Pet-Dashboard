#pragma once
#include "PetProfile.h"
#include "PetOwner.h"
#include "AuthenticationManager.h"
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
public:
    User(string username, string password, string role, int PetID) : 
    username(username), password(password), role(role), LinkedPetID(PetID) {}

    void set_username(string u) { username = u; }
    string get_username() { return username; }

    void set_password (string p) { password = p; }
    string get_password () { return password; }

    void setLinkedPetID(int ID) { ID = LinkedPetID; }
    int getLinkedPetID() { return LinkedPetID; }

    void LinkToPetProfile(PetProfile& p) {
        LinkedPetID = p.getID();
    }

    void addPetOwner(PetOwner& p, AuthenticationManager& a) {
            PetOwners.push_back(p);
    }

};
