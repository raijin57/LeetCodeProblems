//
// Created by arsen on 01.11.2025.
//
#include <vector>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = (right - left) * std::min(height[right] , height[left]);
            maxArea = std::max(maxArea, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};