//
// Created by arsen on 01.11.2025.
//
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 1;
        int pos = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[pos - 1]) {
                nums[pos++] = nums[i];
            }
            ++i;
        }
        return pos;
    }
};