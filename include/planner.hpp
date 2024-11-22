#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include <string>
#include "Assignment.hpp"

// Function to load assignments from a JSON file for a given user
bool loadAssignments(const std::string& username, std::vector<SchoolWork::Assignment>& assignments);

// Function to calculate the priority of assignments based on deadline, size, and grade weight
double calculatePriority(const SchoolWork::Assignment& assignment, const std::vector<SchoolWork::Assignment>& assignments);

// Function to plan the work schedule for the week
void planWorkWeek(std::vector<SchoolWork::Assignment>& assignments, int maxDailyHours);

// Function to start the planner
void startPlanner();

// Function to run the planner
void runPlanner();

#endif // PLANNER_H
