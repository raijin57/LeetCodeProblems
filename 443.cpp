//
// Created by arsen on 14.09.2025.
//
#include <string>
#include <vector>
class Solution {
public:
    int compress(std::vector<char>& chars) {
        int answer = 0;
        for (int i = 0; i < chars.size();) {
            const char letter = chars[i];
            int counter = 0;
            while (i < chars.size() && chars[i] == letter) {
                ++counter;
                ++i;
            }
            chars[answer++] = letter;
            if (counter > 1) {
                for (const char c : std::to_string(counter)) {
                    chars[answer++] = c;
                }
            }
        }
        return answer;
    }
};