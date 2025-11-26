//
// Created by arsen on 26.11.2025.
//
#include <vector>
class Solution {
   public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int left = 0;
        int counter = 0;
        for (int x : nums) {
            counter += x ^ 1;
            if (counter > 1) {
                counter -= nums[left++] ^ 1;
            }
        }
        return nums.size() - left;
    }
};