//
// Created by arsen on 27.11.2025.
//
#include <algorithm>
#include <limits.h>
#include <vector>
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int x = coin; x <= amount; ++x) {
                dp[x] = std::min(dp[x], dp[x - coin] + 1);
            }
        }
        return dp[amount];
    }
};