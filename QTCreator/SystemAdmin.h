#include <iostream>
#include "UserProfile.h"
class SystemAdmin : public UserProfile
{
public:
    SystemAdmin(const std::string& username,
                const std::string& password,
                const std::string& passwordHash,
                const std::string& email);
};