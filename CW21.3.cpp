#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);

    for (auto& v : nums) {
        std::cin >> v;
    }

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>{});
    int sum_largest = std::accumulate(nums.begin(), nums.begin() + k, 0);
    std::cout << sum_largest << std::endl;

    std::partial_sort(nums.begin(), nums.begin() + k, nums.end());

    // first k smallest
    for (size_t i = 0; i < k; i++) {
        std::cout << nums[i] << ' ';
    }
}