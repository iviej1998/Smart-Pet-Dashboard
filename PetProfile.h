#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "Device.h"
#include "LogEntry.h"
using namespace std;

class PetProfile : public SystemEntity {
protected:
    int petID;
    string PetName;
    string PetType;
    int foodAmount;
    int treatLimit;
    string linkedDevices;
};
