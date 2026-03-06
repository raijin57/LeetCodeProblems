//
// Created by arsen on 06.03.2026.
//
#include <vector>
class Solution {
public:
    void dfs(std::vector<std::vector<char>>& matrix, int row, int col) {
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == '0') {
            return;
        }
        matrix[row][col] = '0';
        dfs(matrix, row + 1, col);
        dfs(matrix, row - 1, col);
        dfs(matrix, row, col + 1);
        dfs(matrix, row, col - 1);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int islandCounter = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    islandCounter++;
                }
            }
        }
        return islandCounter;
    }
};