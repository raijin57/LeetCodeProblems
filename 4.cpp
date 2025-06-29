//
// Created by arsen on 29.06.2025.
//
#include <algorithm>
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result(nums1);
        for (int i : nums2) {
            result.push_back(i);
        }
        std::sort(result.begin(), result.end());
        bool median_is_single = result.size() % 2 == 0;
        if (median_is_single) {
            return (result[result.size() / 2 - 1] + result[result.size() / 2]) / 2.0;
        }
       return result[result.size() / 2];
    }
};