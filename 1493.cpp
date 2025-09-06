//
// Created by arsen on 06.09.2025.
//
#include <algorithm>
#include <vector>
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int result;
        if (std::find(nums.begin(), nums.end(), 0) == nums.end()) {
            return nums.size() - 1;
        }
        int i = 0;
        int j = 0;
        int zeroes = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                zeroes++;
            }
            while (zeroes > 1) {
                if (nums[i] == 0) {
                    zeroes--;
                }
                i++;
            }
            result = std::max(result, j - i);
            j++;
        }
        return result;
    }
};