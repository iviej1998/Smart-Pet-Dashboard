#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "Device.h"
#include "PetProfile.h"
#include "LogEntry.h"
using namespace std;

class User : public SystemEntity {
protected:
    int userID;
    string username;
    string password;
    string role;
};
