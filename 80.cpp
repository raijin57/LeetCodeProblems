//
// Created by arsen on 04.11.2025.
//
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int left = 2;
        int right = 2;
        while (right < nums.size()) {
            if (nums[left - 2] != nums[right]) {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        return left;
    }
};