//
// Created by arsen on 30.06.2025.
//
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        int longest = 0;
        std::sort(nums.begin(), nums.end());
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[right] > 1) {
                right++;
            }
            if (nums[i] - nums[right] == 1) {
                longest = std::max(longest, i - right + 1);
            }
        }
        return longest;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1,3,2,2,5,2,3,7};
    std::cout << s.findLHS(nums) << std::endl;
}