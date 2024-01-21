#include "TrafficNode.h"
#include <iostream>

TrafficNode::TrafficNode(const std::string& licensePlate)
    : licensePlate(licensePlate), violation(nullptr), left(nullptr), right(nullptr) {}

TrafficNode::~TrafficNode() {
    delete violation;
    delete left;
    delete right;
}

void TrafficNode::addTrafficViolation(const std::string& violationType) {
    if (!violation) {
        violation = new TrafficViolation(violationType);
    }
    else {
        std::cout << "Violation already exists for " << licensePlate << std::endl;
    }
}

void TrafficNode::printData() const {
    std::cout << "License Plate: " << licensePlate << "\tViolation: ";
    if (violation) {
        std::cout << violation->getViolationType();
    }
    else {
        std::cout << "None";
    }
    std::cout << std::endl;
}
