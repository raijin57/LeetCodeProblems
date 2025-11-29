//
// Created by arsen on 29.11.2025.
//
#include <unordered_set>
#include <vector>
class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int realSum = 0;
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int uniqueSum = 0;
        int duplicate = 0;
        int missing = 0;
        std::unordered_set<int> seen(nums.begin(), nums.end());
        for (int x : nums) {
            realSum += x;
        }
        for (int x: seen) {
            uniqueSum += x;
        }
        missing = expectedSum - uniqueSum;
        duplicate = realSum - uniqueSum;
        return {duplicate, missing};
    }
};