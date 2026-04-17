//
// Created by Angel Madrigal on 4/13/26.
//

#include "UserProfile.h"

void UserProfile::setUsrID(int id) { userID = id; }

//Setters
void UserProfile::setUsrName(const std::string& usrName) { userName = usrName; }
void UserProfile::setPassword(const std::string& pass) { password = pass; }
void UserProfile::setPassHash(const std::string& passHash) { passwordHash = passHash; } //Needs necessary library, Jill will already hash the password, not me
void UserProfile::setUsrEmail(const std::string& usrEmail) { email = usrEmail; }
void UserProfile::setUsrRole(const std::string& usrRole) { userRole = usrRole; }

//Getters
int UserProfile::getUserID() const { return userID; }
std::string UserProfile::getPassword() const { return password; }
std::string UserProfile::getUserName() const { return userName; }
std::string UserProfile::getPasswordHash() const { return passwordHash; } //Might not need, tdb
std::string UserProfile::getEmail() const { return email; }
std::string UserProfile::getUserRole() const { return userRole; }

void UserProfile::editUsrProfile(const std::string& usName, const std::string& pasHash, const std::string& usrEmail) {  //Dont let them change user role
    userName = usName;
    passwordHash = pasHash;
    email = usrEmail;

    std::cout << "User profile for " << userName << " successfully changed!" << std::endl;
}

void UserProfile::displayProfile() {
    std::cout << "Username: " << userName << std::endl;
    std::cout << "User Role: " << userRole << std::endl;
}