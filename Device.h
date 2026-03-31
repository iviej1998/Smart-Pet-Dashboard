#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "PetProfile.h"
#include "LogEntry.h"
using namespace std;

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
