#include <list>
#include <iostream>

int main() {
    size_t n;
    int x;
    std::cin >> n >> x;
    std::list<int> l;

    for (size_t i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        l.push_back(v);
    }

    l.sort([x](int a, int b) {
        return (a < x) != (b < x) && a < b;
    });

    for (auto v : l) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}