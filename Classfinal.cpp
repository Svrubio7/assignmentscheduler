#include <iostream>
#include <string>

class Assignment {
private:
    std::string name;
    std::string course;
    int deadline;       // Days from today
    int estimatedHours; // Estimated time to complete the assignment

public:
    // Constructor
    Assignment(const std::string& name, const std::string& course, int deadline, int estimatedHours)
        : name(name), course(course), deadline(deadline), estimatedHours(estimatedHours) {}

    // Copy Constructor
    Assignment(const Assignment& other)
        : name(other.name), course(other.course), deadline(other.deadline), estimatedHours(other.estimatedHours) {
        std::cout << "Copy constructor called\n";
    }

    // Copy Assignment Operator
    Assignment& operator=(const Assignment& other) {
        std::cout << "Copy assignment operator called\n";
        if (this != &other) { // Prevent self-assignment
            name = other.name;
            course = other.course;
            deadline = other.deadline;
            estimatedHours = other.estimatedHours;
        }
        return *this;
    }

    // Move Constructor
    Assignment(Assignment&& other) noexcept
        : name(std::move(other.name)), course(std::move(other.course)), deadline(other.deadline), estimatedHours(other.estimatedHours) {
        std::cout << "Move constructor called\n";
        other.deadline = 0;
        other.estimatedHours = 0;
    }

    // Move Assignment Operator
    Assignment& operator=(Assignment&& other) noexcept {
        std::cout << "Move assignment operator called\n";
        if (this != &other) {
            name = std::move(other.name);
            course = std::move(other.course);
            deadline = other.deadline;
            estimatedHours = other.estimatedHours;

            // Nullify the moved-from object's state
            other.deadline = 0;
            other.estimatedHours = 0;
        }
        return *this;
    }

    // Getters
    std::string getName() const { return name; }

    std::string getCourse() const { return course; }

    int getDeadline() const { return deadline; }

    int getEstimatedHours() const { return estimatedHours; }

    // Setters
    void setName(const std::string& name) { this->name = name; }

    void setCourse(const std::string& course) { this->course = course; }

    void setDeadline(int deadline) { this->deadline = deadline; }

    void setEstimatedHours(int estimatedHours) { this->estimatedHours = estimatedHours; }

    
    void display() const {
        std::cout << "Assignment: " << name << "\nCourse: " << course
                  << "\nDeadline (days): " << deadline
                  << "\nEstimated hours: " << estimatedHours << std::endl;
    }

};




