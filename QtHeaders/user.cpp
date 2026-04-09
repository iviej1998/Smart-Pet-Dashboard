#include "User.h"
#include "globals.h"        // Needed for PetOwners global vector
#include <iostream>

// Constructor implementation
User::User(string username, string password, string role, int PetID)
    : username(username)
    , password(password)
    , role(role)
    , LinkedPetID(PetID)
{
}

// Username setters/getters
void User::set_username(string u) {
    username = u;
}

string User::get_username() {
    return username;
}

// Password setters/getters
void User::set_password(string p) {
    password = p;
}

string User::get_password() {
    return password;
}

// Linked Pet ID setters/getters
void User::setLinkedPetID(int ID) {
    LinkedPetID = ID;      // FIXED: your original code reversed assignment
}

int User::getLinkedPetID() {
    return LinkedPetID;
}

// Link user to a PetProfile
void User::LinkToPetProfile(PetProfile &p) {
    LinkedPetID = p.getID();
}

// Add a PetOwner to the global list
void User::addPetOwner(PetOwner &p, AuthenticationManager &a) {
    PetOwners.push_back(p);
}