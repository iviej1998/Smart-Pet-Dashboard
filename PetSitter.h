#pragma once
#include <iostream>
#include "User.h"
using namespace std;

/********************************************************
 * Authors: Jillian Ivie,
 * Version: 1.1
 * Purpose: Represents a temporary or limited acess user who 
  is authorized to assist in caring for a pet on behalf of the pet owner.
  This class extends the User class and provides controlled access 
  to selected pet profiles, feeding actions, and monitoring features
  without granting full ownership or administrative purposes.
 *******************************************************/

class PetSitter : public User {
protected:

/* Responsibilities
  view assigned pet profiles
  Monitor pet-related status and activity
  Perform approved care actions for assigned pets
  Interact with permitted devices for assigned pets
  Operate under permitted devices for assigned pets
  Operate under restricted access defined by the pet owner or system
*/


};
