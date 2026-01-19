//
// Created by arsen on 19.01.2026.
//
#include <string>
class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int lenMin = std::min(len1, len2);
        std::string answer = "";
        for (int i = 0; i < lenMin; ++i) {
            answer += word1[i] + word2[i];
        }
        if (len1 > lenMin) {
            answer += word1.substr(lenMin);
        }
        if (len2 > lenMin) {
            answer += word2.substr(lenMin);
        }
        return answer;
    }
};