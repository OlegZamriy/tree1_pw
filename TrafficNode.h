#ifndef TRAFFICNODE_H
#define TRAFFICNODE_H

#include "TrafficViolation.h"

class TrafficNode {
public:
    TrafficNode(const std::string& licensePlate);
    ~TrafficNode();
    void addTrafficViolation(const std::string& violationType);
    void printData() const;

private:
    std::string licensePlate;
    TrafficViolation* violation;
    TrafficNode* left;
    TrafficNode* right;
};

#endif // TRAFFICNODE_H
