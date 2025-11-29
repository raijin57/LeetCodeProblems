//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
    void dfs(int i, int n, std::vector<int>& cur, std::vector<std::vector<int>>& res, std::vector<int>& nums) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        dfs(i + 1, n, cur, res, nums);
        cur.push_back(nums[i]);
        dfs(i + 1, n, cur, res, nums);
        cur.pop_back();
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        dfs(0, nums.size(), cur, res, nums);
        return res;
    }
};