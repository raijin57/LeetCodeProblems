//
// Created by arsen on 31.10.2025.
//
#include <queue>
#include <vector>
class Solution {
   public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> order;
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        std::queue<int> queue;
        for (int index = 0; index < numCourses; ++index) {
            if (indegree[index] == 0) {
                queue.push(index);
            }
        }
        while (!queue.empty()) {
            const int at = queue.front();
            queue.pop();
            order.push_back(at);
            for (int v : adj[at]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    queue.push(v);
                }
            }
        }
        if (order.size() != numCourses) {
            return {};
        }
        return order;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> prerequisites = {{0, 1}};
    std::vector<int> order = s.findOrder(2, prerequisites);
}