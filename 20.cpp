//
// Created by arsen on 19.10.2025.
//
#include <string>
#include <stack>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) {
                    return false;
                }
                if ((stack.top() == '(' && c == ')') || (stack.top() == '{' && c == '}') || (stack.top() == '[' && c == ']')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};