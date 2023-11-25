#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> readIntegersFromFile(const std::string& filename) {
    std::vector<int> integers;
    std::ifstream file(filename);

    int number;
    while (file >> number) {
        integers.push_back(number);
    }

    file.close();
    return integers;
}

void writeIntegersToFile(const std::vector<int>& integers, const std::string& filename) {
    std::ofstream file(filename);

    for (int number : integers) {
        file << number << '\n';
    }

    file.close();
}

int main() {
    std::vector<int> integers = readIntegersFromFile("F.txt");
    std::vector<int> positiveIntegers;
    std::vector<int> negativeIntegers;

    for (int number : integers) {
        if (number == 0) {
            continue;
        }
        if (number>0) {
            positiveIntegers.push_back(number);
        }
        else {
            negativeIntegers.push_back(number);
        }
    }
    if (positiveIntegers.size() != negativeIntegers.size()) {
        std::cout << "File F does not contain an equal number of positive and negative integers.\n";
        return 0;
    }

    std::vector<int> result;

    size_t i = 0;
    while (i+1 < positiveIntegers.size()) {
        result.push_back(positiveIntegers[i]);
        result.push_back(positiveIntegers[i + 1]);
        result.push_back(negativeIntegers[i]);
        result.push_back(negativeIntegers[i + 1]);
        i += 2;
    }

    if (i == positiveIntegers.size() -1) {
        std::cout << "Last two numbers:\n";
        std::cout<< positiveIntegers[i]<< '\n';
        std::cout << negativeIntegers[i] << '\n';
    }
    writeIntegersToFile(result, "G.txt");

    return 0;
}