#include <iostream>
#include <vector>

std::vector<int> findRepeatingDecimal(int n, int m) {
    std::vector<int> remainders;
    std::vector<int> decimals;

    int remainder = n % m;

    while (remainder != 0 && std::find(remainders.begin(), remainders.end(), remainder) == remainders.end()) {
        remainders.push_back(remainder);
        remainder *= 10;
        decimals.push_back(remainder / m);
        remainder %= m;
    }
    if (remainder == 0) {
        return {};
    }
    else {
        auto start = std::find(remainders.begin(), remainders.end(), remainder);
        return std::vector<int>(decimals.begin() + (start - remainders.begin()), decimals.end());
    }
}

int main() {
    int n, m;
    std::cout << "Enter the values for n and m: ";
    std::cin >> n >> m;

    std::vector<int> repeatingPart = findRepeatingDecimal(n, m);

    if (repeatingPart.empty()) {
        std::cout << "The decimal expansion is terminating." << std::endl;
    }
    else {
        std::cout << "The repeating part of the decimal fraction " << n << "/" << m << " is: ";
        for (int digit : repeatingPart) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }

    return 0;
}