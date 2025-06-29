//
// Created by arsen on 29.06.2025.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
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

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
}