#include <iostream>
#include <vector>
#include "displayfunctions.hpp"  
#include "Assignment.hpp"        

using namespace std;


void displayAssignment(const SchoolWork::Assignment& assignment) {
    cout << "Assignment: " << assignment.getName() << "\n"
         << "Course: " << assignment.getCourse() << "\n"
         << "Deadline (days): " << assignment.getDeadline() << "\n"
         << "Estimated hours: " << assignment.getEstimatedHours() << "\n"
         << "Grade Weight: " << assignment.getGradeWeight() << "%\n"
         << "Size: " 
         << (assignment.getAssignmentSize() == SchoolWork::AssignmentSize::SHORT ? "Short" :
             assignment.getAssignmentSize() == SchoolWork::AssignmentSize::MEDIUM ? "Medium" : "Long") 
         << "\n-------------------------\n";
}


void displayAllAssignments(const vector<SchoolWork::Assignment>& assignments) {
    cout << "Current Assignments:\n";
    for (const auto& assignment : assignments) {
        displayAssignment(assignment);
    }
}


void displaySchedule(const vector<SchoolWork::Assignment>& assignments, int maxDailyHours) { 
    if (assignments.empty()) {
        cout << "No assignments scheduled.\n";
        return;
    }

    cout << "\nFinal Scheduled Assignments:\n";
    for (const auto& assignment : assignments) {
        cout << "Work on " << assignment.getName() << " for " 
             << assignment.getEstimatedHours() << " hour(s). Deadline in " 
             << assignment.getDeadline() << " days.\n";
    }
}
