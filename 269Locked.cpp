//
// Created by arsen on 01.11.2025.
//
#include <iostream>

#include <ostream>
#include <stack>
#include <string>
#include <vector>
class Solution {
   public:
    bool dfs(int v, const std::vector<std::vector<int>>& adj, std::vector<int>& visited, std::stack<int>& stack) {
        visited[v] = 1;
        for (int u : adj[v]) {
            if (visited[u] == 1) {
                return false;
            }
            if (visited[u] == 0 && !dfs(u, adj, visited, stack)) {
                return false;
            }
        }
        visited[v] = 2;
        stack.push(v);
        return true;
    }

    std::string alienOrder(std::vector<std::string>& words) {
        std::vector<bool> present(26, false);
        for (auto& word : words) {
            for (auto& c : word) {
                present[c - 'a'] = true;
            }
        }
        std::vector<std::vector<int>> adj(26);
        for (int i = 0; i < words.size() - 1; ++i) {
            bool found = false;
            for (int k = 0; k < std::min(words[i].length(), words[i + 1].length()); ++k) {
                if (words[i][k] != words[i + 1][k]) {
                    adj[words[i][k] - 'a'].push_back(words[i + 1][k] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && words[i].length() > words[i + 1].length()) {
                return "";
            }
        }
        std::vector<int> visited(26, 0);
        std::stack<int> stack;
        for (int i = 0; i < 26; ++i) {
            if (present[i] && visited[i] == 0) {
                if (!dfs(i, adj, visited, stack)) {
                    return "";
                }
            }
        }
        std::string res;
        while (!stack.empty()) {
            res.push_back(static_cast<char>(stack.top() + 'a'));
            stack.pop();
        }
        return res;
    }
};