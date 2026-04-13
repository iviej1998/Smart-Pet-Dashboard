#pragma once
#include "User.h"
#include <iostream>
#include <vector>
using namespace std;
/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Responsible for handling user authentication
    and account validation within the Smart Pet Dashboard.
    It validates registration and login data, enforces
    credential requirements, and coordinates account creation
    and access control before user objects are granted system access.
 *******************************************************/

class AuthenticationManager
{
private:
    vector <User> Users;
public:
    //validate registration input
    //verify username and uniqueness
    // enforce password rules
    //verify matching username and password at signup
    //
    AuthenticationManager();
    AuthenticationManager(vector<User> users);

    vector<User>& getUsers();
};