//
// Created by arsen on 08.07.2025.
//
#include <vector>
class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int negatives = 0;
        int n = grid.size();
        int m = grid[0].size();
        int left = 0;
        int right = m - 1;
        while (left <= n && right >= 0) {
            if (grid[left][right] < 0) {
                negatives += n - left;
                --right;
            }
            else {
                ++left;
            }
        }
        return negatives;
    }
};