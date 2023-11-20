#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>



std::vector<double> calculateArcsin(const std::vector<double>& array) {
    std::vector<double> result;

    for (double value : array) {
        double arcsinValue = std::asin(value);
        if (arcsinValue>=-1.0 && arcsinValue<=1.0) {
            result.push_back(arcsinValue);
        }
    }
    return result;
}

void writeResultsToFile(const std::vector<double>& result, const std::string& filename) {
    std::ofstream file(filename);
    file << std::scientific << std::setprecision(10);

    for (double value : result) {
        file << value << '\n';
    }

    file.close();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::vector<double> inputValues;
    double value;

    while (inputFile >> value) {
        inputValues.push_back(value);
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ';');
    }
    inputFile.close();
    std::vector<double> result = calculateArcsin(inputValues);
    writeResultsToFile(result, "output.txt");

    return 0;
}