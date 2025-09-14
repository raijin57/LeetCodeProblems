//
// Created by arsen on 14.09.2025.
//
#include <algorithm>
#include <string>
class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.empty() || s.length() == 1) {
            return true;
        }
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());
        std::transform(s.begin(), s.end(), s.begin(),  [](unsigned char c) {
            return std::tolower(c);
        });
        int left = 0;
        int right = s.size() - 1;
        while (left != right && right > left) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};