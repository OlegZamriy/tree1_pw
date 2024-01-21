#ifndef TRAFFICDATABASE_H
#define TRAFFICDATABASE_H

#include "TrafficNode.h"
#include <map>

class TrafficDatabase {
public:
    TrafficDatabase();
    ~TrafficDatabase();
    void addTrafficViolation(const std::string& licensePlate, const std::string& violationType);
    void removeTrafficViolation(const std::string& licensePlate);
    void printDatabase() const;
    void printData(const std::string& licensePlate) const;
    void printDataInRange(const std::string& startPlate, const std::string& endPlate) const;

private:
    TrafficNode* root;
    std::map<std::string, TrafficNode*> licensePlateMap;
};

#endif // TRAFFICDATABASE_H
