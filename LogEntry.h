#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "Device.h"
#include "PetProfile.h"
using namespace std;

class LogEntry : public SystemEntity {
protected:
    int timestamp;
    string message;
    int userID;
};
