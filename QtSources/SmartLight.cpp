#include "SmartLight.h"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements SmartLight class functions
 *******************************************************/

// Constructor
SmartLight::SmartLight(int id, string name, int ownerID, int brightnessLevel, bool isOn)
    : Device(id, name, ownerID), brightnessLevel(brightnessLevel)
{
}

// Core functionality
void SmartLight::turnOn()
{
}

void SmartLight::turnOff()
{
}

void SmartLight::setBrightness(int level)
{
}

// Override device behavior
void SmartLight::sendCommand(string command)
{
}

void SmartLight::acknowledge()
{
}

// Status
int SmartLight::getBrightness()
{
}