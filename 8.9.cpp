#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double>> inverse(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double determinant = 1.0;
    for (int i = 0; i < n; i++) {
        determinant *= matrix[i][i];
    }

    if (std::abs(determinant) < 1e-10) {
        std::cerr << "Error: Input matrix is singular (non-invertible)." << std::endl;
        return { {} };
    }
    std::vector<std::vector<double>> augmentedMatrix(matrix);
    for (int i = 0; i < n; i++) {
        augmentedMatrix[i].resize(2 * n);
        augmentedMatrix[i][n + i] = 1.0;
    }
    for (int i = 0; i < n; i++) {
        int pivotRow = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(augmentedMatrix[j][i]) > std::abs(augmentedMatrix[pivotRow][i])) {
                pivotRow = j;
            }
        }
        std::swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmentedMatrix[i][j] /= pivot;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[i][j] = augmentedMatrix[i][n + j];
        }
    }

    return inverseMatrix;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    std::cout << "Inverse Matrix:" << std::endl;
    printMatrix(inverse(matrix));

    return 0;
}