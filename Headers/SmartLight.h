#pragma once
#include "Device.h"
#include <iostream>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a smart lighting device within the 
 * Smart Pet Dashboard system. This class extends the Device 
 * class and provides functionality for controlling brightness,
 * power state, and lighting schedules.
 *******************************************************/

class SmartLight : public Device
{
private:
    int brightnessLevel; // 0–100
    bool isOn;

public:
    // Constructor
    SmartLight(int id, string name, int ownerID);

    // Core functionality
    void turnOn();
    void turnOff();
    void setBrightness(int level);

    // Override device behavior
    void sendCommand(string command) override;
    void acknowledge() override;

    // Status
    int getBrightness();
};