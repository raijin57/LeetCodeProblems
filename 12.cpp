//
// Created by arsen on 21.01.2026.
//
#include <string>
#include <vector>
class Solution {
public:
    std::string intToRoman(int num) {
     std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        std::string result = "";
        for (auto key : roman) {
            while (num >= key.first) {
                result += key.second;
                num -= key.first;
            }
        }
        return result;
    }
};