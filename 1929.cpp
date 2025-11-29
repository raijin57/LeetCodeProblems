//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n = nums.size();
        nums.resize(2 * n, 0);
        for (int i = 0; i < n; ++i) {
            nums[i + n] = nums[i];
        }
        return nums;
    }
};