//
// Created by arsen on 04.11.2025.
//
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[right] + numbers[left] == target) {
                break;
            }
            if (numbers[right] + numbers[left] < target) {
                left++;
            }
            if (numbers[right] + numbers[left] > target) {
                right--;
            }
        }
        return std::vector<int>({left + 1, right + 1});
    }
};