#include "AuthenticationManager.h"
#include "UserProfileManager.h"

AuthenticationManager::AuthenticationManager(std::vector<UserProfile> users, UserProfileManager& Manage)
    : users(users), Manage(Manage) {}

const std::vector<UserProfile>& AuthenticationManager::getUsers() const {
    return users;
}

int AuthenticationManager::getUsersSize() const
{
    return users.size();
}

bool AuthenticationManager::ValidateCredentials(const std::string& username, const std::string& password) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getUserName() == username && users[i].getPassword() == password) {
            return true;
        }
    }
    return false;
}

std::string AuthenticationManager::hashPassword(const std::string& password)
{
    std::string hash = password;
    for (int i = 0; i < password.length(); ++i) {
        hash[i] = '*';
    }
    return hash;
}

bool AuthenticationManager::registerUser(const std::string& username, const std::string& password, const std::string& email)
{
    UserProfile p;
    p.setUsrName(username);
    p.setPassword(password);
    std::string hash = hashPassword(password);
    p.setPassHash(hash);
    p.setUsrEmail(email);
    std::string defaultRole = "PetOwner";
    //Manage.addUserProfile(username, hash, email, defaultRole);
    users.push_back(p);
    return true;
}

bool AuthenticationManager::updatePassword(const std::string& username,
                                           const std::string& oldPassword,
                                           const std::string& newPassword)
{
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getUserName() == username) {
            if (users[i].getPassword() != oldPassword) {
                return false;
            }

            if (!validatePasswordStrength(newPassword)) {
                return false;
            }

            users[i].setPassword(newPassword);
            users[i].setPassHash(hashPassword(newPassword));
            return true;
        }
    }
    return false;
}

bool AuthenticationManager::validatePasswordStrength(const std::string& password)
{
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (int i = 0; i < password.length(); ++i) {
        char ch = password[i];

        if (std::isupper(static_cast<unsigned char>(ch))) {
            hasUpper = true;
        }
        else if (std::islower(static_cast<unsigned char>(ch))) {
            hasLower = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(ch))) {
            hasDigit = true;
        }
        else {
            hasSpecial = true;
        }
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}