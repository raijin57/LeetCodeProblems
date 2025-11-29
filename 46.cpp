//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.size() == 1) {
            res.push_back({nums});
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            std::vector<int> remaining;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remaining.push_back(nums[j]);
                }
            }
            std::vector<std::vector<int>> perms = permute(remaining);
            for (auto v : perms) {
                v.insert(v.begin(), n);
                res.push_back(v);
            }
        }
        return res;
    }
};