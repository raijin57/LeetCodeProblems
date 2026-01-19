//
// Created by arsen on 19.01.2026.
//
#include <algorithm>
#include <vector>
#include <cmath>
class Solution {
public:
    int findClosestNumber(std::vector<int>& nums) {
        int closest = 100000;
        for (int i : nums) {
            if (std::abs(i) < std::abs(closest)) {
                closest = i;
            }
        }
        if (closest < 0 && std::find(nums.begin(), nums.end(), std::abs(closest)) != nums.end()) {
            return std::abs(closest);
        }
        return closest;
    }
};