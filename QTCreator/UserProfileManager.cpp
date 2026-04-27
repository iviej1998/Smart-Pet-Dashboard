//
// Created by Angel Madrigal on 4/13/26.
//

#include "UserProfileManager.h"

int UserProfileManager::addUserProfile(const std::string& usName,
                                       const std::string& pasHash,
                                       const std::string& eml,
                                       const std::string& usRole) {
    auto usrProfile = std::make_unique<UserProfile>(usName, pasHash, eml, usRole);

    bool inserted = addUserToDatabase(*usrProfile);
    if (!inserted) {
        return -1;
    }

    Database::QueryResult result = database->executeSelectQuery("SELECT LAST_INSERT_ID()");

    if (result.empty()) {
        std::cout << "LAST_INSERT_ID() returned empty!" << std::endl;
        return -1;
    }

    std::string rawValue = result[0].begin()->second;
    int generatedID = std::stoi(rawValue);
    usrProfile->setUsrID(generatedID);

    int userID = usrProfile->getUserID();
    userProfiles.push_back(std::move(usrProfile));
    return userID;
}
bool UserProfileManager::addUserToDatabase(UserProfile& userProfile) {
    std::string aSqlQuery =
        "INSERT INTO UserProfile (Username, PasswordHash, Email, UserRole) "
        "VALUES ('" + userProfile.getUserName() + "', '" +
        userProfile.getPasswordHash() + "', '" +
        userProfile.getEmail() + "', '" +
        userProfile.getUserRole() + "')";

    bool success = database->executeQuery(aSqlQuery);

    if (!success) {
        std::cerr << "Failed to insert user into database." << std::endl;
        return false;
    }

    return true;
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

std::vector<int> UserProfileManager::getPetIdsForUser(int userID) {
    std::vector<int> petIDs;
    if (!database){
        return petIDs;
    }

    std::string query = "SELECT PetID FROM UserPetAccess WHERE userID = " + std::to_string(userID) + " ORDER BY PetID";
    Database::QueryResult result = database->executeSelectQuery(query);

    for (const auto& row: result) {
        auto id = row.find("PetID");
        if (id != row.end()) {
            petIDs.push_back(std::stoi(id->second));
        }
    }
    return petIDs;

}