//
// Created by arsen on 29.06.2025.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
/**
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<char> seen;
        int result = 0;
        int answer = 0;
        for (char c : s) {
            if (std::find(seen.begin(), seen.end(), c) != seen.end()) {
                answer = result > answer ? result : answer;
                seen.erase(seen.begin(), std::find(seen.begin(), seen.end(), c) + 1);
                seen.push_back(c);
                result = seen.size();
                continue;
            }
            seen.push_back(c);
            result++;
        }
        answer = answer < result ? result : answer;
        return answer;
    }
};
*/
//! Теперь sliding window
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> lastSeen(128, -1);
        int result = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (lastSeen[c] >= left) {
                left = std::max(left, lastSeen[c] + 1);
            }
            lastSeen[c] = right;
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};