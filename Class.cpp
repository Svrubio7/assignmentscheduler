#include <iostream>
#include <string>

class Assignment {
private:
    std::string name;
    std::string course;
    int deadline;  // Days from today
    int estimatedHours;  // Estimated time to complete the assignment

public:
    // Setters
    void setName(std::string name) {
        this->name = name;
    }

    void setCourse(std::string course) {
        this->course = course;
    }

    void setDeadline(int deadline) {
        this->deadline = deadline;
    }

    void setEstimatedHours(int estimatedHours) {
        this->estimatedHours = estimatedHours;
    }

    // Getters
    std::string getName() {
        return name;
    }

    std::string getCourse() {
        return course;
    }

    int getDeadline() {
        return deadline;
    }

    int getEstimatedHours() {
        return estimatedHours;
    }

    // Method to display assignment details
    void printDetails() {
        std::cout << "Assignment Name: " << name << ", Course: " << course 
                  << ", Due in: " << deadline << " days, Estimated Time: " 
                  << estimatedHours << " hours" << std::endl;
    }

    // Method to calculate the urgency of the assignment
    double calculateUrgency() {
        return static_cast<double>(estimatedHours) / deadline;
    }
};
