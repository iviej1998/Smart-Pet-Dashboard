#pragma once
#include "UserProfile.h"
#include "PetProfile.h"
#include <vector>
#include <string>

class PetOwner : public UserProfile {
private:
    int OwnerID;
    bool isAuthenticated = true;
    std::vector<PetProfile> PetProfiles;

public:
    PetOwner(int ownerID,
             bool isAuth,
             std::vector<PetProfile> PP,
             std::string username,
             std::string password,
             std::string passwordHash,
             std::string email,
             std::string role);
};