//
// Created by arsen on 19.10.2025.
//
#include <algorithm>
#include <vector>
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

#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n <= 2) {
            return 0;
        }
        std::vector<int> left_max(n);
        std::vector<int> right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = std::max(left_max[i-1], height[i]);
        }
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; --i) {
            right_max[i] = std::max(right_max[i+1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += std::min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
