#include "gtest/gtest.h"
#include "../include/assignmentcreator.hpp"   // Adjust path based on your project structure
#include "../include/Assignment.hpp"          // Adjust path based on your project structure
#include "../include/json.hpp"                           // Ensure correct path to json.hpp
#include <vector>
#include <fstream>
#include <sstream>

using json = nlohmann::json;  // This should be added before using the `json` type

// Mock function to simulate user input for testing
void mockInput(std::stringstream& input, const std::string& addOrDelete, const std::string& name, const std::string& course, int deadline, int hours, float weight, int size, const std::string& addAnother) {
    input << addOrDelete << "\n" << name << "\n" << course << "\n" << deadline << "\n" << hours << "\n" << weight << "\n" << size << "\n" << addAnother << "\n";
}

// Test for creating an assignment (valid input case)
TEST(AssignmentCreatorTest, CreateAssignment) {
    // Setup mock input: 'a' for add, assignment details, and 'n' for no further additions
    std::string username = "testUser";
    std::stringstream input;
    mockInput(input, "a", "Math Homework", "Math", 5, 10, 20.0f, 2, "n");

    // Redirect cin to use our mock input
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());

    // Mock creating or editing assignment
    createOrEditAssignment(username);

    // Restore original cin
    std::cin.rdbuf(originalCin);

    // Check if the file was created
    std::ifstream file("Data/testUser.json");
    ASSERT_TRUE(file.is_open()) << "File should have been created";

    // Additional validation could include checking the contents of the file
    json jAssignments;
    file >> jAssignments;
    ASSERT_GT(jAssignments.size(), 0) << "At least one assignment should be saved";
    
    file.close();
}

// Test for creating an assignment (edge case - empty input)
TEST(AssignmentCreatorTest, CreateAssignment_EmptyInput) {
    // Setup mock input: 'a' for add, but no valid assignment details, and 'n' for no further additions
    std::string username = "testUserEmpty";
    std::stringstream input;
    mockInput(input, "a", "", "", 0, 0, 0.0f, 1, "n");

    // Redirect cin to use our mock input
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());

    // Mock creating or editing assignment
    createOrEditAssignment(username);

    // Restore original cin
    std::cin.rdbuf(originalCin);

    // Check if the file was created
    std::ifstream file("Data/testUserEmpty.json");
    ASSERT_TRUE(file.is_open()) << "File should have been created";

    // Check that the file is empty or doesn't have any saved assignments
    json jAssignments;
    file >> jAssignments;
    ASSERT_EQ(jAssignments.size(), 0) << "No assignments should be saved for empty input";
    
    file.close();
}
