//
// Created by arsen on 25.06.2025.
//
class Solution {
public:
  int numberOfSteps(int num) {
    if (num == 0) {
      return num;
    } else if (num % 2 == 0) {
      return 1 + numberOfSteps(num / 2);
    } else {
      return 1 + numberOfSteps(num - 1);
    }
  }
};