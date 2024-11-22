#include <iostream>
#include <vector>
#include <string>
#include "../include/Assignment.hpp"
#include "../include/assignmentcreator.hpp"  // For managing assignments
#include "../include/planner.hpp"            // For planning the workweek
#include "../include/displayfunctions.hpp"   // For displaying assignments

int main() {
    std::string username;
    std::vector<SchoolWork::Assignment> assignments;

    // 1. Ask the user for their name and load existing assignments if any
    std::cout << "Enter your name: ";
    std::cin >> username;

    if (!loadAssignments(username, assignments)) {
        std::cout << "No existing data found for user " << username << ". A new file will be created." << std::endl;
    }

    // 2. Ask if the user wants to modify the assignment list
    char modifyList;
    std::cout << "Do you want to modify the assignment list? (y/n): ";
    std::cin >> modifyList;

    if (modifyList == 'y' || modifyList == 'Y') {
        createOrEditAssignment(username);  // Call the function to modify the assignments if the user chooses 'y'
    }

    // 3. Display all assignments after possible modifications
    displayAllAssignments(assignments);

    // 4. Plan the workweek based on the assignments
    int maxDailyHours;
    std::cout << "Enter your maximum study hours per day: ";
    std::cin >> maxDailyHours;

    planWorkWeek(assignments, maxDailyHours);  // Plan the workweek
    displaySchedule(assignments, maxDailyHours);  // Display final schedule

    return 0;
}
