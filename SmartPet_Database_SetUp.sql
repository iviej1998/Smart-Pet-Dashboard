# CREATE DATABASE SmartPetDashboard_MonitoringLogging_DB;
USE SmartPetDashboard_MonitoringLogging_DB;

#===================================================================================
# Profile Setup for Pet and User
#
# Creates the tables needed to store user information and pet information.
#===================================================================================

# User Profile table
CREATE TABLE UserProfile (
	UserID INT 	AUTO_INCREMENT PRIMARY KEY, 
    Username VARCHAR(50) NOT NULL UNIQUE,
    PasswordHash VARCHAR(200) NOT NULL,
    UserRole ENUM ('Owner', 'Pet_Sitter', 'Admin', 'QA_User') NOT NULL
);

# Pet Profile set up
CREATE TABLE PetProfile (
	PetID INT AUTO_INCREMENT PRIMARY KEY,
    PetName VARCHAR(50) NOT NULL, 
    
    PetType ENUM ('Dog', 'Cat', 'Fish', 'Reptile', 'Other') NOT NULL,
    CustomPetType VARCHAR(50) NULL,
    CHECK (
		(PetType = 'Other' AND CustomPetType IS NOT NULL)
        OR 
        (PetType != 'Other' AND CustomPetType IS NULL)),
    
    FoodAmount DECIMAL(4, 2) CHECK (FoodAmount >= 0),
    TreatLimit INT CHECK (TreatLimit >= 0), 
    RequireLight BOOLEAN DEFAULT FALSE # change to true if pet requires
);

# junction table to establish many-to-many relationship between pets & owners
CREATE TABLE UserPetAccess (
UserID INT NOT NULL,
PetID INT NOT NULL,
UserRole ENUM('Owner', 'PetSitter', 'Admin') NOT NULL, 
PRIMARY KEY (UserID, PetID),
FOREIGN KEY (UserID) REFERENCES UserProfile(UserID),
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID)
);

#===================================================================================
# Configuration Tables for Smart Pet Devices
#
# Establishes default behavior of the device based on the PetID.
#===================================================================================

# Configuration for Auto Food Dispenser behavior
CREATE TABLE AutoFeedConfig (
AutoFeedID INT AUTO_INCREMENT PRIMARY KEY, 
PetID INT NOT NULL, 
FeedingsPerDay INT NOT NULL CHECK (FeedingsPerDay BETWEEN 1 AND 6), 
HoursBetweenFeeding INT NOT NULL CHECK 
	(HoursBetweenFeeding BETWEEN 3 AND 12), # preventing overfeeding 
FeedStatus ENUM('Empty', 'Near_Empty', 'Full') NOT NULL,
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID)
);

# Configuration for Habitat Lamp Settings
CREATE TABLE LightConfig (
LightID INT AUTO_INCREMENT PRIMARY KEY,
PetID INT NOT NULL, 
DefaultBrightness ENUM('Low', 'Medium', 'High'),
DefaultColor VARCHAR(30), 
DefaultHeatLevel ENUM('Low', 'Medium', 'High'),
DurationHours INT CHECK (DurationHours BETWEEN 0 AND 24), 
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID)
);

#===================================================================================
# Automatic Device Schedule Setup
#
# Creates tables to setup automatic schedules for pet feeding or light operations.
#===================================================================================

# Auto feed schedule table, where portion size defaults to pet profile unless otherwise stated
CREATE TABLE AutoFeedSchedule (
FeedScheduleID INT AUTO_INCREMENT PRIMARY KEY, 
PetID INT NOT NULL, 
FeedTime TIME NOT NULL,

PortionSize DECIMAL(4, 2) NULL CHECK (PortionSize >= 0), 
UseDefaultPortion BOOLEAN DEFAULT TRUE, # use default portion size in pet profile
CHECK (
	(UseDefaultPortion = TRUE AND PortionSize IS NULL)
    OR
    (UseDefaultPortion = FALSE AND PortionSize IS NOT NULL)),

IsActive BOOLEAN DEFAULT TRUE, # sets up automatic feeding
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID)
);

