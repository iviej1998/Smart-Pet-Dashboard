//
// Created by Angel Madrigal on 4/13/26.
//
#include "EnvLoader.h"

#include <iostream>

std::unordered_map<std::string, std::string> loadEnv(const std::string& filePath) {
    std::unordered_map<std::string, std::string> um;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return {};
    }
    std::string line;
    while (std::getline(inFile, line)) {
        size_t index = line.find('=');
        if (index == std::string::npos) continue;
        std::string value = line.substr(index + 1);
        if (!value.empty() && value.back() == '\r') {
            value.pop_back();
        }
        um[line.substr(0, index)] = value;
    }
    return um;
}
