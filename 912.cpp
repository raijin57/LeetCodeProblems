//
// Created by arsen on 29.11.2025.
//
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdint>
class Solution {
    void CountingSort(std::vector<int>& input, int place, int min) {
        std::vector counter(256, 0);
        std::vector<int> output(input.size());
        for (int i = 0; i < input.size(); i++) {
            counter[(input[i] - min) / place % 256]++;
        }
        int sum = 0;
        for (int i = 0; i < 256; i++) {
            int tmp = counter[i];
            counter[i] = sum;
            sum += tmp;
        }
        for (int i = 0; i < input.size(); i++) {
            output[counter[(input[i] - min) / place % 256]] = input[i];
            counter[(input[i] - min) / place % 256]++;
        }
        input.swap(output);
    }

    void RadixSort(std::vector<int>& A) {
        const auto minmax = std::minmax_element(A.begin(), A.end());
        const int max = *minmax.second;
        const int min = *minmax.first;
        for (int64_t div = 1; (max - min) / div > 0; div *= 256) {
            CountingSort(A, div, min);
        }
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        RadixSort(nums);
        return nums;
    }
};