//
// Created by arsen on 02.11.2025.
//
#include <limits.h>
#include <vector>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int result = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                result = std::min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};