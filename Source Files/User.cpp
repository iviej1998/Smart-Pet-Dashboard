#pragma once
#include "User.h"
#include "PetProfile.cpp"
#include "PetOwner.cpp"
//#include "AuthenticationManager.cpp"
#include <iostream>
#include <vector>
using namespace std;

User::User(string username, string password, string role, int PetID, vector<PetOwner> p, vector<SystemAdmin> s) :
    username(username), password(password), role(role), LinkedPetID(PetID), PetOwners(p), SystemAdmins(s) {}
User(string username, string password, string role, int PetID) :
    username(username), password(password), role(role), LinkedPetID(PetID) {}

void User::setLinkedPetID(int ID) { ID = LinkedPetID; }
void User::set_username(string u) { username = u; }
string User::get_username() { return username; }

void User::set_password (string p) { password = p; }
string User::get_password () { return password; }

void User::setLinkedPetID(int ID) { ID = LinkedPetID; }
int User::getLinkedPetID() { return LinkedPetID; }

void User::LinkToPetProfile(PetProfile& p) {
    LinkedPetID = p.getID();
}

void addPetOwner(PetOwner& p, SystemAdmin& s) {
    if (s.validate_user() == true ) {
        PetOwners.push_back(p);
    }
}