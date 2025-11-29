//
// Created by arsen on 29.11.2025.
//
#include <vector>
class Solution {
    void recursion(int i, int n, std::vector<int>& cur, std::vector<std::vector<int>>& res, std::vector<int>& candidates) {
        if (n < 0) {
            return;
        }
        if (n == 0) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            cur.push_back(candidates[j]);
            recursion(j, n - candidates[j], cur, res, candidates);
            cur.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        recursion(0, target, cur, res, candidates);
        return res;
    }
};