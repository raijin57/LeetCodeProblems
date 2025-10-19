//
// Created by arsen on 19.10.2025.
//
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> res;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] < b[0];
        });
        for (auto v : intervals) {
            if (res.empty() || res.back()[1] < v[0]) {
                res.push_back(v);
            }
            else {
                res.back()[1] = std::max(res.back()[1], v[1]);
            }
        }
        return res;
    }
};