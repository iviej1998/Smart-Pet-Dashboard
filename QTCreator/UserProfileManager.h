//
// Created by Angel Madrigal on 4/13/26.
//

#pragma once
#include <memory>
#include <unordered_map>
#include <algorithm>
#include "UserProfile.h"
#include "Database.h"
#include "PetProfileManager.h" // In order to use the same database

class UserProfileManager {
private:
    std::unordered_map<int, std::vector<int> > userPetAccess;
    std::shared_ptr<PetProfileManager> petProfileManager;
    std::shared_ptr<Database> database;
    std::vector<std::unique_ptr<UserProfile> > userProfiles;

    void addUserToDatabase(UserProfile& userProfile);
    void deleteUserFromDatabase(UserProfile& userProfile);
    void updateUserInDatabase(UserProfile& userProfile);
    void linkUserToPet(int usrID, int petID, const std::string& userRole);
public:
    int addUserProfile(const std::string& usName, const std::string& pasHash, const std::string& eml, const std::string& usRole); //Calls PetProfileManager::addPetProfile() ?
    void deleteUserProfile(UserProfile& usrProf);
    void updateUserProfile(UserProfile& usrProf, const std::string& usName, const std::string& pasHash, const std::string& eml);
    int addPetToUser(int userID, const std::string& petName, const std::string& petType,
                     const std::string& otherType, double foodAmt, int treatLimit, bool hasLamp);

    UserProfileManager(std::shared_ptr<PetProfileManager> petProfileManager, std::shared_ptr<Database> myDb) : petProfileManager(petProfileManager), database(myDb) {}
};