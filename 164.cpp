//
// Created by arsen on 29.11.2025.
//
#include <algorithm>
#include <vector>
#include <cstdint>
class Solution {
    void CountingSort(std::vector<int>& input, int place) {
        std::vector<int> counter(256, 0);
        std::vector<int> output(input.size());
        for (int i = 0; i < input.size(); i++) {
            counter[input[i] / place % 256]++;
        }
        int sum = 0;
        for (int i = 0; i < 256; i++) {
            int tmp = counter[i];
            counter[i] = sum;
            sum += tmp;
        }
        for (int i = 0; i < input.size(); i++) {
            output[counter[input[i] / place % 256]] = input[i];
            counter[input[i] / place % 256]++;
        }
        input.swap(output);
    }
    void RadixSort(std::vector<int>& A) {
        int max = *std::max_element(A.begin(), A.end());
        for (int64_t div = 1; max / div > 0; div *= 256) {
            CountingSort(A, div);
        }
    }
public:
    int maximumGap(std::vector<int>& nums) {
        RadixSort(nums);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            result = std::max(result, nums[i] - nums[i - 1]);
        }
        return result;
    }
};