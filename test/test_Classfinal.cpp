#include <gtest/gtest.h>
#include "../include/Assignment.hpp"  // Adjust this path as necessary

// Test Default Constructor
TEST(AssignmentTest, DefaultConstructor) {
    SchoolWork::Assignment assignment;
    EXPECT_EQ(assignment.getName(), "");
    EXPECT_EQ(assignment.getCourse(), "");
    EXPECT_EQ(assignment.getDeadline(), 0);
    EXPECT_EQ(assignment.getEstimatedHours(), 0);
    EXPECT_FLOAT_EQ(assignment.getGradeWeight(), 0.0f);
    EXPECT_EQ(assignment.getAssignmentSize(), SchoolWork::AssignmentSize::MEDIUM);
}

// Test Parameterized Constructor
TEST(AssignmentTest, ParameterizedConstructor) {
    SchoolWork::Assignment assignment("Math Homework", "Math", 5, 10, 20.0f, SchoolWork::AssignmentSize::LONG);
    EXPECT_EQ(assignment.getName(), "Math Homework");
    EXPECT_EQ(assignment.getCourse(), "Math");
    EXPECT_EQ(assignment.getDeadline(), 5);
    EXPECT_EQ(assignment.getEstimatedHours(), 10);
    EXPECT_FLOAT_EQ(assignment.getGradeWeight(), 20.0f);
    EXPECT_EQ(assignment.getAssignmentSize(), SchoolWork::AssignmentSize::LONG);
}

// Test Copy Constructor
TEST(AssignmentTest, CopyConstructor) {
    SchoolWork::Assignment assignment1("English Essay", "English", 3, 8, 30.0f, SchoolWork::AssignmentSize::SHORT);
    SchoolWork::Assignment assignment2 = assignment1;  // Copy constructor
    EXPECT_EQ(assignment2.getName(), "English Essay");
    EXPECT_EQ(assignment2.getCourse(), "English");
    EXPECT_EQ(assignment2.getDeadline(), 3);
    EXPECT_EQ(assignment2.getEstimatedHours(), 8);
    EXPECT_FLOAT_EQ(assignment2.getGradeWeight(), 30.0f);
    EXPECT_EQ(assignment2.getAssignmentSize(), SchoolWork::AssignmentSize::SHORT);
}

// Test Copy Assignment Operator
TEST(AssignmentTest, CopyAssignmentOperator) {
    SchoolWork::Assignment assignment1("History Project", "History", 4, 12, 40.0f, SchoolWork::AssignmentSize::MEDIUM);
    SchoolWork::Assignment assignment2;
    assignment2 = assignment1;  // Copy assignment operator
    EXPECT_EQ(assignment2.getName(), "History Project");
    EXPECT_EQ(assignment2.getCourse(), "History");
    EXPECT_EQ(assignment2.getDeadline(), 4);
    EXPECT_EQ(assignment2.getEstimatedHours(), 12);
    EXPECT_FLOAT_EQ(assignment2.getGradeWeight(), 40.0f);
    EXPECT_EQ(assignment2.getAssignmentSize(), SchoolWork::AssignmentSize::MEDIUM);
}

// Test Move Constructor
TEST(AssignmentTest, MoveConstructor) {
    SchoolWork::Assignment assignment1("Science Lab", "Science", 6, 15, 25.0f, SchoolWork::AssignmentSize::LONG);
    SchoolWork::Assignment assignment2 = std::move(assignment1);  // Move constructor
    EXPECT_EQ(assignment2.getName(), "Science Lab");
    EXPECT_EQ(assignment2.getCourse(), "Science");
    EXPECT_EQ(assignment2.getDeadline(), 6);
    EXPECT_EQ(assignment2.getEstimatedHours(), 15);
    EXPECT_FLOAT_EQ(assignment2.getGradeWeight(), 25.0f);
    EXPECT_EQ(assignment2.getAssignmentSize(), SchoolWork::AssignmentSize::LONG);
    EXPECT_EQ(assignment1.getEstimatedHours(), 0);  // Ensure moved-from object is reset
}

// Test Move Assignment Operator
TEST(AssignmentTest, MoveAssignmentOperator) {
    SchoolWork::Assignment assignment1("Physics Assignment", "Physics", 7, 20, 35.0f, SchoolWork::AssignmentSize::MEDIUM);
    SchoolWork::Assignment assignment2;
    assignment2 = std::move(assignment1);  // Move assignment operator
    EXPECT_EQ(assignment2.getName(), "Physics Assignment");
    EXPECT_EQ(assignment2.getCourse(), "Physics");
    EXPECT_EQ(assignment2.getDeadline(), 7);
    EXPECT_EQ(assignment2.getEstimatedHours(), 20);
    EXPECT_FLOAT_EQ(assignment2.getGradeWeight(), 35.0f);
    EXPECT_EQ(assignment2.getAssignmentSize(), SchoolWork::AssignmentSize::MEDIUM);
    EXPECT_EQ(assignment1.getEstimatedHours(), 0);  // Ensure moved-from object is reset
}

// Test Setters with Validation (Edge Case Testing)
TEST(AssignmentTest, SettersWithValidation) {
    SchoolWork::Assignment assignment;
    assignment.setName("Chemistry Homework");
    assignment.setCourse("Chemistry");
    assignment.setDeadline(10);
    assignment.setEstimatedHours(5);
    assignment.setGradeWeight(50.0f);
    assignment.setAssignmentSize(SchoolWork::AssignmentSize::SHORT);

    EXPECT_EQ(assignment.getName(), "Chemistry Homework");
    EXPECT_EQ(assignment.getCourse(), "Chemistry");
    EXPECT_EQ(assignment.getDeadline(), 10);
    EXPECT_EQ(assignment.getEstimatedHours(), 5);
    EXPECT_FLOAT_EQ(assignment.getGradeWeight(), 50.0f);
    EXPECT_EQ(assignment.getAssignmentSize(), SchoolWork::AssignmentSize::SHORT);

    // Edge cases for negative values
    assignment.setDeadline(-1);  // Invalid, should not change
    EXPECT_EQ(assignment.getDeadline(), 10);  // No change expected

    assignment.setEstimatedHours(-5);  // Invalid, should not change
    EXPECT_EQ(assignment.getEstimatedHours(), 5);  // No change expected

    assignment.setGradeWeight(150.0f);  // Invalid, should not change
    EXPECT_FLOAT_EQ(assignment.getGradeWeight(), 50.0f);  // No change expected
}

// Test Comparison Operators
TEST(AssignmentTest, ComparisonOperators) {
    SchoolWork::Assignment assignment1("Math Homework", "Math", 5, 10, 20.0f, SchoolWork::AssignmentSize::LONG);
    SchoolWork::Assignment assignment2("History Project", "History", 3, 12, 40.0f, SchoolWork::AssignmentSize::MEDIUM);
    EXPECT_FALSE(assignment1 == assignment2);
    EXPECT_TRUE(assignment2 < assignment1);  // Earlier deadline
}
