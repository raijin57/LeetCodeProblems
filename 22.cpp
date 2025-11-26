//
// Created by arsen on 26.11.2025.
//
#include <string>
#include <vector>
class Solution {
    void recursion(int left, int right, std::string s, int n, std::vector<std::string>& res) {
        if (left == right && left + right == 2 * n) {
            res.push_back(s);
            return;
        }
        if (left < n) {
            recursion(left + 1, right, s + "(", n, res);
        }
        if (right < left) {
            recursion(left, right + 1, s + ")", n, res);
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        recursion(0, 0, "", n, res);
        return res;
    }
};