//
// Created by arsen on 25.06.2025.
//
#include <string>
#include <vector>
class Solution {
   public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> answer;
        for (int i = 1; i < n + 1; ++i) {
            bool divisible_by_3 = i % 3 == 0;
            bool divisible_by_5 = i % 5 == 0;
            bool divisible_by_15 = i % 15 == 0;
            if (divisible_by_15) {
                answer.push_back("FizzBuzz");
            } else if (divisible_by_3) {
                answer.push_back("Fizz");
            } else if (divisible_by_5) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(std::to_string(i));
            }
        }
        return answer;
    }
};