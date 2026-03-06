//
// Created by arsen on 06.03.2026.
//
#include <string>
class Solution {
public:
    bool checkOnesSegment(std::string s) {
        int left = 0;
        int right = 1;
        for (; right < s.length(); right++, left++) {
            if (s[left] == '0' && s[right] == '1') {
                return false;
            }
        }
        return true;
    }
};