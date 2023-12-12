#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(const std::vector<std::vector<T>>& input) : data(input) {}
    Matrix(size_t rows, size_t cols) : data(rows, std::vector<T>(cols, T())) {}

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& element : row) {
                os << element << ' ';
            }
            os << '\n';
        }
        return os;
    }
    size_t rows() const {
        return data.size();
    }

    size_t cols() const {
        return data.empty() ? 0 : data[0].size();
    }

    Matrix operator+(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrix dimensions do not match");
        }

        Matrix result(*this);
        for (size_t i = 0; i < data.size(); ++i) {
            std::transform(result.data[i].begin(), result.data[i].end(), other.data[i].begin(),
                result.data[i].begin(), std::plus<T>());
        }

        return result;
    }


    std::vector<T> operator*(const std::vector<T>& vec) const {
        if (data[0].size() != vec.size()) {
            throw std::invalid_argument("Matrix and vector dimensions do not match");
        }

        std::vector<T> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = std::inner_product(data[i].begin(), data[i].end(), vec.begin(), static_cast<T>(0));
        }

        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (data[0].size() != other.data.size()) {
            throw std::invalid_argument("Matrix dimensions do not allow multiplication");
        }

        Matrix<T> result(rows(), other.cols());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix<int> intMatrix1({ {1, 2, 3}, {4, 5, 6} });
    Matrix<int> intMatrix2({ {7, 8}, {9, 10}, {11, 12} });
    std::cout << "Matrix 1:\n" << intMatrix1 << "\nMatrix 2:\n" << intMatrix2;

    try {
        Matrix<int> intSum = intMatrix1 + intMatrix2;
        std::cout << "Matrix Sum:\n" << intSum;
        std::vector<int> intVector({ 1, 2, 3 });
        std::vector<int> intProduct = intMatrix1 * intVector;
        std::cout << "Matrix-Vector Product:\n";
        for (const auto& element : intProduct) {
            std::cout << element << ' ';
        }
        std::cout << '\n';

        // Matrix multiplication
        Matrix<int> intProductMatrix = intMatrix1 * intMatrix2;
        std::cout << "Matrix Product:\n" << intProductMatrix;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Matrix<float> floatMatrix1({ {1.1f, 2.2f, 3.3f}, {4.4f, 5.5f, 6.6f} });
    Matrix<float> floatMatrix2({ {7.7f, 8.8f}, {9.9f, 10.10f}, {11.11f, 12.12f} });
    //Matrix<float> floatMatrix2({ {7.7f, 8.8f, 11.11f}, {9.9f, 10.10f, 12.12f});
    std::cout << "\nMatrix 1 (float):\n" << floatMatrix1 << "\nMatrix 2 (float):\n" << floatMatrix2;

    try {
        Matrix<float> floatSum = floatMatrix1 + floatMatrix2;
        std::cout << "Matrix Sum (float):\n" << floatSum;
        std::vector<float> floatVector({ 1.1f, 2.2f, 3.3f });
        std::vector<float> floatProduct = floatMatrix2 * floatVector;
        std::cout << "Matrix-Vector Product (float):\n";
        for (const auto& element : floatProduct) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
        Matrix<float> floatProductMatrix = floatMatrix1 * floatMatrix2;
        std::cout << "Matrix Product (float):\n" << floatProductMatrix;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}