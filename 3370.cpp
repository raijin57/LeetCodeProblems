//
// Created by arsen on 29.10.2025.
//
class Solution {
public:
    int twosPower(const int n) {
        int two = 2;
        while (two <= n) {
            two *= 2;
        }
        return two;
    }
    int smallestNumber(int n) {
        return twosPower(n) - 1;
    }
};