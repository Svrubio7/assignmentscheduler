#ifndef DISPLAYFUNCTIONS_H
#define DISPLAYFUNCTIONS_H

#include <vector>
#include "Assignment.hpp" // Ensure this includes the definition of the Assignment class

void displayAssignment(const SchoolWork::Assignment& assignment);
void displayAllAssignments(const std::vector<SchoolWork::Assignment>& assignments);
void displaySchedule(const std::vector<SchoolWork::Assignment>& assignments, int maxDailyHours); // Add int maxDailyHours here

#endif // DISPLAYFUNCTIONS_H
