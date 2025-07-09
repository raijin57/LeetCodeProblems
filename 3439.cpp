//
// Created by arsen on 09.07.2025.
//
#include <vector>
class Solution {
public:
    int maxFreeTime(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
        std::vector<int> freeTime = timeBetweenEvents(eventTime, k, startTime, endTime);
        int max_sum = 0;
        for (int i = 0; i < k + 1; i++) {
            max_sum += freeTime[i];
        }
        int window_sum = max_sum;
        for (int i = k + 1; i < freeTime.size(); i++) {
            window_sum += freeTime[i] - freeTime[i - k - 1];
            max_sum = std::max(max_sum, window_sum);
        }
        return max_sum;
    }
    std::vector<int> timeBetweenEvents(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
        std::vector<int> result;
        result.push_back(startTime[0]);
        for (int i = 0; i < startTime.size() - 1; i++) {
            result.push_back(startTime[i + 1] - endTime[i]);
        }
        result.push_back(eventTime - endTime[endTime.size() - 1]);
        return result;
    }
};