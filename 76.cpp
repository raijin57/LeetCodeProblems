//
// Created by arsen on 04.11.2025.
//
#include <climits>
#include <vector>
#include <string>
class Solution {
   public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        std::vector<int> map(128, 0);
        for (int i = 0; i < t.size(); ++i) {
            map[t[i]]++;
        }
        int left = 0;
        int right = 0;
        int count = t.length();
        int min = INT_MAX;
        int startIndex = 0;
        while (right < s.length()) {
            if (map[s[right++]]-- > 0) {
                count--;
            }
            while (count == 0) {
                if (right - left < min) {
                    startIndex = left;
                    min = right - left;
                }
                if (map[s[left++]]++ == 0) {
                    count++;
                }
            }
        }
        return min == INT_MAX ? "" : s.substr(startIndex, min);
    }
};

/*
 * class Solution {
 * public:
 *     std::string minWindow(std::string s, std::string t) {
 *         if (s.length() < t.length()) {
 *             return "";
 *         }
 *         if (t.empty()) {
 *             return"";
 *         }
 *         if (s == t) {
 *             return s;
 *         }
 *         std::unordered_map<char, int> mapT;
 *         for (char c : t) {
 *             mapT[c]++;
 *         }
 *         int left = 0;
 *         int have = 0;
 *         std::unordered_map<char, int> mapCurrent;
 *         int bestL = INT_MAX;
 *         int bestI = 0;
 *         for (int i = 0; i < s.length(); ++i) {
 *             mapCurrent[s[i]]++;
 *             if (mapT.count(s[i]) && mapCurrent[s[i]] == mapT[s[i]]) {
 *                 have++;
 *             }
 *             while (have == mapT.size()) {
 *                 if (bestL > i - left + 1) {
 *                     bestL = i - left + 1;
 *                     bestI = left;
 *                 }
 *                 if (mapT.count(s[left]) && mapCurrent[s[left]] - 1 < mapT[s[left]]) {
 *                     have--;
 *                 }
 *                 mapCurrent[s[left++]]--;
 *             }
 *         }
 *         if (bestL == INT_MAX) {
 *             return "";
 *         }
 *         return s.substr(bestI, bestL);
 *     }
 * };
 */