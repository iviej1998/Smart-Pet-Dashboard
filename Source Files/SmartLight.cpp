#pragma once
#include "SmartLight.cpp"
#include "Device.cpp"
#include <iostream>
using namespace std;
/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents the smart habitat lighting device
    used within the Smart Pet Dashboard system. This class
    extends the Device base class and provides specialized functionality
    for controlling habitat lighting features such as power state,
    brightness, color, heating power, and heating level.
    It supports remote environmental control for reptiles 
    and aquariums through the centralized dashboard. 
 *******************************************************/
class SmartLight : public Device
{
private:
    int brightnessLevel; // 0–100
    bool isOn;

public:
    // Constructor
    SmartLight(int id, string name, int ownerID) {}

    // Core functionality
    void turnOn() {}
    void turnOff() {}
    void setBrightness(int level) {}

    // Override device behavior
    void sendCommand(string command) override {}
    void acknowledge() override {}

    // Status
    int getBrightness() {}
};