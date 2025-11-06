//
// Created by arsen on 04.11.2025.
//
#include <algorithm>
#include <limits.h>
#include <vector>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        if (nums.size() < 3) {
            return 0;
        }
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];
                if (std::abs(target - sum) < std::abs(target - result)) {
                    result = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};