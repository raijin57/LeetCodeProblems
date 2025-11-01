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

int main() {
    Solution s;
    std::vector<int> nums = {3, 3};
    std::cout << s.removeElement(nums, 3) << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }
}