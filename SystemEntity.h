#pragma once
#include <iostream>
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Serves as a common base class for major system 
    objects that require shared identity or common attributes.
    This class provides the foundation for inherited classes,
    allowing consistent handling of core data like unique identifiers.
    Child Classes: User, Device, PetProfile, LogEntry
 *******************************************************/
class SystemEntity {
protected:
    int EntityID;
};
