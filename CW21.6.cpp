#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (auto& v : nums) {
        std::cin >> v;
    }

    int sum = 0;

    std::for_each(nums.begin(), nums.end(), [&sum](int v){
        sum += v;
    });

    std::cout << sum << std::endl;
}