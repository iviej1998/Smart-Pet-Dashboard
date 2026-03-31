#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "PetProfile.h"
#include "LogEntry.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a generic smart device connected to
    the Smart Pet Dashboard. This class defines the shared 
    behavior for all supported devices, such as connection
    state, device identity, status reporting, and command
    handling.
  * Child Classes: SmartLight, FoodDispenser
 *******************************************************/
class Device : public SystemEntity {
protected:
    int deviceID;
    string deviceName;
    string status;
    bool isConnected;
    int ownerID; //or linked pet profile

public:
  void sendCommand() {}

  void acknowledge() {}

  string getStatus(){}
};
