#include "PetOwner.h"

PetOwner::PetOwner(int ownerID,
                   bool isAuth,
                   std::vector<PetProfile> PP,
                   std::string username,
                   std::string password,
                   std::string passwordHash,
                   std::string email,
                   std::string role)
    : UserProfile(username, password, passwordHash, email, role),
    OwnerID(ownerID),
    isAuthenticated(isAuth),
    PetProfiles(PP)
{
}