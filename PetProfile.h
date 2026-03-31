#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "Device.h"
#include "LogEntry.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents an individual pe managed by the system.
    This class stores pet-specific information such as pet
    name, feeding configuration, and associated care settings.
    It provides the structure needed to connect pets to devices,
    feeding rules, and owner managed settings.
  * Child Classes: Reptile, Fish, Cat, Dog
 *******************************************************/

class PetProfile : public SystemEntity {
protected:
    int petID;
    string PetName;
    string PetType;
    int foodAmount;
    int treatLimit;
    string linkedDevices;
};
