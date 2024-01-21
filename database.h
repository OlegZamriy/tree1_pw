#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>

class TrafficViolation {
public:
    std::string violationDetails;

    TrafficViolation(const std::string& details) : violationDetails(details) {}
};

class Node {
public:
    std::string licensePlate;
    std::vector<TrafficViolation> violations;
    Node* left;
    Node* right;

    Node(const std::string& plate) : licensePlate(plate), left(nullptr), right(nullptr) {}
};

class Database {
private:
    Node* root;

    void insert(Node*& node, const std::string& plate, const std::string& violationDetails);
    void print(Node* node);
    Node* search(Node* node, const std::string& plate);
    void printRange(Node* node, const std::string& start, const std::string& end);

public:
    Database();
    ~Database();

    void addViolation(const std::string& plate, const std::string& violationDetails);
    void printDatabase();
    void printDataByPlate(const std::string& plate);
    void printDataInRange(const std::string& start, const std::string& end);
};

#endif // DATABASE_H
