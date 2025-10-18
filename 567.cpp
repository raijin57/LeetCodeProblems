//
// Created by arsen on 18.10.2025.
//
#include <iostream>

#include <ostream>
#include <string>
#include <unordered_map>
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        std::unordered_map<char, int> map_s1;
        std::unordered_map<char, int> map_s2;
        for (int i = 0; i < s1.size(); i++) {
            map_s1[s1[i]]++;
            map_s2[s2[i]]++;
        }
        if (map_s1 == map_s2) {
            return true;
        }
        int left = 0;
        for (int right = s1.length() ; right < s2.length(); right++) {
            map_s2[s2[right]]++;
            map_s2[s2[left]]--;
            if (map_s2[s2[left]] == 0) {
                map_s2.erase(s2[left]);
            }
            left++;
            if (map_s1 == map_s2) {
                return true;
            }
        }
        return false;
    }
};