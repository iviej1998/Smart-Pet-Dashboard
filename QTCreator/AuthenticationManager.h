#pragma once
#include "UserProfile.h"
#include "UserProfileManager.h"
#include <iostream>
#include <vector>
#include <cctype>
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
    vector<UserProfile> users;
    UserProfileManager& Manage;

public:
    AuthenticationManager(std::vector<UserProfile> users, UserProfileManager& Manage);
    const vector<UserProfile>& getUsers() const;
    int getUsersSize() const;
    bool ValidateCredentials(const string& username, const string& password);
    bool registerUser(const string& username, const string& password, const string& email);
    string hashPassword(const string& password);
    bool updatePassword(const string& username, const string& oldPassword, const string& newPassword);
    bool validatePasswordStrength(const string& password);
};