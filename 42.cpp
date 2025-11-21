//
// Created by arsen on 19.10.2025.
//
#include <algorithm>
#include <vector>
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        std::vector<int> maxLeft(n);
        std::vector<int> maxRight(n);
        int leftWall = 0;
        int rightWall = 0;
        for (int i = 0; i < n; i++) {
            const int j = n - i - 1;
            maxLeft[i] = leftWall;
            maxRight[i] = rightWall;
            leftWall = std::max(leftWall, height[i]);
            rightWall = std::max(rightWall, height[j]);
        }
        std::reverse(maxRight.begin(), maxRight.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            const int potential = std::min(maxLeft[i], maxRight[i]);
            ans += std::max(0, potential - height[i]);
        }
        return ans;
    }
};

//? Моё сигма-решение, не зашедшее по TL
/** class Solution {
// public:
//     int trap(std::vector<int>& height) {
//         int result = 0;
//         if (height.size() == 0) {
//             return 0;
//         }
//         for (int i = 1; i < *std::max_element(height.begin(), height.end()) + 1; i++) {
//             int last_same_height = -1;
//             int water = 0;
//             for (int stick = 0; stick < height.size(); stick++) {
//                 if (height[stick] >= i) {
//                     result += water;
//                     water = 0;
//                     last_same_height = stick;
//                     continue;
//                 }
//                 if (height[stick] <= i && last_same_height != -1) {
//                     water += 1;
//                 }
//             }
//         }
//         return result;
//     }
// };
**/

