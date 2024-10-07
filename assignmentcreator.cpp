//File dedicated to create all of the assignments for the planner 
//Creates an array of assignments and returns it to the planner   

#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "Assignment.h"
#include "json.hpp"  // Include nlohmann/json library

using json = nlohmann::json;
namespace fs = std::filesystem;

// Function to trim leading/trailing whitespaces from the string
std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(" \n\r\t");
    auto end = str.find_last_not_of(" \n\r\t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Function to delete an assignment by selection
void deleteAssignment(json& jAssignments) {
    if (jAssignments.empty()) {
        std::cout << "No assignments found to delete.\n";
        return;
    }

    // Display assignments
    std::cout << "Assignments:\n";
    for (size_t i = 0; i < jAssignments.size(); ++i) {
        std::cout << i + 1 << ". " << jAssignments[i]["name"] << "\n";
    }

    // Ask the user which assignment to delete
    int choice;
    std::cout << "Enter the number of the assignment you want to delete: ";
    std::cin >> choice;

    // Validate the choice
    if (choice > 0 && choice <= static_cast<int>(jAssignments.size())) {
        std::string assignmentName = jAssignments[choice - 1]["name"];
        jAssignments.erase(jAssignments.begin() + (choice - 1));
        std::cout << "Assignment '" << assignmentName << "' deleted.\n";
    } else {
        std::cout << "Invalid selection.\n";
    }
}

void createOrEditAssignment(const std::string& username) {
    std::vector<SchoolWork::Assignment> assignments;
    json jAssignments;

    // File path for storing the JSON
    const std::string filePath = "Data/" + username + ".json";

    // Load existing assignments if file exists
    if (fs::exists(filePath)) {
        std::ifstream existingFile(filePath);
        if (existingFile.is_open()) {
            try {
                existingFile >> jAssignments;  // Read existing JSON content
            } catch (const std::exception& e) {
                std::cerr << "Error reading JSON file: " << e.what() << "\n";
            }
            existingFile.close();
        } else {
            std::cerr << "Error opening existing file for reading.\n";
        }
    }

    char operationChoice;
    std::cout << "Do you want to add or delete assignments? (a/d): ";
    std::cin >> operationChoice;

    if (operationChoice == 'd' || operationChoice == 'D') {
        deleteAssignment(jAssignments);
    } else {
        // Adding new assignments
        bool addAnother = true;
        while (addAnother) {
            std::string name, course;
            int deadline, estimatedHours;
            float gradeWeight;
            int sizeInput;
            SchoolWork::AssignmentSize size;

            // Collect assignment data
            std::cin.ignore();  // Clear the input buffer

            std::cout << "Enter the name of the assignment: ";
            std::getline(std::cin, name);

            std::cout << "Enter the course: ";
            std::getline(std::cin, course);

            std::cout << "Enter the deadline (in days from today): ";
            std::cin >> deadline;

            std::cout << "Enter the estimated hours to complete the assignment: ";
            std::cin >> estimatedHours;

            std::cout << "Enter the grade weight (in percentage): ";
            std::cin >> gradeWeight;

            std::cout << "Enter the size of the assignment (1 = Short, 2 = Medium, 3 = Long): ";
            std::cin >> sizeInput;

            switch (sizeInput) {
                case 1:
                    size = SchoolWork::AssignmentSize::SHORT;
                    break;
                case 2:
                    size = SchoolWork::AssignmentSize::MEDIUM;
                    break;
                case 3:
                    size = SchoolWork::AssignmentSize::LONG;
                    break;
                default:
                    size = SchoolWork::AssignmentSize::MEDIUM;
                    std::cout << "Invalid input, defaulting to Medium.\n";
            }

            // Create a new assignment and add to the list
            SchoolWork::Assignment assignment(name, course, deadline, estimatedHours, gradeWeight, size);

            // Convert assignment to JSON
            json j;
            j["name"] = assignment.getName();
            j["course"] = assignment.getCourse();
            j["deadline"] = assignment.getDeadline();
            j["estimatedHours"] = assignment.getEstimatedHours();
            j["gradeWeight"] = assignment.getGradeWeight();

            switch (assignment.getAssignmentSize()) {
                case SchoolWork::AssignmentSize::SHORT:
                    j["size"] = "Short";
                    break;
                case SchoolWork::AssignmentSize::MEDIUM:
                    j["size"] = "Medium";
                    break;
                case SchoolWork::AssignmentSize::LONG:
                    j["size"] = "Long";
                    break;
            }

            // Add the new assignment to the list of assignments
            jAssignments.push_back(j);

            // Ask if the user wants to add another assignment
            char choice;
            std::cout << "Do you want to add another assignment? (y/n): ";
            std::cin >> choice;

            if (choice == 'n' || choice == 'N') {
                addAnother = false;
            }
        }
    }

    // Create a directory called Data if it doesn't exist
    if (!fs::exists("Data")) {
        fs::create_directory("Data");
    }

    // Save the assignments to the JSON file named after the user
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << jAssignments.dump(4);  // Pretty print with an indentation of 4 spaces
        file.close();
        std::cout << "Assignments saved to " << filePath << std::endl;
    } else {
        std::cerr << "Error creating file!" << std::endl;
    }
}

int main() {
    std::string username;

    // Get the user's name
    std::cout << "Enter your name: ";
    std::getline(std::cin, username);

    // Trim whitespace from the username
    username = trim(username);

    // Call the function to create or edit assignments for the user
    createOrEditAssignment(username);

    return 0;
}
