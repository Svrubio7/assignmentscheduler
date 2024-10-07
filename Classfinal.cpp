// Classfinal.cpp

#include "Assignment.h"

namespace SchoolWork {

    // Default Constructor
    Assignment::Assignment() : name(""), course(""), deadline(0), estimatedHours(0),
                               gradeWeight(0), size(AssignmentSize::MEDIUM) {}

    // Parameterized Constructor
    Assignment::Assignment(const std::string& name, const std::string& course, int deadlineDays, int estimatedHours,
                           float gradeWeight, AssignmentSize size)
        : name(name), course(course), deadline(deadlineDays), estimatedHours(estimatedHours),
          gradeWeight(gradeWeight), size(size) {}

    // Copy Constructor
    Assignment::Assignment(const Assignment& other)
        : name(other.name), course(other.course), deadline(other.deadline), estimatedHours(other.estimatedHours),
          gradeWeight(other.gradeWeight), size(other.size) {
        std::cout << "Copy constructor called\n";
    }

    // Copy Assignment Operator
    Assignment& Assignment::operator=(const Assignment& other) {
        std::cout << "Copy assignment operator called\n";
        if (this != &other) {
            name = other.name;
            course = other.course;
            deadline = other.deadline;
            estimatedHours = other.estimatedHours;
            gradeWeight = other.gradeWeight;
            size = other.size;
        }
        return *this;
    }

    // Move Constructor
    Assignment::Assignment(Assignment&& other) noexcept
        : name(std::move(other.name)), course(std::move(other.course)),
          deadline(other.deadline), estimatedHours(other.estimatedHours),
          gradeWeight(other.gradeWeight), size(other.size) {
        std::cout << "Move constructor called\n";
        other.estimatedHours = 0;
        other.gradeWeight = 0;
    }

    // Move Assignment Operator
    Assignment& Assignment::operator=(Assignment&& other) noexcept {
        std::cout << "Move assignment operator called\n";
        if (this != &other) {
            name = std::move(other.name);
            course = std::move(other.course);
            deadline = other.deadline;
            estimatedHours = other.estimatedHours;
            gradeWeight = other.gradeWeight;
            size = other.size;

            other.estimatedHours = 0;
            other.gradeWeight = 0;
        }
        return *this;
    }

    // Destructor
    Assignment::~Assignment() = default;

    // Getters
    std::string Assignment::getName() const { return name; }
    std::string Assignment::getCourse() const { return course; }
    int Assignment::getDeadline() const { return deadline; }
    int Assignment::getEstimatedHours() const { return estimatedHours; }
    float Assignment::getGradeWeight() const { return gradeWeight; }
    AssignmentSize Assignment::getAssignmentSize() const { return size; }

    // Setters with validation
    void Assignment::setName(const std::string& name) { this->name = name; }
    void Assignment::setCourse(const std::string& course) { this->course = course; }
    void Assignment::setDeadline(int deadlineDays) {
        if (deadlineDays < 0) {
            std::cerr << "Deadline can't be negative.\n";
            return;
        }
        this->deadline = deadlineDays;
    }

    void Assignment::setEstimatedHours(int estimatedHours) {
        if (estimatedHours < 0) {
            std::cerr << "Estimated hours can't be negative.\n";
            return;
        }
        this->estimatedHours = estimatedHours;
    }

    void Assignment::setGradeWeight(float gradeWeight) {
        if (gradeWeight < 0.0f || gradeWeight > 100.0f) {
            std::cerr << "Grade weight must be between 0 and 100.\n";
            return;
        }
        this->gradeWeight = gradeWeight;
    }

    void Assignment::setAssignmentSize(AssignmentSize size) { this->size = size; }

    // Display method
    void Assignment::display() const {
        std::cout << "Assignment: " << name << "\nCourse: " << course
                  << "\nDeadline (days): " << deadline
                  << "\nEstimated hours: " << estimatedHours
                  << "\nGrade Weight: " << gradeWeight << "%"
                  << "\nSize: " << getSizeAsString() << std::endl;
    }

    // Comparison operators
    bool Assignment::operator==(const Assignment& other) const {
        return name == other.name && course == other.course &&
               deadline == other.deadline && estimatedHours == other.estimatedHours &&
               gradeWeight == other.gradeWeight && size == other.size;
    }

    bool Assignment::operator<(const Assignment& other) const {
        return deadline < other.deadline;
    }

    // Helper method to convert the AssignmentSize enum to a string for display purposes
    std::string Assignment::getSizeAsString() const {
        switch (size) {
            case AssignmentSize::SHORT: return "Short";
            case AssignmentSize::MEDIUM: return "Medium";
            case AssignmentSize::LONG: return "Long";
            default: return "Unknown";
        }
    }

}  // namespace SchoolWork
