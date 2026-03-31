#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "Device.h"
#include "PetProfile.h"
#include "LogEntry.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a system user who can access Smart Pet Dashboard.
    This class stores common user information and behaviors shared by all user types,
    such as authentication related data and account identity. 
  * Child Classes: PetOwner, SystemAdmin, PetSitter
 *******************************************************/

class User : public SystemEntity {
protected:
    int userID;
    string username;
    string password;
    string role;
};
