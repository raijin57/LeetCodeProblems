//
// Created by arsen on 25.06.2025.
//
#include <vector>

class Solution {
   public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> result;
        int prefix_sum = 0;
        for (int num : nums) {
            prefix_sum += num;
            result.push_back(prefix_sum);
        }
        return result;
    }
};