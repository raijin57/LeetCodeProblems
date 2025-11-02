//
// Created by arsen on 02.11.2025.
//
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::unordered_map<char, int> mapP;
        std::unordered_map<char, int> mapS;
        for (char c : p) {
            mapP[c]++;
        }
        std::vector<int> ans;
        for (int i = 0; i < p.length(); ++i) {
            mapS[s[i]]++;
        }
        if (mapP == mapS) {
            ans.push_back(0);
        }
        for (int i = p.length(); i < s.length(); ++i) {
            mapS[s[i]]++;
            mapS[s[i - p.length()]]--;
            if (mapS[s[i - p.length()]] == 0) {
                mapS.erase(s[i - p.length()]);
            }
            if (mapP == mapS) {
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
    }
};