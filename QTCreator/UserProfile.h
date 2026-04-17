//
// Created by Angel Madrigal on 4/13/26.
//
#pragma once
#include <string>
#include <iostream>

class UserProfile {
private:
    int userID = 0;
    std::string userName;
    std::string password;
    std::string passwordHash;
    std::string email;
    std::string userRole;

    void setUsrID(int id); //Set from the database primary key
public:
    UserProfile(const std::string &usName, const std::string &pass, const std::string &pasHash, const std::string &eml, const std::string &usRole) :
        userName(usName),password(pass), passwordHash(pasHash), email(eml), userRole(usRole) {}
    UserProfile(const std::string &usName, const std::string &pasHash, const std::string &eml, const std::string &usRole) :
        userName(usName), passwordHash(pasHash), email(eml), userRole(usRole) {}
    //Setters
    void setUsrName(const std::string& usrName);
    void setPassword(const std::string& pass);
    void setPassHash(const std::string& passHash); //Needs necessary library
    void setUsrEmail(const std::string& usrEmail);
    void setUsrRole(const std::string& usrRole);

    //Getters
    int getUserID() const;
    std::string getUserName() const;
    std::string getPassword() const; //Might not need, tdb
    std::string getPasswordHash() const; //Might not need, tdb
    std::string getEmail() const;
    std::string getUserRole() const;

    void editUsrProfile(const std::string& usName, const std::string& pasHash, const std::string& usrEmail); //Dont let them change user role
    void displayProfile();

    UserProfile() {}
    ~UserProfile() {}

    friend class UserProfileManager; //Allows use of setUsrID and access hashed password
};