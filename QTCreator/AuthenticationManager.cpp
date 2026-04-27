#include "AuthenticationManager.h"
#include "UserProfileManager.h"

AuthenticationManager::AuthenticationManager(std::vector<UserProfile> users,
                                             UserProfileManager& Manage,
                                             Database* database)
    : users(users), Manage(Manage), database(database) {}

const std::vector<UserProfile>& AuthenticationManager::getUsers() const
{
    return users;
}

int AuthenticationManager::getUsersSize() const
{
    return users.size();
}

bool AuthenticationManager::ValidateCredentials(const std::string& email, const std::string& password)
{
    if (!database) {
        return false;
    }

    std::string query =
        "SELECT PasswordHash FROM UserProfile WHERE Email = '" + email + "'";

    Database::QueryResult result = database->executeSelectQuery(query);

    if (result.empty()) {
        return false;
    }

    std::string storedHash = result[0]["PasswordHash"];

    // TEMP: because your current hashPassword() just turns password into ****
    // this compares the entered password after hashing to the stored PasswordHash
    return hashPassword(password) == storedHash;
}

int AuthenticationManager::getUserIdByEmail(const std::string& email) const
{
    if (!database) {
        return -1;
    }

    std::string query =
        "SELECT UserID FROM UserProfile WHERE Email = '" + email + "'";

    Database::QueryResult result = database->executeSelectQuery(query);

    if (result.empty()) {
        return -1;
    }

    return std::stoi(result[0].at("UserID"));
}
std::string AuthenticationManager::getUsernameByEmail(const std::string& email) const
{
    if (!database) {
        return "";
    }

    std::string query =
        "SELECT Username FROM UserProfile WHERE Email = '" + email + "'";

    Database::QueryResult result = database->executeSelectQuery(query);

    if (result.empty()) {
        return "";
    }

    return result[0].at("Username");
}

std::string AuthenticationManager::hashPassword(const std::string& password)
{
    std::string hash = password;
    for (int i = 0; i < password.length(); ++i) {
        hash[i] = '*';
    }
    return hash;
}

bool AuthenticationManager::registerUser(const std::string& username,
                                         const std::string& password,
                                         const std::string& email)
{
    if (!database) {
        std::cerr << "Database pointer is null." << std::endl;
        return false;
    }

    if (!validatePasswordStrength(password)) {
        std::cerr << "Password failed strength validation." << std::endl;
        return false;
    }

    std::string checkQuery =
        "SELECT UserID FROM UserProfile WHERE Email = '" + email +
        "' OR Username = '" + username + "'";

    Database::QueryResult existing = database->executeSelectQuery(checkQuery);

    if (!existing.empty()) {
        std::cerr << "User already exists." << std::endl;
        return false;
    }

    std::string hash = hashPassword(password);
    std::string defaultRole = "Owner";

    int newUserId = Manage.addUserProfile(username, hash, email, defaultRole);

    if (newUserId == -1) {
        std::cerr << "Database insert failed in addUserProfile()." << std::endl;
        return false;
    }

    std::cout << "User inserted with ID: " << newUserId << std::endl;
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