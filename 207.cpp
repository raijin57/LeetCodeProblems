//
// Created by arsen on 31.10.2025.
//
#include <vector>
class Solution {
   public:
    bool dfs(std::vector<std::vector<int>>& nums, int v, std::vector<int>& visited, std::vector<int>& order) {
        visited[v] = 1;
        order[v] = 1;
        for (int to : nums[v]) {
            if (!visited[to]) {
                if (dfs(nums, to, visited, order)) {
                    return true;
                }
            } else if (order[to]) {
                return true;
            }
        }
        order[v] = false;
        return false;
    }
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        std::vector<int> order(numCourses);
        std::vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, order)) {
                    return false;
                }
            }
        }
        return true;
    }
};