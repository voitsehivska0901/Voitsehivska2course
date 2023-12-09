#include <iostream>
#include <type_traits>

namespace my_max {
    template<typename T>
    const T& max(const T& a, const std::type_identity_t<T>& b) {
        return a > b ? a : b;
    }
}

int main() {
    std::cout << my_max::max(2, 42) << std::endl;
}