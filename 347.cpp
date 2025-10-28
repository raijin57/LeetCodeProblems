//
// Created by arsen on 28.10.2025.
//
#include <queue>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int k : nums) {
            map[k]++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (auto it = map.begin(); it != map.end(); ++it) {
            pq.push({it->second, it->first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        std::vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};