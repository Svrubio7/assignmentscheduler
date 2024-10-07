// Assignment.h

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>

namespace SchoolWork {

    // Enum to represent the size of the assignment
    enum class AssignmentSize {
        SHORT,
        MEDIUM,
        LONG
    };

    class Assignment {
    private:
        std::string name;
        std::string course;
        int deadline;                    // Days from today (integer value)
        int estimatedHours;              // Estimated time to complete the assignment
        float gradeWeight;               // Weight of the assignment in percentages (0 - 100)
        AssignmentSize size;             // Size of the assignment: SHORT, MEDIUM, or LONG

    public:
        // Default Constructor
        Assignment();

        // Parameterized Constructor
        Assignment(const std::string& name, const std::string& course, int deadlineDays, int estimatedHours,
                   float gradeWeight, AssignmentSize size);

        // Copy Constructor
        Assignment(const Assignment& other);

        // Copy Assignment Operator
        Assignment& operator=(const Assignment& other);

        // Move Constructor
        Assignment(Assignment&& other) noexcept;

        // Move Assignment Operator
        Assignment& operator=(Assignment&& other) noexcept;

        // Destructor
        ~Assignment();

        // Getters
        std::string getName() const;
        std::string getCourse() const;
        int getDeadline() const;
        int getEstimatedHours() const;
        float getGradeWeight() const;
        AssignmentSize getAssignmentSize() const;

        // Setters
        void setName(const std::string& name);
        void setCourse(const std::string& course);
        void setDeadline(int deadlineDays);
        void setEstimatedHours(int estimatedHours);
        void setGradeWeight(float gradeWeight);
        void setAssignmentSize(AssignmentSize size);

        // Display method
        void display() const;

        // Comparison operators
        bool operator==(const Assignment& other) const;
        bool operator<(const Assignment& other) const;

    private:
        // Helper method to convert the AssignmentSize enum to a string for display purposes
        std::string getSizeAsString() const;
    };

}  // namespace SchoolWork

#endif // ASSIGNMENT_H
