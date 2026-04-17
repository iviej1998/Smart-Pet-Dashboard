#include "SystemAdmin.h"

SystemAdmin::SystemAdmin(const std::string& username,
                         const std::string& password,
                         const std::string& passwordHash,
                         const std::string& email)
    : UserProfile(username, password, passwordHash, email, "System Admin")
{
}