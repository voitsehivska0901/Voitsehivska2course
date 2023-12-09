#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<clock_t> clocks(n);
    std::generate(clocks.begin(), clocks.end(), clock);
    size_t new_size = std::unique(clocks.begin(), clocks.end()) - clocks.begin();
    clocks.resize(new_size);
    std::copy(clocks.begin(), clocks.end(), std::ostream_iterator<clock_t>(std::cout));
}
