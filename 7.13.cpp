#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

int findClosestToAverage(const std::vector<int>& A) {
    int minElement = A[0];
    int maxElement = A[0];
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] < minElement) {
            minElement = A[i];
        }
        else if (A[i] > maxElement) {
            maxElement = A[i];
        }
    }
    double average = static_cast<double>(minElement + maxElement) / 2.0;
    int closestElement = A[0];
    double closestDifference = std::abs(A[0] - average);
    for (int i = 1; i < A.size(); ++i) {
        double currentDifference = std::abs(A[i] - average);
        if (currentDifference < closestDifference) {
            closestElement = A[i];
            closestDifference = currentDifference;
        }
    }
    return closestElement;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::cout << "Element closest to the average: " << findClosestToAverage(A) << std::endl;

    return 0;
}