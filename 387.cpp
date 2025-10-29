//
// Created by arsen on 29.10.2025.
//
#include <string>
#include <unordered_map>
class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};