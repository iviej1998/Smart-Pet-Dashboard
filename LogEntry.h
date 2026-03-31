#pragma once
#include <iostream>
#include "SystemEntity.h"
#include "User.h"
#include "Device.h"
#include "PetProfile.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a recorded system event or activity. 
    This class provides a common structure for tracking actions
    such as feeding events, device commands, status changes,
    and other monitored operations. It serves as a base class
    for more specific logging classes and supports the system's
    monitoring and accountability features.
  * Child Classes: FeedingLog, DeviceActivityLog, SystemEventLog
 *******************************************************/

class LogEntry : public SystemEntity {
protected:
    int timestamp;
    string message;
    int userID;
};
