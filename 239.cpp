//
// Created by arsen on 21.11.2025.
//
#include <vector>
#include <deque>
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> deque;
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (!deque.empty() && deque.front() <= i - k) {
                deque.pop_front();
            }
            while (!deque.empty() && nums[deque.back()] <= nums[i]) {
                deque.pop_back();
            }
            deque.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[deque.front()]);
            }
        }
        return res;
    }
};