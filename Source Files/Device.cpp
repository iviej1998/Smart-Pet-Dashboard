#include "Device.cpp"

/********************************************************
 * Authors: Jillian Ivie
 * Version: 1.1
 * Purpose: Implements Device class
 *******************************************************/

// Constructor
Device::Device(int id, string name, int owner)
    : deviceID(id)
    , deviceName(name)
    , ownerID(owner)
    , status("OFF")
    , isConnected(false)
{}

// Send a command to device
void Device::sendCommand(string command)
{
    cout << "Sending command '" << command << "' to device: " << deviceName << endl;
    status = command;
}

// Acknowledge command
void Device::acknowledge()
{
    cout << "Device " << deviceName << " acknowledged command." << endl;
}

// Get current status
string Device::getStatus()
{
    return status;
}