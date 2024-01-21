#include "TrafficDatabase.h"
#include <iostream>

TrafficDatabase::TrafficDatabase() : root(nullptr) {}

TrafficDatabase::~TrafficDatabase() {
    delete root;
}

void TrafficDatabase::addTrafficViolation(const std::string& licensePlate, const std::string& violationType) {
    if (licensePlateMap.find(licensePlate) == licensePlateMap.end()) {
        TrafficNode* newNode = new TrafficNode(licensePlate);
        newNode->addTrafficViolation(violationType);
        licensePlateMap[licensePlate] = newNode;

        if (!root) {
            root = newNode;
        }
    }
    else {
        licensePlateMap[licensePlate]->addTrafficViolation(violationType);
    }
}

void TrafficDatabase::removeTrafficViolation(const std::string& licensePlate) {
    auto it = licensePlateMap.find(licensePlate);
    if (it != licensePlateMap.end()) {
        delete it->second;
        licensePlateMap.erase(it);
    }
    else {
        std::cout << "No data found for " << licensePlate << std::endl;
    }
}

void TrafficDatabase::printDatabase() const {
    if (root) {
        printDataInRange(root, "");
    }
    else {
        std::cout << "Database is empty." << std::endl;
    }
}

void TrafficDatabase::printData(const std::string& licensePlate) const {
    auto it = licensePlateMap.find(licensePlate);
    if (it != licensePlateMap.end()) {
        it->second->printData();
    }
    else {
        std::cout << "No data found for " << licensePlate << std::endl;
    }
}

void TrafficDatabase::printDataInRange(const std::string& startPlate, const std::string& endPlate) const {
    for (const auto& entry : licensePlateMap) {
        if (entry.first >= startPlate && entry.first <= endPlate) {
            entry.second->printData();
        }
    }
}
