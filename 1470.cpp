//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> ans;
        int left = 0;
        int right = n;
        while (right < 2 * n) {
            ans.push_back(nums[left++]);
            ans.push_back(nums[right++]);
        }
        return ans;
    }
};