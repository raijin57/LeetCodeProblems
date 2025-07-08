//
// Created by arsen on 08.07.2025.
//
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};
int main() {
    Solution s;
    std::vector<int> nums = {1, 3, 5, 6};
    std::cout << s.searchInsert(nums, 2) << std::endl;
}