#ifndef ASSIGNMENTCREATOR_H
#define ASSIGNMENTCREATOR_H

#include <string>
#include <vector>
#include "Assignment.hpp"

// Function to add or delete assignments
// This function allows users to either add new assignments or delete existing ones
void createOrEditAssignment(const std::string& username);


// Function to delete an assignment from the list
void deleteAssignment(std::vector<SchoolWork::Assignment>& assignments, const std::string& username);


#endif // ASSIGNMENTCREATOR_H
