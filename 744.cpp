//
// Created by arsen on 08.07.2025.
//
#include <vector>
class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int index = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] == target) {
                left = mid + 1;
            }
            else if (letters[mid] > target) {
                index = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return letters[index];
    }
};