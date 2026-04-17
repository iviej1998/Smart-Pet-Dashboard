//
// Created by Angel Madrigal on 4/13/26.
//

#include "UserProfileManager.h"

int UserProfileManager::addUserProfile(const std::string& usName, const std::string& pasHash, const std::string& eml, const std::string& usRole) {
    auto usrProfile = std::make_unique<UserProfile>(usName, pasHash, eml, usRole);
    addUserToDatabase(*usrProfile);
    //std::cout << "User Profile insert attempted" << std::endl; - Debugging

    // Retrieve auto-generated ID from database
    Database::QueryResult result = database->executeSelectQuery("SELECT LAST_INSERT_ID()");
    //std::cout << "Result size: " << result.size() << std::endl << std::flush; - Debugging
    if (result.empty()) {
        std::cout << "Result is empty!" << std::endl;
    } else {
        std::string rawValue = result[0].begin()->second;
        //std::cout << "Raw value: [" << rawValue << "]" << std::flush << std::endl; - Debugging
        int generatedID = std::stoi(rawValue);
        usrProfile->setUsrID(generatedID); //Sets UserID from database
    }
    int userID = usrProfile->getUserID();
    userProfiles.push_back(std::move(usrProfile));
    return userID;

}
void UserProfileManager::addUserToDatabase(UserProfile& userProfile) {
    std::string aSqlQuery = "INSERT INTO UserProfile (Username, PasswordHash, Email, UserRole) "
                            "VALUES ('" + userProfile.getUserName() + "', '" + userProfile.getPasswordHash() + "', '" + userProfile.getEmail() + "', "
                                                                                                                                     "'" + userProfile.getUserRole() + "' )";

    database->executeQuery(aSqlQuery);
}

void UserProfileManager::deleteUserFromDatabase(UserProfile& userProfile) {
    std::string dSqlQuery = "DELETE FROM UserProfile WHERE Username = '" + userProfile.getUserName() + "' ";

    database->executeQuery(dSqlQuery);
}


void UserProfileManager::deleteUserProfile(UserProfile& usrProf) {
    deleteUserFromDatabase(usrProf);
    auto it = std::find_if(userProfiles.begin(), userProfiles.end(), [&](const std::unique_ptr<UserProfile>& p) {
        return p->getUserID() == usrProf.getUserID();
    });

    if (it != userProfiles.end()) {
        userProfiles.erase(it);
    }
}

void UserProfileManager::updateUserProfile(UserProfile& usrProf, const std::string& usName, const std::string& pasHash, const std::string& eml) {
    usrProf.editUsrProfile(usName, pasHash, eml);

    updateUserInDatabase(usrProf);
}
void UserProfileManager::updateUserInDatabase(UserProfile& userProfile) { //Dont let them change user role
    std::string uSqlQuery = "UPDATE UserProfile SET Username = '" + userProfile.getUserName() + "', PasswordHash = '" + userProfile.getPasswordHash() + "', Email = '" + userProfile.getEmail() + "' WHERE UserID = " + std::to_string(userProfile.getUserID()) + " ";

    database->executeQuery(uSqlQuery);
}

void UserProfileManager::linkUserToPet(int usrID, int petID, const std::string& userRole) {
    std::string lSqlQuery = "INSERT INTO UserPetAccess (UserID, PetID, UserRole) VALUES ("+ std::to_string(usrID) +", "+ std::to_string(petID) + ", '" + userRole + "' ) ";

    database->executeQuery(lSqlQuery);
}

int UserProfileManager::addPetToUser(int userID, const std::string& petName, const std::string& petType,
                                     const std::string& otherType, double foodAmt, int treatLimit, bool hasLamp) {

    int petID = petProfileManager->addPetProfile(petName, petType, otherType, foodAmt, treatLimit, hasLamp);
    userPetAccess[userID].push_back(petID);
    auto it = std::find_if(userProfiles.begin(), userProfiles.end(),[&](const std::unique_ptr<UserProfile>& p) {
        return p->getUserID() == userID;
    });

    if (it != userProfiles.end()) {
        linkUserToPet(userID, petID, (*it)->getUserRole());
    } else {
        std::cerr << "User not found!" << std::endl;
    }

    return petID;
}