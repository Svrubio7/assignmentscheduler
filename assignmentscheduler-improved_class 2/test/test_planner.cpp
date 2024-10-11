#include <gtest/gtest.h>
#include "planner.hpp"
#include "../include/Assignment.hpp"
#include "../include/displayfunctions.hpp"
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

// Mock data creation for the test cases
void createMockJSONFile(const std::string& username, const nlohmann::json& data) {
    std::ofstream file("Data/" + username + ".json");
    file << data.dump(4);
    file.close();
}

// Test loadAssignments function
TEST(PlannerTest, LoadAssignmentsEmptyFile) {
    // Create empty JSON file for testing
    std::string username = "emptyUser";
    nlohmann::json data = nlohmann::json::array(); // Empty array (no assignments)
    createMockJSONFile(username, data);

    std::vector<SchoolWork::Assignment> assignments;
    ASSERT_FALSE(loadAssignments(username, assignments));  // Should return false for empty data
}

// Test loadAssignments with valid assignments
TEST(PlannerTest, LoadAssignmentsValidFile) {
    std::string username = "testUser";
    nlohmann::json data1 = nlohmann::json::array({
        {{"name", "Math Homework"}, {"course", "Math"}, {"deadline", 5}, {"estimatedHours", 10}, {"gradeWeight", 20.0}, {"size", "Medium"}},
        {{"name", "Science Project"}, {"course", "Science"}, {"deadline", 3}, {"estimatedHours", 8}, {"gradeWeight", 30.0}, {"size", "Long"}}
    });
    createMockJSONFile(username, data1);

    std::vector<SchoolWork::Assignment> assignments;
    ASSERT_TRUE(loadAssignments(username, assignments));  // Should return true for valid data
    ASSERT_EQ(assignments.size(), 2);  // Two assignments should be loaded
}

// Test priority calculation function
TEST(PlannerTest, CalculatePriorityTest) {
    // Create sample assignments
    SchoolWork::Assignment assignment1("Math", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM);
    SchoolWork::Assignment assignment2("Science", "Science", 2, 8, 30.0, SchoolWork::AssignmentSize::LONG);

    std::vector<SchoolWork::Assignment> assignments = {assignment1, assignment2};
    
    // Test priority calculation
    double priority1 = calculatePriority(assignment1, assignments);
    double priority2 = calculatePriority(assignment2, assignments);

    // Expect assignment2 to have higher priority because of a shorter deadline
    ASSERT_GT(priority2, priority1);
}

// Test the planWorkWeek function (edge case)
TEST(PlannerTest, PlanWorkWeekEmptyAssignments) {
    std::vector<SchoolWork::Assignment> assignments;
    int maxDailyHours = 5;

    // Capture output
    testing::internal::CaptureStdout();
    planWorkWeek(assignments, maxDailyHours);
    std::string output = testing::internal::GetCapturedStdout();

    // Expect output message for empty assignments
    ASSERT_NE(output.find("All assignments have been scheduled successfully."), std::string::npos);
}

// Test scheduling an assignment that is due in 5 months (approximately 150 days)
TEST(PlannerTest, PlanWorkWeekAssignmentDueIn5Months) {
    std::vector<SchoolWork::Assignment> assignments;

    // Create an assignment that is due in 150 days (5 months)
    SchoolWork::Assignment assignment(
        "Long-Term Project",   // name
        "Software Engineering", // course
        150,                   // deadline in days
        100,                   // estimated hours
        50.0f,                 // grade weight
        SchoolWork::AssignmentSize::LONG // size
    );
    assignments.push_back(assignment);

    int maxDailyHours = 5;

    // Capture output
    testing::internal::CaptureStdout();
    planWorkWeek(assignments, maxDailyHours);
    std::string output = testing::internal::GetCapturedStdout();

    // Verify that the assignment is scheduled properly (this is an example of how the output can be checked)
    ASSERT_NE(output.find("Long-Term Project"), std::string::npos);
    ASSERT_NE(output.find("Work on Long-Term Project"), std::string::npos);

    // Verify that the scheduling is completed
    ASSERT_NE(output.find("All assignments have been scheduled successfully."), std::string::npos);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
