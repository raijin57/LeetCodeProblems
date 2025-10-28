//
// Created by arsen on 28.10.2025.
//
#include <cmath>
#include <queue>
#include <vector>
struct comparator {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        return std::sqrt(std::pow(lhs.first, 2) + std::pow(lhs.second, 2)) < std::sqrt(std::pow(rhs.first, 2) + std::pow(rhs.second, 2));
    }
};

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparator> pq;
        for (int i = 0; i < points.size(); ++i) {
            pq.emplace(points[i][0], points[i][1]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        std::vector<std::vector<int>> ans;
        while (pq.size() > k) {
            pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};