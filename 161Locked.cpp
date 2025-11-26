//
// Created by arsen on 26.11.2025.
//
#include <string>
class Solution {
   public:
    bool isOneEditDistance(std::string s, std::string t) {
        int sLength = s.size();
        int tLength = t.size();
        if (sLength < tLength) {
            return isOneEditDistance(t, s);
        }
        if (sLength - tLength > 1) {
            return false;
        }
        for (int i = 0; i < sLength; ++i) {
            if (s[i] != t[i]) {
                if (sLength == tLength) {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                return s.substr(i + 1) == t.substr(i);
            }
        }
        return sLength == tLength + 1;
    }
};