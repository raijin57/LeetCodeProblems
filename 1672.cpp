//
// Created by arsen on 25.06.2025.
//
#include <vector>
class Solution {
   public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max_wealth = 0;
        for (std::vector person : accounts) {
            int wealth = 0;
            for (int sum : person) {
                wealth += sum;
            }
            max_wealth = wealth > max_wealth ? wealth : max_wealth;
        }
        return max_wealth;
    }
};