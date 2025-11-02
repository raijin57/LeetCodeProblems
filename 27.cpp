//
// Created by arsen on 01.11.2025.
//
#include <iostream>

#include <ostream>
#include <vector>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        int pos = 0;
        while (i < nums.size()) {
            if (nums[i] != val) {
                std::swap(nums[i], nums[pos]);
                pos++;
            }
            i++;
        }
        return pos;
    }
};