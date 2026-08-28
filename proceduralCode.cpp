#include <iostream>
#include <vector>
#include <string>

void printClassScore(const std::string& className, const std::vector<double>& scores){
    std::cout << className << "Scores: ";
    for (double score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
}

double AvrageClassCalc(const std::vector<double>& scores){
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}


int main() {
    std::vector<double> classA = {88.5, 92.0, 79.5, 95.0};
    std::vector<double> classB = {60.0, 75.5, 82.0, 90.0, 68.0};

    printClassScore("Class A", classA);
    printClassScore("Class B", classB);

    std::cout << "__________________________________" << std::endl;

    std::cout << "Class A Average: " << AvrageClassCalc(classA) << std::endl;
    std::cout << "Class B Average: " << AvrageClassCalc(classB) << std::endl;

    return 0;
}