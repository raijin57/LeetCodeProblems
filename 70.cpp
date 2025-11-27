//
// Created by arsen on 27.11.2025.
//
#include <unordered_map>
class Solution {
    std::unordered_map<int, int> memo{{0, 1}, {1, 1}};
    int recursion(int n, std::unordered_map<int, int>& memo) {
        if (memo.count(n)) {
            return memo[n];
        }
        memo[n] = recursion(n - 1, memo) + recursion(n - 2, memo);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        return recursion(n, memo);
    }
};