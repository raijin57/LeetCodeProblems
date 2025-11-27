//
// Created by arsen on 27.11.2025.
//
#include <vector>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i + 1] = std::max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[nums.size()];
    }
};