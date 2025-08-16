//
// Created by arsen on 16.08.2025.
//
#include <string>
class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        for (char number : "9876543210") {
            std::string s = std::string(3, number);
            if (num.find(s) != std::string::npos) {
                return s;
            }
        }
        return "";
    }
};