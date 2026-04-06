#include "SmartFeeder.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements SmartFeeder class functions
 *******************************************************/

// Constructor
SmartFeeder::SmartFeeder(int id, string name, int ownerID)
    : Device(id, name, ownerID)
{
}

// Feeding actions
void SmartFeeder::dispenseFood()
{
}

void SmartFeeder::dispenseTreat()
{
}

// Configuration
void SmartFeeder::setPortionSize(int size)
{
}

void SmartFeeder::addFeedingSchedule(string time)
{
}

// Status / monitoring
void SmartFeeder::updateFoodLevel(int amount)
{
}

void SmartFeeder::updateTreatLevel(int amount)
{
}

string SmartFeeder::getFeederStatus()
{
}

// Override base class behavior
void SmartFeeder::sendCommand(string command)
{
}

void SmartFeeder::acknowledge()
{
}