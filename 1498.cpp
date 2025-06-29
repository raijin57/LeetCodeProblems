//
// Created by arsen on 29.06.2025.
//
#include <algorithm>
#include <vector>
class Solution {
   public:
    int numSubseq(std::vector<int> &nums, int target) {
        constexpr auto MOD = 1000000007;

        std::sort(nums.begin(), nums.end());

        int begin = 0;
        int end = static_cast<int>(nums.size() - 1);
        int result = 0;

        std::vector<int> pow2(nums.size() + 1, 1);
        for (int i = 1; i <= nums.size(); ++i) {
            pow2[i] = (pow2[i - 1] * static_cast<int64_t>(2)) % MOD;
        }

        while (begin <= end) {
            if (nums[begin] + nums[end] <= target) {
                result = (result + pow2[end - begin]) % MOD;
                ++begin;
            } else {
                --end;
            }
        }
        return result;
    }
};