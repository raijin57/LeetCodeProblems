//
// Created by arsen on 08.07.2025.
//
#include <iostream>
#include <string>
class Solution {
public:
    int possibleStringCount(std::string word) {
        int answer = 1;
        for (std::string::iterator it = word.begin(); it != word.end(); ++it) {
            if (*it == *(it + 1)) {
                ++answer;
            }
        }
        return answer;
    }
};
int main() {
    Solution s;
    std::string word;
    std::cin >> word;
    std::cout << s.possibleStringCount(word) << std::endl;
    return 0;
}