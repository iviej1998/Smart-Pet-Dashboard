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

    AuthenticationManager();
    AuthenticationManager(vector<User> users);
    vector<User>& getUsers();
    bool login(const string& username, const string& password);
    bool registerUser(const string& username, const string& password);
    bool verifyPassword(const string& username, const string& password);
    string hashPassword(const string& password);
    bool updatePassword(const string& username, const string& oldPassword, const string& newPassword);
    bool validatePasswordStrength(const string& password);


};