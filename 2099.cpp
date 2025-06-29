//
// Created by arsen on 29.06.2025.
//
#include <algorithm>
#include <vector>
class Solution {
   public:
    std::vector<int> maxSubsequence(std::vector<int> &nums, int k) {
        std::vector<int> copy(nums);
        std::vector<int> result;
        std::stable_sort(nums.begin(), nums.end());
        std::vector<int> maxes;
        for (int i = 0; i < k; ++i) {
            int max = nums[nums.size() - 1];
            nums.pop_back();
            maxes.push_back(max);
        }
        for (int i = 0; i < copy.size(); ++i) {
            if (std::find(maxes.begin(), maxes.end(), copy[i]) != maxes.end() && result.size() < k) {
                result.push_back(copy[i]);
            }
        }
        return result;
    }
};