# Auto light schedule 
CREATE TABLE AutoLightSchedule (
LightScheduleID INT AUTO_INCREMENT PRIMARY KEY,
PetID INT NOT NULL,

StartTime TIME NOT NULL,
EndTime TIME NOT NULL, 
CHECK (StartTime < EndTime),

Brightness ENUM('Low', 'Medium', 'High') NULL, 
Color VARCHAR(30) NULL, 
HeatLevel ENUM('Low', 'Medium', 'High') NULL,
UseDefaultSettings BOOLEAN DEFAULT TRUE,
IsActive BOOLEAN DEFAULT TRUE,
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID)
);

#===================================================================================
# Logging History Table Setup
#
# Creates tables to log manual and automatic commands for both Smart Pet Devices
#===================================================================================

# Smart Pet Food Dispenser Log History
CREATE TABLE FeedingHistory (
FoodLogID INT AUTO_INCREMENT PRIMARY KEY,
PetID INT NOT NULL,
UserID INT NULL, 
FoodTimestamp DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
FeedingType ENUM('Manual', 'Automatic') NOT NULL, 
FoodType ENUM('Food', 'Treat'),
AmountOunces DECIMAL (4, 2) CHECK (AmountOunces >= 0),
TreatQuantity INT CHECK (TreatQuantity >= 0), 
DispenserConnected BOOLEAN, 
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID),
FOREIGN KEY (UserID) REFERENCES UserProfile(UserID)
);

# Table for Light Log History
CREATE TABLE LightHistory (
LightLogID INT AUTO_INCREMENT PRIMARY KEY, 
PetID INT NOT NULL, 
UserID INT NULL, 
LightTimestamp DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
ActionType ENUM('Manual', 'Automatic') NOT NULL, 
ChangedField ENUM('Brightness', 'Color', 'Heat', 'Power') NOT NULL,
OldValue VARCHAR(50) NOT NULL, # what light setting being changed was 
NewValue VARCHAR(50) NOT NULL, # new light setting after change
CHECK (Oldvalue <> NewValue),

LightConnected BOOLEAN, 
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID),
FOREIGN KEY (UserID) REFERENCES UserProfile(UserID)
);

# table for both automatic and manual commands
CREATE TABLE CommandHistory (
CommandID INT AUTO_INCREMENT PRIMARY KEY,
PetID INT NOT NULL, 
UserID INT NULL, # null if automated command
CommandTimestamp DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
CommandSource ENUM('Manual', 'Automatic') NOT NULL,
CommandType ENUM(
				'Food_Dispensed', 
                'Treat_Dispensed',
                'Light_ON',
                'Light_OFF', 
                'Heat_ON',
                'Heat_OFF',
                'Heat_Change',
                'Brightness_Change', 
                'Color_Change') NOT NULL,
Details VARCHAR(150),
FOREIGN KEY (PetID) REFERENCES PetProfile(PetID),
FOREIGN KEY (UserID) REFERENCES UserProfile(UserID)
);

#===================================================================================
# Indexing to optimize data retrieval
#
# Indices created to improve query performance on frequently queried foreign keys, 
# such as PetID and UserID, to improve performance for system log retrieval, schedule
# lookup, and user-specified dashboard queries.
#===================================================================================

# index to improve lookup speed for user-pet relationships
CREATE INDEX idx_userpet_user ON UserPetAccess(UserID);
CREATE INDEX idx_userpet_pet ON UserPetAccess(PetID);

# index for feeding logs by pet
CREATE INDEX idx_feeding_pet ON FeedingHistory(PetID);
CREATE INDEX idx_feeding_user ON FeedingHistory(UserID);

# index for habitat light logs by pet
CREATE INDEX idx_light_pet ON LightHistory(PetID);
CREATE INDEX idx_light_user ON LightHistory(UserID);

# index for command history by pet
CREATE INDEX idx_command_pet ON CommandHistory(PetID);
CREATE INDEX idx_command_user ON CommandHistory(UserID);

# index for schedule lookup
CREATE INDEX idx_feed_schedule_pet ON AutoFeedSchedule(PetID);
CREATE INDEX idx_light_schedule_pet ON AutoLightSchedule(PetID);
