//
// Created by arsen on 04.11.2025.
//
#include <limits.h>
#include <string>
#include <unordered_map>
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) {
            return "";
        }
        if (t.empty()) {
            return"";
        }
        if (s == t) {
            return s;
        }
        std::unordered_map<char, int> mapT;
        for (char c : t) {
            mapT[c]++;
        }
        int left = 0;
        int have = 0;
        std::unordered_map<char, int> mapCurrent;
        int bestL = INT_MAX;
        int bestI = 0;
        for (int i = 0; i < s.length(); ++i) {
            mapCurrent[s[i]]++;
            if (mapT.count(s[i]) && mapCurrent[s[i]] == mapT[s[i]]) {
                have++;
            }
            while (have == mapT.size()) {
                if (bestL > i - left + 1) {
                    bestL = i - left + 1;
                    bestI = left;
                }
                if (mapT.count(s[left]) && mapCurrent[s[left]] - 1 < mapT[s[left]]) {
                    have--;
                }
                mapCurrent[s[left++]]--;
            }
        }
        if (bestL == INT_MAX) {
            return "";
        }
        return s.substr(bestI, bestL);
    }
};
int main() {
    Solution s;
    std::string r = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string result = s.minWindow(r, t);
}