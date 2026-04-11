#include "SmartFeeder.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements SmartFeeder class functions
 *******************************************************/

// Constructor
SmartFeeder::SmartFeeder(int id, string name, int ownerID)
    : Device(id, name, ownerID), portionSize(0), foodLevel(100), treatLevel(50)
{
}

// Dispense normal food
void SmartFeeder::dispenseFood() {
    if (foodLevel >= portionSize) {
        foodLevel -= portionSize;
        cout << "Dispensing food. Portion size: " << portionSize << endl;
    }
    else {
        cout << "Not enough food in feeder." << endl;
    }
}

// Dispense a treat
void SmartFeeder::dispenseTreat() {
    if (treatLevel > 0) {
        treatLevel--;
        cout << "Dispensing treat." << endl;
    }
    else {
        cout << "No treats remaining." << endl;
    }
}

// Set portion size
void SmartFeeder::setPortionSize(int size) {
    portionSize = size;
}

// Add a feeding time to the schedule
void SmartFeeder::addFeedingSchedule(string time) {
    //feedingSchedule.push_back(time);
}

// Update food level
void SmartFeeder::updateFoodLevel(int amount) {
    foodLevel = amount;
}

// Update treat level
void SmartFeeder::updateTreatLevel(int amount) {
    treatLevel = amount;
}

// Return feeder status
string SmartFeeder::getFeederStatus() {
    if (foodLevel <= 0) {
        return "EMPTY";
    }
    else if (foodLevel < 20) {
        return "NEAR_EMPTY";
    }
    else {
        return "FULL";
    }
}

// Send command to feeder
void SmartFeeder::sendCommand(string command) {
    cout << "SmartFeeder received command: " << command << endl;
    status = command;
}

// Acknowledge command
void SmartFeeder::acknowledge() {
    cout << "SmartFeeder acknowledged command." << endl;
}