#include "AuthenticationManager.h"
using namespace std;

AuthenticationManager::AuthenticationManager() {}

AuthenticationManager::AuthenticationManager(vector<User> users) : Users(users){}

vector<User>& AuthenticationManager:: getUsers() {
    return Users;
}
