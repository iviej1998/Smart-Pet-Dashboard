#pragma once
#include <iostream>
#include "User.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a priviledged system user responsible 
    for maintaining and overseeing the Smart Pet Dashboard System.
    This class extends the User class and provides administrative
    functionality such as managing user accounts, monitoring system activity,
    and ensuring system integrity.
 *******************************************************/

class SystemAdmin : public User {
protected:
public:

   void validate_user() {
      
   }

};
