//
// Created by arsen on 14.09.2025.
//
#include <iostream>

#include <ostream>
#include <unordered_map>
#include <vector>
//* class Solution {
//* public:
//*     int subarraySum(std::vector<int>& nums, int k) {
//*         int answer = 0;
//*         int count = 0;
//*         int start = 0;
//*         for (int i = 0; i < nums.size(); i++) {
//*             start = i;
//*             count = 0;
//*             while (start < nums.size()) {
//*                 count += nums[start];
//*                 if (count == k) {
//*                     answer += 1;
//*                 }
//*                 start++;
//*             }
//*         }
//*         return answer;
//*     }
//* };

// ! Теперь прочитав про префиксные суммы !

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        std::unordered_map<int, int> freq;
        freq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (freq.count(sum - k)) {
                count += freq[sum - k];
            }
            ++freq[sum];
        }
        return count;
    }
};