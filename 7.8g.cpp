#include <iostream>
#include <vector>

int countIntegersWithBitsSet(const std::vector<unsigned int>& numbers) {
    int count = 0;
    for (unsigned int num : numbers) {
        if ((num & (1 << 4)) && (num & (1 << 5)) && (num & (1 << 7))) {
            count++;
        }
    }

    return count;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<unsigned int> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << countIntegersWithBitsSet(numbers) << std::endl;

    return 0;
}