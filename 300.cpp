//
// Created by arsen on 27.11.2025.
//
#include <algorithm>
#include <vector>
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};