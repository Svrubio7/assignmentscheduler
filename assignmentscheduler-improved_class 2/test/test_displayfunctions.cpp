#include "gtest/gtest.h"
#include "../include/displayfunctions.hpp"
#include "../include/Assignment.hpp"
#include <vector>
#include <string>

// displaying a single assignment
TEST(DisplayFunctionsTest, DisplaySingleAssignment) {
    //  sample assignment
    SchoolWork::Assignment assignment("Math Homework", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM);
    
 
    testing::internal::CaptureStdout();
    
    // function to display the assignment
    displayAssignment(assignment);
    
    // Capture the output and compare it to the expected result
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = 
        "Assignment: Math Homework\n"
        "Course: Math\n"
        "Deadline (days): 5\n"
        "Estimated hours: 10\n"
        "Grade Weight: 20%\n"
        "Size: Medium\n"
        "-------------------------\n";
    
    EXPECT_EQ(output, expectedOutput);
}

// displaying all assignments
TEST(DisplayFunctionsTest, DisplayAllAssignments) {
    // sample assignments
    std::vector<SchoolWork::Assignment> assignments = {
        SchoolWork::Assignment("Math Homework", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM),
        SchoolWork::Assignment("Science Project", "Science", 7, 15, 25.0, SchoolWork::AssignmentSize::LONG)
    };


    testing::internal::CaptureStdout();
    
    //  function to display all assignments
    displayAllAssignments(assignments);
    
    
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = 
        "Current Assignments:\n"
        "Assignment: Math Homework\n"
        "Course: Math\n"
        "Deadline (days): 5\n"
        "Estimated hours: 10\n"
        "Grade Weight: 20%\n"
        "Size: Medium\n"
        "-------------------------\n"
        "Assignment: Science Project\n"
        "Course: Science\n"
        "Deadline (days): 7\n"
        "Estimated hours: 15\n"
        "Grade Weight: 25%\n"
        "Size: Long\n"
        "-------------------------\n";

    EXPECT_EQ(output, expectedOutput);
}


