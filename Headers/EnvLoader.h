//
// Created by Angel Madrigal on 4/13/26.
//
#pragma once
#include <unordered_map>
#include <string>
#include <fstream>

std::unordered_map<std::string, std::string> loadEnv(const std::string& filePath);