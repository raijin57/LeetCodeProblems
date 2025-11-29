//
// Created by arsen on 29.11.2025.
//
#include <vector>
#include <string>
#include <unordered_map>
class Solution {
    void backtrack(int i, std::string& cur, std::vector<std::string>& res, std::string& string,
                   std::unordered_map<char, std::string>& map) {
        if (i == string.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : map[string[i]]) {
            cur.push_back(c);
            backtrack(i + 1, cur, res, string, map);
            cur.pop_back();
        }
    }

   public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::unordered_map<char, std::string> letters{{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                                      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        std::vector<std::string> res;
        std::string cur;
        backtrack(0, cur, res, digits, letters);
        return res;
    }
};