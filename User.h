#pragma once
#include <iostream>
#include <vector>
using namespace std;

class PetOwner;
class PetProfile;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a system user who can access Smart Pet Dashboard.
 * This class stores common user information and behaviors shared by all user types,
 * such as authentication related data and account identity.
 * Child Classes: PetOwner, SystemAdmin, PetSitter
 *******************************************************/

class User
{
private:
    int userID;
    int LinkedPetID;
    string username;
    string password;
    string role;

public:
    User(string username, string password, string role, int PetID);

    void set_username(string u);
    string get_username();

    void set_password(string p);
    string get_password();

    void setLinkedPetID(int ID);
    int getLinkedPetID();

    void LinkToPetProfile(PetProfile& p);

    void addPetOwner(PetOwner& p);
};