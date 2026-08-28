#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

// Represents an individual student and their academic records
class Student {
private:
    std::string name;
    int id;
    std::vector<double> grades;

public:
    // Constructor with basic parameter validation
    Student(const std::string& studentName, int studentID)
        : name(studentName), id(studentID) {
        if (studentID <= 0) {
            throw std::invalid_argument("Student ID must be a positive integer.");
        }
        if (studentName.empty()) {
            throw std::invalid_argument("Student name cannot be empty.");
        }
    }

    // Getters marked const (they do not modify member variables)
    std::string getName() const { return name; }
    int getId() const { return id; }

    // Adds a grade to the list after validating value bounds (0.0 to 100.0)
    void addGrade(double grade) {
        if (grade < 0.0 || grade > 100.0) {
            throw std::out_of_range("Grade must be between 0.0 and 100.0.");
        }
        grades.push_back(grade);
    }

    // Calculates GPA/average grade safely without risk of division-by-zero
    double calculateGPA() const {
        if (grades.empty()) {
            return 0.0;
        }
        double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
        return sum / grades.size();
    }

    // Displays individual student information
    void displayInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << " | GPA: " 
                  << std::fixed << std::setprecision(2) << calculateGPA() 
                  << " | Total Grades Entered: " << grades.size() << "\n";
    }
};

// Manages a collection of Student objects
class StudentManager {
private:
    std::vector<Student> students;

public:
    // Adds a new student while checking for duplicate IDs
    void addStudent(const Student& student) {
        for (const auto& s : students) {
            if (s.getId() == student.getId()) {
                throw std::invalid_argument("Student with ID " + std::to_string(student.getId()) + " already exists.");
            }
        }
        students.push_back(student);
    }

    // Finds a student by ID; returns a pointer to allow modification (like adding grades)
    Student* findStudent(int id) {
        for (auto& s : students) {
            if (s.getId() == id) {
                return &s;
            }
        }
        return nullptr; // Return nullptr if no student matches
    }

    // Displays details for all managed students
    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "No students registered in the system.\n";
            return;
        }
        std::cout << "--- Registered Students ---\n";
        for (const auto& student : students) {
            student.displayInfo();
        }
        std::cout << "---------------------------\n";
    }
};

int main() {
    std::cout << "=================================\n";
    std::cout << "   Student Management System     \n";
    std::cout << "=================================\n\n";

    try {
        StudentManager manager;

        // 1. Create and add students
        Student s1("Alice Smith", 101);
        Student s2("Bob Jones", 102);
        Student s3("Charlie Brown", 103);

        // 2. Add grades
        s1.addGrade(88.5);
        s1.addGrade(92.0);
        s1.addGrade(95.0);

        s2.addGrade(75.0);
        s2.addGrade(81.5);

        s3.addGrade(100.0);

        // Register students with the manager
        manager.addStudent(s1);
        manager.addStudent(s2);
        manager.addStudent(s3);

        // 3. Display all students
        manager.displayAllStudents();
        std::cout << "\n";

        // 4. Find and update a specific student
        std::cout << "Searching for student with ID 102...\n";
        Student* found = manager.findStudent(102);
        if (found != nullptr) {
            std::cout << "Found student! Adding new grade...\n";
            found->addGrade(90.0);
            std::cout << "Updated Info: ";
            found->displayInfo();
        } else {
            std::cout << "Student not found.\n";
        }
        std::cout << "\n";

        // 5. Test Error Handling Edge Cases
        std::cout << "--- Testing Exception Handling ---\n";

        // Testing invalid grade bounds
        try {
            s1.addGrade(105.0); // Should fail
        } catch (const std::exception& e) {
            std::cout << "Caught expected grade error: " << e.what() << "\n";
        }

        // Testing duplicate student ID insertion
        try {
            Student duplicate("Alice Copy", 101);
            manager.addStudent(duplicate); // Should fail
        } catch (const std::exception& e) {
            std::cout << "Caught expected duplicate error: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "System Error: " << e.what() << "\n";
    }

    return 0;
}