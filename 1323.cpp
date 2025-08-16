//
// Created by arsen on 16.08.2025.
//
#include <string>
class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        int found = s.find("6");
        if (found == std::string::npos) {
            return num;
        }
        else {
            s.replace(found, 1, "9");
            return std::stoi(s);
        }
    }
};