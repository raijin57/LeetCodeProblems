//
// Created by arsen on 14.09.2025.
//
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (std::string str : strs) {
            std::string temp = str;
            std::sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto it = map.begin(); it != map.end(); ++it) {
            ans.push_back(std::move(it->second));
        }
        return ans;
    }
};