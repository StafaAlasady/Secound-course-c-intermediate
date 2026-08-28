// persistent_student_manager.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Student {
private:
    std::string name;
    int id;
    std::vector<double> grades;

public:
    Student() : name(""), id(0) {}

    Student(const std::string& studentName, int studentID)
        : name(studentName), id(studentID) {
        if (studentID <= 0) {
            throw std::invalid_argument("Student ID must be positive.");
        }
        if (studentName.empty()) {
            throw std::invalid_argument("Student name cannot be empty.");
        }
    }

    std::string getName() const { return name; }
    int getId() const { return id; }

    void addGrade(double grade) {
        if (grade < 0.0 || grade > 100.0) {
            throw std::out_of_range("Grade must be between 0.0 and 100.0.");
        }
        grades.push_back(grade);
    }

    double calculateGPA() const {
        if (grades.empty()) return 0.0;
        double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
        return sum / grades.size();
    }

    void displayInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << " | GPA: " 
                  << std::fixed << std::setprecision(2) << calculateGPA() 
                  << " | Grades Count: " << grades.size() << "\n";
    }

    // Converts Student object to JSON
    json toJson() const {
        return json{
            {"name", name},
            {"id", id},
            {"grades", grades}
        };
    }

    // Creates/Populates Student object from JSON
    void fromJson(const json& j) {
        if (!j.contains("name") || !j.contains("id") || !j.contains("grades")) {
            throw std::runtime_error("Corrupted JSON structure: missing required fields.");
        }
        name = j["name"].get<std::string>();
        id = j["id"].get<int>();
        grades = j["grades"].get<std::vector<double>>();
    }
};

class PersistentStudentManager {
private:
    std::vector<Student> students;
    std::string filename;

public:
    PersistentStudentManager(const std::string& dbFile) : filename(dbFile) {}

    void addStudent(const Student& student) {
        for (const auto& s : students) {
            if (s.getId() == student.getId()) {
                throw std::invalid_argument("Student ID " + std::to_string(student.getId()) + " already exists.");
            }
        }
        students.push_back(student);
    }

    Student* findStudent(int id) {
        for (auto& s : students) {
            if (s.getId() == id) {
                return &s;
            }
        }
        return nullptr;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "No student records found.\n";
            return;
        }
        for (const auto& student : students) {
            student.displayInfo();
        }
    }

    // Saves all students to JSON file
    void saveToFile() const {
        json j_array = json::array();
        for (const auto& s : students) {
            j_array.push_back(s.toJson());
        }

        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            throw std::runtime_error("Unable to open file for writing: " + filename);
        }

        outFile << j_array.dump(4); // Indented by 4 spaces
        outFile.close();
    }

    // Loads students from JSON file safely
    void loadFromFile() {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            std::cout << "No existing data file found (" << filename << "). Starting fresh.\n";
            return;
        }

        json j_array;
        try {
            inFile >> j_array;
        } catch (const json::parse_error&) {
            inFile.close();
            throw std::runtime_error("File format error: " + filename + " is not valid JSON.");
        }
        inFile.close();

        students.clear();
        for (const auto& item : j_array) {
            Student s;
            s.fromJson(item);
            students.push_back(s);
        }
    }
};

int main() {
    std::cout << "Persistent Student Management System" << std::endl;
    std::cout << "------------------------------------\n";

    const std::string dbFileName = "students.json";

    try {
        // 1. Create manager instance targeting "students.json"
        PersistentStudentManager manager(dbFileName);

        // 2. Load existing data from file if present
        std::cout << "Attempting to load data from file...\n";
        manager.loadFromFile();
        std::cout << "\n[Current Records in Memory]\n";
        manager.displayAllStudents();

        // 3. Add new students or modify existing ones
        std::cout << "\nAdding new student records...\n";
        Student s1("Dave Wilson", 104);
        s1.addGrade(91.0);
        s1.addGrade(85.5);

        Student s2("Eve Miller", 105);
        s2.addGrade(98.0);

        manager.addStudent(s1);
        manager.addStudent(s2);

        // 4. Save data back to file
        std::cout << "Saving updated records to " << dbFileName << "...\n";
        manager.saveToFile();

        // 5. Demonstrate persistence by reloading into a new manager instance
        std::cout << "\nDemonstrating Persistence (Simulating application restart)...\n";
        PersistentStudentManager freshManager(dbFileName);
        freshManager.loadFromFile();

        std::cout << "\n[Reloaded Records from Disk]\n";
        freshManager.displayAllStudents();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}