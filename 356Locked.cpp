//
// Created by arsen on 19.11.2025.
//
#include <limits.h>
#include <set>
#include <vector>
class Solution {
public:
    bool isReflected(std::vector<std::vector<int>>& points) {
        int minX = INT_MIN;
        int maxX = INT_MAX;
        std::set<std::pair<int, int>> pointsSet;
        for (const auto& point : points) {
            minX = std::min(minX, point[0]);
            maxX = std::max(maxX, point[0]);
            pointsSet.insert(std::make_pair(point[0], point[1]));
        }
        for (const auto& point : points) {
            if (!pointsSet.count({maxX + minX - point[0], point[1]})) {
                return false;
            }
        }
        return true;
    }
};