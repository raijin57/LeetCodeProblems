//
// Created by arsen on 06.09.2025.
//
#include <vector>
#include <string>
class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        if (nums.size() == 0) {
            return result;
        }
        int i = 0;
        int j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (nums[j] != nums[i] + (j - i)) {
                if (j - i == 1) {    // std::vector<int> nums = {0,1,2,4,5,7};
                    result.push_back(std::to_string(nums[i]));
                    i = j;
                }
                else {
                    result.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j - 1]));
                    i = j;
                }
            }
            j++;
        }
        if (j - i != 1) {
            result.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j - 1]));
        }
        else {
            result.push_back(std::to_string(nums[j - 1]));
        }
        return result;
    }
};

int main() {
    std::vector<int> nums = {0,1,2,4,5,7};
    Solution s;
    s.summaryRanges(nums);
    return 0;
}