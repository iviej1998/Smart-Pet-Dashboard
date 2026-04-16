//
// Created by Angel Madrigal on 4/12/26.
//
#include "PetProfileManager.h"

int PetProfileManager::addPetProfile(const std::string& newName,
                                     const std::string& newType, const std::string& newOtherType, double newFoodAmt,
                                     int newTreatLimit, bool newHasLamp) { //adds to vector and database

    auto profile = std::make_unique<PetProfile>(newName, newType, newOtherType, newFoodAmt, newTreatLimit, newHasLamp);
    addToDatabase(*profile);
    //std::cout << "Insert attempted" << std::endl; - Debugging

    // Retrieve auto-generated ID from database
    Database::QueryResult result = mySQLdb->executeSelectQuery("SELECT LAST_INSERT_ID()");
    //std::cout << "Result size: " << result.size() << std::endl << std::flush; - Debugging
    if (result.empty()) {
        std::cout << "Result is empty!" << std::endl;
    } else {
        std::string rawValue = result[0].begin()->second;
        //std::cout << "Raw value: [" << rawValue << "]" << std::flush << std::endl; - Debugging
        int generatedID = std::stoi(rawValue);
        profile->setID(generatedID);
    }
    int newID = profile->getID();
    petProfiles.push_back(std::move(profile));
    return newID; //Return petID for UserProfileManagement to insert into UserPetAccess table
}
void PetProfileManager::addToDatabase(PetProfile &petProfile) { //TODO: Prevent Injection attacks with binding parameters
    std::string otherTypeVal = petProfile.getOtherType().empty() ? "NULL" : "'" + petProfile.getOtherType() + "'"; //Make into normal if statements
    std::string aSqlQuery = "INSERT INTO petprofile (PetName, PetType, CustomPetType, FoodAmount, TreatLimit, RequireLight) "
                            "VALUES ('" + petProfile.getName() + "', '" + petProfile.getType() + "', " + otherTypeVal + ", " + std::to_string(petProfile.getFoodAmount()) + ", " + std::to_string(petProfile.getTreatLimit()) + ", "
                            + std::to_string(petProfile.getLamp()) + ")";

    mySQLdb->executeQuery(aSqlQuery);
}

void PetProfileManager::deletePetProfile(PetProfile &petProfile) { //deletes from vector abd database
    deleteFromDatabase(petProfile);
    auto it = std::find_if(petProfiles.begin(), petProfiles.end(), [&](const std::unique_ptr<PetProfile>& p) {
        return p->getID() == petProfile.getID();
    });

    if (it != petProfiles.end()) {
        petProfiles.erase(it);
    }

}
void PetProfileManager::deleteFromDatabase(PetProfile &petProfile) {
    std::string dSqlQuery1 = "DELETE FROM UserPetAccess WHERE PetID = "+ std::to_string(petProfile.getID()) + " ";
    std::string dSqlQuery2 = "DELETE FROM petprofile WHERE PetID = " + std::to_string(petProfile.getID()) + " ";

    mySQLdb->executeQuery(dSqlQuery1);
    mySQLdb->executeQuery(dSqlQuery2);
}

void PetProfileManager::updatePetProfile(PetProfile& petProfile, const std::string& newName,
                                         const std::string& newType, const std::string& newOtherType, double newFoodAmt,
                                         int newTreatLimit, bool newHasLamp) {
    petProfile.editProfile(newName, newType, newOtherType, newFoodAmt, newTreatLimit, /*bool hasF,*/ newHasLamp);
    updateInDatabase(petProfile);
}
void PetProfileManager::updateInDatabase(PetProfile &petProfile) {
    std::string uSqlQuery = "UPDATE petprofile SET PetName = '" + petProfile.getName() + "', PetType = '" + petProfile.getType() + "', CustomPetType = " + (petProfile.getOtherType().empty() ? "NULL" : "'" + petProfile.getOtherType() + "'") + ", "
                                                                                                                                                                                                                                                  "FoodAmount =  " + std::to_string(petProfile.getFoodAmount()) + ", TreatLimit = " + std::to_string(petProfile.getTreatLimit()) + ", "
                                                                                                                                            "RequireLight = " + std::to_string(petProfile.getLamp()) + " WHERE PetID = " + std::to_string(petProfile.getID()) + " ";

    mySQLdb->executeQuery(uSqlQuery);
}


void PetProfileManager::displayAllPetProfiles() {
    for (const auto& profile : petProfiles) {
        profile->displayProfile();
    }
}

void PetProfileManager::pullPetProfile(int userId) {
    pullFromDatabase(userId);
    displayAllPetProfiles();
}

void PetProfileManager::pullFromDatabase(int userId) {
    petProfiles.clear(); //Makes sure there is no redundancy when pulling pet profiles from database if user adds any in same session
    std::string allPetIDQuery = "SELECT PetID FROM UserPetAccess WHERE UserID = " + std::to_string(userId) + " ";
    Database::QueryResult allPetIDs =  mySQLdb->executeSelectQuery(allPetIDQuery);

    for (auto i = 0; i < allPetIDs.size(); i++) {
        std::string allPetsOfUser = "SELECT * FROM PetProfile WHERE PetID = "+ allPetIDs[i]["PetID"] + " ";
        Database::QueryResult allPetProfs = mySQLdb->executeSelectQuery(allPetsOfUser);

        auto tempPetProfile = std::make_unique<PetProfile>(allPetProfs[0]["PetName"], allPetProfs[0]["PetType"], allPetProfs[0]["CustomPetType"], std::stod(allPetProfs[0]["FoodAmount"]), std::stoi(allPetProfs[0]["TreatLimit"]), std::stoi(allPetProfs[0]["RequireLight"]));
        tempPetProfile->setID(std::stoi(allPetProfs[0]["PetID"]));
        petProfiles.push_back(std::move(tempPetProfile));
    }
}

PetProfile& PetProfileManager::returnPetProfile(int petId) {
    auto it = std::find_if(petProfiles.begin(),petProfiles.end(),[&](const std::unique_ptr<PetProfile>& petProfile) {
        return petProfile->getID() == petId;
    });
    if (it != petProfiles.end()) {
        return *(*it);
    } else {
        std::cerr << "Pet Profile not found!" << std::endl;
        throw std::runtime_error("Pet Profile not found!");
    }
}