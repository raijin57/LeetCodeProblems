//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int left = 0;
        int right = 0;
        int max = 0;
        while (right < nums.size()) {
            while (right < nums.size() && nums[right] != 0) {
                right++;
            }
            max = std::max(max, right - left);
            left = ++right;
        }
        return max;
    }
};