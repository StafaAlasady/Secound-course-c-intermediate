#include <iostream>
#include <string>
#include <vector>
// Function using const reference for efficiency (no copying, no modification)
void printEmployeeReport(const std::string& name, const std::vector<double>& scores) {
    std::cout << "Performance Report for: " << name << std::endl;
    std::cout << "Scores: ";
    for (double score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
}
// Function using reference to modify original data
void applyRaise(double& salary, double percentage) {
    salary = salary * (1.0 + percentage / 100.0);
}
// Function using reference to modify vector elements
void normalizeScores(std::vector<double>& scores) {
    if (scores.empty()) return;
    // Find maximum score
    double maxScore = scores[0];
    for (double score : scores) {
        if (score > maxScore) {
            maxScore = score;
        }
    }
    // Normalize all scores to percentage of maximum
    for (double& score : scores) {
        score = (score / maxScore) * 100.0;
    }
}
double calculateAvrage(const std::vector<double>& scores){
    if (scores.empty()) return 0.0;
    double sum = 0.0;

    for (double score : scores) {
        sum +=score;
    }
    return sum/ scores.size();
}

void IncreaseAllScores(std::vector<double>& scores, double increment){
    for (double& score : scores)
    score += increment;
}
int main() {

    std::string employeeName = "Bob Wilson";
    std::vector<double> performanceScores = {85.0, 92.0, 78.0, 88.0, 95.0};
    double currentSalary = 6000.0;
    IncreaseAllScores(performanceScores, 5.0);
    for(double score : performanceScores){
        std::cout << score << "";
    }
    std::cout << std::endl;

    // Test const reference function
    printEmployeeReport(employeeName, performanceScores);

    // Test reference modification
    std::cout << "Original salary: $" << currentSalary << std::endl;
    applyRaise(currentSalary, 8.5); // 8.5% raise
    std::cout << "After raise: $" << currentSalary << std::endl;

    // Test vector modification by reference
    std::cout << "\nOriginal scores: ";
    for (double score : performanceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    normalizeScores(performanceScores);
    std::cout << "Normalized scores: ";
    for (double score : performanceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    double normalizedAvg = calculateAvrage(performanceScores);
    std::cout<<"Normalized avrage scores: "<< normalizedAvg << std::endl;
    //recalculating and showing the new booster avg
    double boostedAvg = calculateAvrage(performanceScores);
    std::cout << "Boosted average score: " << boostedAvg << std::endl;
    return 0;
}