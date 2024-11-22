#include <gtest/gtest.h>
#include "../include/planner.hpp"
#include "../include/Assignment.hpp"
#include "../include/displayfunctions.hpp"
#include <fstream>
#include "../include/json.hpp"


using json = nlohmann::json;

//created a mock JSONFILE
void createMockJSONFile(const std::string& username, const nlohmann::json& data) {
    std::ofstream file("Data/" + username + ".json");
    file << data.dump(4);
    file.close();
}

// testing the loadAssignments function
TEST(PlannerTest, LoadAssignmentsEmptyFile) {
    // Empty Json File
    std::string username = "emptyUser";
    nlohmann::json data = nlohmann::json::array(); // empty array (no assignments)
    createMockJSONFile(username, data);

    std::vector<SchoolWork::Assignment> assignments;
    ASSERT_FALSE(loadAssignments(username, assignments));  // the output should be FALSE as there are no assgiments
}

// testing for loadAssignments with valid assignments
TEST(PlannerTest, LoadAssignmentsValidFile) {
    std::string username = "testUser";
    nlohmann::json data1 = nlohmann::json::array({
        {{"name", "Math Homework"}, {"course", "Math"}, {"deadline", 5}, {"estimatedHours", 10}, {"gradeWeight", 20.0}, {"size", "Medium"}},
        {{"name", "Science Project"}, {"course", "Science"}, {"deadline", 3}, {"estimatedHours", 8}, {"gradeWeight", 30.0}, {"size", "Long"}}
    });
    createMockJSONFile(username, data1);

    std::vector<SchoolWork::Assignment> assignments;
    ASSERT_TRUE(loadAssignments(username, assignments));  // should return TRUE
    ASSERT_EQ(assignments.size(), 2);  // two assigments loaded
}

// testing the priority calculation function
TEST(PlannerTest, CalculatePriorityTest) {
    // sample assigments
    SchoolWork::Assignment assignment1("Math", "Math", 5, 10, 20.0, SchoolWork::AssignmentSize::MEDIUM);
    SchoolWork::Assignment assignment2("Science", "Science", 2, 8, 30.0, SchoolWork::AssignmentSize::LONG);

    std::vector<SchoolWork::Assignment> assignments = {assignment1, assignment2};
    
    // testing priority calculation
    double priority1 = calculatePriority(assignment1, assignments);
    double priority2 = calculatePriority(assignment2, assignments);

    // THE OUTPUT SHOULD: assignment2 should have higher priority (shorter deadline) 
    ASSERT_GT(priority2, priority1);
}

// testing the planWorkWeek function (edge case)
TEST(PlannerTest, PlanWorkWeekEmptyAssignments) {
    std::vector<SchoolWork::Assignment> assignments;
    int maxDailyHours = 5;

    // Capture output
    testing::internal::CaptureStdout();
    planWorkWeek(assignments, maxDailyHours);
    std::string output = testing::internal::GetCapturedStdout();

    // expect output message for empty assignments
    ASSERT_NE(output.find("All assignments have been scheduled successfully."), std::string::npos);
}

// EDGE CASE: testing scheduling an assignment that is due in 5 months (approximately 150 days)
TEST(PlannerTest, PlanWorkWeekAssignmentDueIn5Months) {
    std::vector<SchoolWork::Assignment> assignments;

    // creating the assigment
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

    // grabs output
    testing::internal::CaptureStdout();
    planWorkWeek(assignments, maxDailyHours);
    std::string output = testing::internal::GetCapturedStdout();

    // checking if it is scheduling the assigment 
    ASSERT_NE(output.find("Long-Term Project"), std::string::npos);
    ASSERT_NE(output.find("Work on Long-Term Project"), std::string::npos);

    // verfting it has been schedueld 
    ASSERT_NE(output.find("All assignments have been scheduled successfully."), std::string::npos);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
