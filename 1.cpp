//
// Created by arsen on 29.06.2025.
//
#include <map>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> needed;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (needed.find(target - nums[i]) != needed.end()) {
                result.push_back(needed.find(target - nums[i])->second);
                result.push_back(i);
                break;
            }
            needed[nums[i]] = i;
        }
        return result;
    }
};