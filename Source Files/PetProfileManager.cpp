//
// Created by Angel Madrigal on 4/12/26.
//
#include "PetProfileManager.h"

int PetProfileManager::addPetProfile(const std::string& newName,
                      const std::string& newType, const std::string& newOtherType, double newFoodAmt,
                      int newTreatLimit, bool newHasLamp) { //adds to vector and database

    auto profile = std::make_unique<PetProfile>(newName, newType, newOtherType, newFoodAmt, newTreatLimit, newHasLamp);
    addToDatabase(*profile);
    std::cout << "Insert attempted" << std::endl;

    // Retrieve auto-generated ID from database
    Database::QueryResult result = mySQLdb->executeSelectQuery("SELECT LAST_INSERT_ID()");
    std::cout << "Result size: " << result.size() << std::endl << std::flush;
    if (result.empty()) {
        std::cout << "Result is empty!" << std::endl;
    } else {
        std::string rawValue = result[0].begin()->second;
        std::cout << "Raw value: [" << rawValue << "]" << std::flush << std::endl;
        int generatedID = std::stoi(rawValue);
        profile->setID(generatedID);
    }
    int newID = profile->getID();
    petProfiles.push_back(std::move(profile));
    return newID; //Return petID for UserProfileManagement to insert into UserPetAccess table
}
void PetProfileManager::addToDatabase(PetProfile &petProfile) { //TODO: Prevent Injection attacks with binding parameters
    std::string otherTypeVal = petProfile.getOtherType().empty() ? "NULL" : "'" + petProfile.getOtherType() + "'";
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
void PetProfileManager::deleteFromDatabase(PetProfile &petProfile) { //TODO: Join User and PetProfile tables so condition is not only PetName
    std::string dSqlQuery = "DELETE FROM petprofile WHERE PetName = '" + petProfile.getName() + "'";

    mySQLdb->executeQuery(dSqlQuery);
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

/*void PetProfileManager::pullPetProfile(int userId) {

}

PetProfile& PetProfileManager::returnPetProfile(int petId) { //TODO: Wait until sql connector is incorporated with user classes

}

void PetProfileManager::pullFromDatabase(int userId) { //TODO: Wait until sql connector is incorporated with user classes

}*/