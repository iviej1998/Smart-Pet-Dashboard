#pragma once
#include "UserProfile.h"
#include "UserProfileManager.h"
#include "Database.h"
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class AuthenticationManager
{
private:
    vector<UserProfile> users;
    UserProfileManager& Manage;
    Database* database;

public:
    AuthenticationManager(std::vector<UserProfile> users,
                          UserProfileManager& Manage,
                          Database* database);

    const vector<UserProfile>& getUsers() const;
    int getUsersSize() const;

    bool ValidateCredentials(const string& email, const string& password);
    bool registerUser(const string& username, const string& password, const string& email);
    string hashPassword(const string& password);
    bool updatePassword(const string& username, const string& oldPassword, const string& newPassword);
    bool validatePasswordStrength(const string& password);

    int getUserIdByEmail(const std::string& email) const;
    std::string getUsernameByEmail(const std::string& email) const;
};