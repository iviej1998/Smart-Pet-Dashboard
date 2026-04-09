#pragma once
#include <iostream>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a generic smart device connected to
 * the Smart Pet Dashboard.
 *******************************************************/

class Device
{
protected:
    int deviceID;
    string deviceName;
    string status;
    bool isConnected;
    int ownerID;

public:
    Device(int id, string name, int owner);

    void virtual sendCommand(string command);
    void virtual acknowledge();
    string getStatus();
};