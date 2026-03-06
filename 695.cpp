//
// Created by arsen on 06.03.2026.
//
#include <iostream>
#include <vector>
class Solution {
public:
    int dfs(std::vector<std::vector<int>>& matrix, int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] == 0) {
            return 0;
        }
        int count = 1;
        matrix[row][col] = 0;
        count += dfs(matrix, row + 1, col, n, m);
        count += dfs(matrix, row - 1, col, n, m);
        count += dfs(matrix, row, col + 1, n, m);
        count += dfs(matrix, row, col - 1, n, m);
        return count;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    maxArea = std::max(maxArea, dfs(grid, row, col, n, m));
                }
            }
        }
        return maxArea;
    }
};