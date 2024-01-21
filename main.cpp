#include "database.h"

int main() {
    Database database;

    char choice;
    do {
        std::cout << "\n1. Add Violation\n";
        std::cout << "2. Print Database\n";
        std::cout << "3. Print Data by License Plate\n";
        std::cout << "4. Print Data in Range of License Plates\n";
        std::cout << "5. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case '1': {
            std::string plate, violationDetails;
            std::cout << "Enter license plate: ";
            std::getline(std::cin, plate);
            std::cout << "Enter violation details: ";
            std::getline(std::cin, violationDetails);
            database.addViolation(plate, violationDetails);
            break;
        }
        case '2':
            database.printDatabase();
            break;
        case '3': {
            std::string plate;
            std::cout << "Enter license plate: ";
            std::getline(std::cin, plate);
            database.printDataByPlate(plate);
            break;
        }
        case '4': {
            std::string start, end;
            std::cout << "Enter range of license plates (start): ";
            std::getline(std::cin, start);
            std::cout << "Enter range of license plates (end): ";
            std::getline(std::cin, end);
            database.printDataInRange(start, end);
            break;
        }
        case '5':
            std::cout << "Thank you for using! Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
