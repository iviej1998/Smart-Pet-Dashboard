#pragma once
#include "Device.h"
#include <iostream>
#include <vector>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents the automatic pet feeding device 
 * within the Smart Pet Dashboard system. This class extends
 * the Device class and provides functionality for dispensing
 * food and treats, managing feeding schedules, controlling
 * portion sizes, and reporting feeder status.
 *******************************************************/

class SmartFeeder : public Device
{
private:
    int portionSize;
    int foodLevel;
    int treatLevel;
    vector<string> feedingSchedule;

public:
    // Constructor
    SmartFeeder(int id, string name, int ownerID);

    // Feeding actions
    void dispenseFood();
    void dispenseTreat();

    // Configuration
    void setPortionSize(int size);
    void addFeedingSchedule(string time);

    // Status / monitoring
    void updateFoodLevel(int amount);
    void updateTreatLevel(int amount);
    string getFeederStatus();

    // Overridden device behaviors
    void sendCommand(string command) override;
    void acknowledge() override;
};