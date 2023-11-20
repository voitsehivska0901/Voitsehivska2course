#include <iostream>
#include <vector>


void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

void addRowsToBeginning(std::vector<std::vector<int>>& matrix, int k) {
    if (k < 0) {
        std::cout << "k suposed to be non negative integer" << std::endl;
        return;
    }
    int rows = matrix.size();
    int cols = (rows > 0) ? matrix[0].size() : 0;
    for (int i = 0; i < k; i++) {
        std::vector<int> newRow(cols);
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> newRow[j];
        }
        matrix.insert(matrix.begin(), newRow);
    }
}

void deleteUnpairedRows(std::vector<std::vector<int>>& matrix) {
    //indexin starts from zero, so we check i % 2 == 0 and not !=0
    int rows = matrix.size();
    for (int i = rows - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            matrix.erase(matrix.begin() + i);
        }
    }
}

int main() {
    int N, M;
    int k;

    std::cout << "Enter the number of rows (N): ";
    std::cin >> N;
    std::cout << "Enter the number of columns (M): ";
    std::cin >> M;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Original Matrix:\n";
    displayMatrix(matrix);
    std::cout << "Enter the number of rows to add (k): ";
    std::cin >> k;
    addRowsToBeginning(matrix, k);
    std::cout << "Matrix after adding rows:\n";
    displayMatrix(matrix);
    deleteUnpairedRows(matrix);
    std::cout << "Matrix after deleting unpaired rows:\n";
    displayMatrix(matrix);

    return 0;
}