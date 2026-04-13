#include "User.h"
#include "PetOwner.h"
#include "PetProfile.h"
#include "globals.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements User class functions
 *******************************************************/

User::User() {}

User::User(int userID, string username, string password, string role, int PetID)
    : userID(userID), username(username), password(password), role(role), LinkedPetID(PetID)
{
}

void User::set_userID(int id)
{
    userID = id;
}

int User::get_userID() {
    return userID;
}

void User::set_username(string u)
{
    username = u;
}

string User::get_username()
{
    return username;
}

void User::set_password(string p)
{
    password = p;
}

string User::get_password()
{
    return password;
}

void User::setLinkedPetID(int ID)
{
    LinkedPetID = ID;
}

int User::getLinkedPetID()
{
    return LinkedPetID;
}

void User::LinkToPetProfile(PetProfile& p)
{
    LinkedPetID = p.getID();
}

void User::set_PetID_count(int id)
{
     petID_count = id;
}

int User::get_PetID_count()
{
    return petID_count;
}

void User::increment_petID_count() {
    petID_count++;
}

void User::set_role(string r) {
    role = r;
}
string User::get_role() {
    return role;
}

void User::addPetOwner(PetOwner& p)
{
    PetOwners.push_back(p);
}
