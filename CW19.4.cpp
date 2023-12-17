#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    unsigned n, m;
    std::vector<std::vector<double>> mat;

    for (size_t i = 0; i < n; i++) {
        std::vector<double> row(m);
        for (auto& v : row) {
            std::cin >> v;
        }
        row.emplace_back(std::move(row));
    }

    std::sort(mat.begin(), mat.end(), [](const auto& a, const auto& b){
        return std::max_element(a.begin(), a.end()) > std::max_element(b.begin(), b.end());
    });

    for (const auto& row : mat) {
        for (const auto& v : row) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}