//
// Created by arsen on 10.07.2025.
//
#include <climits>
#include <vector>
class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        std::vector<int> result;
        std::vector<std::pair<int, int>> search;
        for (int i = 0; i < intervals.size(); i++) {
            search.push_back(std::make_pair(intervals[i][0], i));
        }
        std::sort(search.begin(), search.end());
        for (int i = 0; i < intervals.size(); i++) {
            int index = INT_MAX;
            int left = 0;
            int right = intervals.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (search[mid].first >= intervals[i][1]) {
                    right = mid - 1;
                    index = mid < search[mid].second ? mid : search[mid].second;
                } else {
                    left = mid + 1;
                }
            }
            if (index == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(index);
            }
        }
        return result;
    }
};