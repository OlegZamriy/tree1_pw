#include "database.h"

Database::Database() : root(nullptr) {}

Database::~Database() {
}

void Database::insert(Node*& node, const std::string& plate, const std::string& violationDetails) {
    if (node == nullptr) {
        node = new Node(plate);
        node->violations.push_back(TrafficViolation(violationDetails));
    }
    else if (plate < node->licensePlate) {
        insert(node->left, plate, violationDetails);
    }
    else if (plate > node->licensePlate) {
        insert(node->right, plate, violationDetails);
    }
    else {
        node->violations.push_back(TrafficViolation(violationDetails));
    }
}

void Database::print(Node* node) {
    if (node != nullptr) {
        print(node->left);
        std::cout << "License Plate: " << node->licensePlate << "\n";
        for (const auto& violation : node->violations) {
            std::cout << "Violation: " << violation.violationDetails << "\n";
        }
        print(node->right);
    }
}

Node* Database::search(Node* node, const std::string& plate) {
    if (node == nullptr || node->licensePlate == plate) {
        return node;
    }

    if (plate < node->licensePlate) {
        return search(node->left, plate);
    }

    return search(node->right, plate);
}

void Database::printRange(Node* node, const std::string& start, const std::string& end) {
    if (node != nullptr) {
        if (start < node->licensePlate) {
            printRange(node->left, start, end);
        }

        if (start <= node->licensePlate && end >= node->licensePlate) {
            std::cout << "License Plate: " << node->licensePlate << "\n";
            for (const auto& violation : node->violations) {
                std::cout << "Violation: " << violation.violationDetails << "\n";
            }
        }

        if (end > node->licensePlate) {
            printRange(node->right, start, end);
        }
    }
}

void Database::addViolation(const std::string& plate, const std::string& violationDetails) {
    insert(root, plate, violationDetails);
}

void Database::printDatabase() {
    if (root == nullptr) {
        std::cout << "The database is empty.\n";
    }
    else {
        std::cout << "Printing the database:\n";
        print(root);
    }
}

void Database::printDataByPlate(const std::string& plate) {
    Node* result = search(root, plate);
    if (result != nullptr) {
        std::cout << "Data for license plate " << plate << ":\n";
        for (const auto& violation : result->violations) {
            std::cout << "Violation: " << violation.violationDetails << "\n";
        }
    }
    else {
        std::cout << "License plate " << plate << " not found in the database.\n";
    }
}

void Database::printDataInRange(const std::string& start, const std::string& end) {
    if (root == nullptr) {
        std::cout << "The database is empty.\n";
    }
    else {
        std::cout << "Printing data within the range of license plates (" << start << " - " << end << "):\n";
        printRange(root, start, end);
    }
}
