#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

void writeNumbersAndRootsToFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    int number;
    while (inFile >> number) {
        if (number >= 0) {
            double squareRoot = std::sqrt(number);
            outFile << std::fixed << std::setprecision(5);
            outFile << number << "," << squareRoot << '\n';
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";
    writeNumbersAndRootsToFile(inputFile, outputFile);

    return 0;
}