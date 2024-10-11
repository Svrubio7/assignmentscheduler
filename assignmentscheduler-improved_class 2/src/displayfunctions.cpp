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



