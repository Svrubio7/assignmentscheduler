// main.cpp

#include <iostream>
#include "Assignment.h"

int main() {
    // Create an Assignment object using the parameterized constructor
    SchoolWork::Assignment mathAssignment("Math Assignment", "Math 101", 5, 10, 25.0f, SchoolWork::AssignmentSize::MEDIUM);
    
    // Display the assignment details
    std::cout << "Displaying math assignment:\n";
    mathAssignment.display();
    
    // Modify the assignment using setters
    mathAssignment.setGradeWeight(30.0f);
    mathAssignment.setDeadline(3);
    mathAssignment.setAssignmentSize(SchoolWork::AssignmentSize::LONG);
    
    // Display the modified assignment
    std::cout << "\nDisplaying modified math assignment:\n";
    mathAssignment.display();
    
    // Create another Assignment object
    SchoolWork::Assignment scienceAssignment("Science Project", "Physics 201", 2, 15, 40.0f, SchoolWork::AssignmentSize::LONG);
    
    // Display the science assignment
    std::cout << "\nDisplaying science assignment:\n";
    scienceAssignment.display();
    
    // Compare the two assignments by deadline
    if (mathAssignment < scienceAssignment) {
        std::cout << "\nThe math assignment is due earlier than the science project.\n";
    } else {
        std::cout << "\nThe science project is due earlier than the math assignment.\n";
    }
    
    return 0;
}
