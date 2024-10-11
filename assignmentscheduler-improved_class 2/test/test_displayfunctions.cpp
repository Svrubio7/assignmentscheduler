#include "gtest/gtest.h"
#include "../include/displayfunctions.hpp"
#include "../include/Assignment.hpp"
#include <vector>
#include <string>

// Test displaying a single assignment
TEST(DisplayFunctionsTest, DisplaySingleAssignment) {
    // Create a sample assignment
    SchoolWork::Assignment assignment("Math Homework", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM);
    
    // Capture the stdout
    testing::internal::CaptureStdout();
    
    // Call the function to display the assignment
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

// Test displaying all assignments
TEST(DisplayFunctionsTest, DisplayAllAssignments) {
    // Create some sample assignments
    std::vector<SchoolWork::Assignment> assignments = {
        SchoolWork::Assignment("Math Homework", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM),
        SchoolWork::Assignment("Science Project", "Science", 7, 15, 25.0, SchoolWork::AssignmentSize::LONG)
    };

    // Capture the stdout
    testing::internal::CaptureStdout();
    
    // Call the function to display all assignments
    displayAllAssignments(assignments);
    
    // Capture the output and compare it to the expected result
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

// Test displaying the schedule
TEST(DisplayFunctionsTest, DisplayScheduleTest) {
    // Create some sample assignments
    std::vector<SchoolWork::Assignment> assignments = {
        SchoolWork::Assignment("Math Homework", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM),
        SchoolWork::Assignment("Science Project", "Science", 7, 15, 25.0, SchoolWork::AssignmentSize::LONG)
    };

    // Capture the stdout
    testing::internal::CaptureStdout();
    
    // Call the function to display the schedule
    displaySchedule(assignments, 8);  // maxDailyHours = 8
    
    // Capture the output and compare it to the expected result
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = 
        "\nFinal Scheduled Assignments:\n"
        "Work on Math Homework for 10 hour(s). Deadline in 5 days.\n"
        "Work on Science Project for 15 hour(s). Deadline in 7 days.\n";

    EXPECT_EQ(output, expectedOutput);
}

// Edge Case: Test displaying an empty schedule
TEST(DisplayFunctionsTest, DisplayEmptyScheduleTest) {
    std::vector<SchoolWork::Assignment> assignments;  // Empty list

    // Capture the stdout
    testing::internal::CaptureStdout();

    // Call the function to display the schedule
    displaySchedule(assignments, 8);  // maxDailyHours = 8

    // Capture the output and compare it to the expected result
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "No assignments scheduled.\n";

    EXPECT_EQ(output, expectedOutput);
}
