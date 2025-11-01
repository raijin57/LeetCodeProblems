//
// Created by arsen on 01.11.2025.
//
#include <vector>
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum = 0;
        double maxSum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = std::max(sum, maxSum);
        }
        return maxSum / k;
    }
};