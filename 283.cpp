//
// Created by arsen on 14.09.2025.
//
#include <vector>
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        // * for (auto i = std::remove(nums.begin(), nums.end(), 0); i != nums.end(); ++i) {
        // *     *i = 0;
        // * }

        // ! Теперь два указателя !
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                std::swap(nums[left], nums[right]);
                ++left;
            }
        }
    }
};