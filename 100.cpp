//
// Created by arsen on 30.10.2025.
//
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        std::queue<TreeNode*> queue1;
        std::queue<TreeNode*> queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* temp1 = queue1.front();
            TreeNode* temp2 = queue2.front();
            queue1.pop();
            queue2.pop();
            if (temp1 == nullptr && temp2 == nullptr) {
                continue;
            }
            if (temp1 == nullptr || temp2 == nullptr || temp1->val != temp2->val) {
                return false;
            }
            queue1.push(temp1->left);
            queue1.push(temp1->right);
            queue2.push(temp2->left);
            queue2.push(temp2->right);
        }
        return queue1.empty() && queue2.empty();
    }
};