//
// Created by arsen on 28.10.2025.
//
#include <queue>
#include <vector>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};