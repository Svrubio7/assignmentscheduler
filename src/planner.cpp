#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../include/Assignment.hpp"
#include "../include/json.hpp"
#include "../include/displayfunctions.hpp"
#include "../include/planner.hpp"

using json = nlohmann::json;
using namespace std;

// Load assignments from the user's JSON file
bool loadAssignments(const string& username, vector<SchoolWork::Assignment>& assignments) {
    string filePath = "Data/" + username + ".json";
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for user " << username << endl;
        return false;
    }

    json data;
    file >> data;

        // Error handling: Check if the JSON data is empty
    if (data.empty()) {
        cerr << "Error: No assignments found for user " << username << endl;
        return false;
    }


    for (const auto& item : data) {
        SchoolWork::Assignment assignment;
        assignment.setName(item["name"]);
        assignment.setCourse(item["course"]);
        assignment.setDeadline(item["deadline"]);
        assignment.setEstimatedHours(item["estimatedHours"]);
        assignment.setGradeWeight(item["gradeWeight"]);
        
        string sizeStr = item["size"];
        if (sizeStr == "Short") {
            assignment.setAssignmentSize(SchoolWork::AssignmentSize::SHORT);
        } else if (sizeStr == "Medium") {
            assignment.setAssignmentSize(SchoolWork::AssignmentSize::MEDIUM);
        } else if (sizeStr == "Long") {
            assignment.setAssignmentSize(SchoolWork::AssignmentSize::LONG);
        }



        assignments.push_back(assignment);
    }
    return true;
}

double calculatePriority(const SchoolWork::Assignment& assignment, const std::vector<SchoolWork::Assignment>& assignments) {
    double priority = 0.0;

    // Higher priority for closer deadlines and more remaining hours
    priority += 100.0 / (assignment.getDeadline() + 1);  // +1 to avoid division by zero
    priority += assignment.getEstimatedHours();

    return priority;
}

void planWorkWeek(std::vector<SchoolWork::Assignment>& assignments, int maxDailyHours) {
    int dayCounter = 1;

    // Continue planning until all assignments are done or deadlines have passed
    while (!assignments.empty()) {
        std::cout << "Day " << dayCounter << ":\n";
        int remainingHours = maxDailyHours;

        // Sort assignments based on recalculated priority (every day)
        std::sort(assignments.begin(), assignments.end(), [&](const SchoolWork::Assignment& a, const SchoolWork::Assignment& b) {
            return calculatePriority(a, assignments) > calculatePriority(b, assignments);  // Higher priority first
        });

        bool workDone = false;  // Track if any work was done during the day

        // Distribute available hours among all active assignments for the day
        while (remainingHours > 0 && !assignments.empty()) {
            // Select the assignment with the highest priority
            auto& highestPriorityAssignment = assignments.front();

            // Skip if the assignment is completed or missed its deadline
            if (highestPriorityAssignment.getEstimatedHours() <= 0 || highestPriorityAssignment.getDeadline() < dayCounter) {
                assignments.erase(assignments.begin());
                continue;
            }

            // Calculate hours to work per day for this assignment
            int daysLeftUntilDeadline = highestPriorityAssignment.getDeadline() - dayCounter + 1;
            int requiredDailyHours = std::max(1, highestPriorityAssignment.getEstimatedHours() / daysLeftUntilDeadline);

            // Allocate time to the assignment, making sure not to exceed the remaining hours for today
            int hoursToWork = std::min(remainingHours, requiredDailyHours);

            // Log the scheduled work
            for (int hour = 0; hour < hoursToWork; ++hour) {
                std::cout << "Hour " << (maxDailyHours - remainingHours + 1 + hour) << ": Work on " << highestPriorityAssignment.getName() << "\n";
            }

            // *** Ensure estimated hours are correctly reduced ***
            int remainingEstimatedHours = highestPriorityAssignment.getEstimatedHours();
            highestPriorityAssignment.setEstimatedHours(remainingEstimatedHours - hoursToWork);  // Reduce by hours worked

            remainingHours -= hoursToWork;
            workDone = true;  // Mark that some work was done today

            // Remove completed assignment from the list
            if (highestPriorityAssignment.getEstimatedHours() <= 0) {
                assignments.erase(assignments.begin());  // Remove completed assignments
            }
        }

        // Only decrement deadlines if work was done that day
        if (workDone) {
            for (auto& assignment : assignments) {
                assignment.setDeadline(assignment.getDeadline() - 1);
            }
        }

        // If no assignments were scheduled on this day
        if (!workDone) {
            std::cout << "No assignments scheduled for today.\n";
        }

        std::cout << "=============================\n";
        dayCounter++;  // Move to the next day
    }

    std::cout << "All assignments have been scheduled successfully.\n";
}

// Start the planner
void startPlanner() {
    string username;
    int maxDailyHours;

    cout << "Enter your name: ";
    cin >> username;
    cout << "Enter your maximum study hours per day: ";
    cin >> maxDailyHours;

    vector<SchoolWork::Assignment> assignments;

    // Load assignments from JSON and schedule them
    if (loadAssignments(username, assignments)) {
        displayAllAssignments(assignments); // Show loaded assignments (optional)
        planWorkWeek(assignments, maxDailyHours); // Plan assignments
    } else {
        cerr << "Error loading assignments for user " << username << endl;
    }
}

// Run the planner
void runPlanner() {
    startPlanner();
}
