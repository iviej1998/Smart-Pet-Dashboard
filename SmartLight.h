#pragma once
#include <iostream>
#include "Device.h"
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

class SmartLight : public Device {
  /* maintain the current power state
    maintain the current brightnss level
    maintain the current color setting
    maintain current heating power state
    maintain current heating level
    recieve and process control commands from the system
    Report updated device status bck to the dashboard
    support logging og lighting and heating actions*/

};