//
// Created by arsen on 19.11.2025.
//
#include <vector>
#include <string>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            if (i == 0) {
                ans = strs[i];
            }
            int len = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (ans[j] == strs[i][j]) {
                    len++;
                }
            }
            ans = ans.substr(0, len);
        }
        return ans;
    }
};