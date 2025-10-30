//
// Created by arsen on 30.10.2025.
//
#include <cstddef>
#include <iostream>
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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        std::queue<TreeNode*> queueLeft;
        std::queue<TreeNode*> queueRight;
        queueLeft.push(root->left);
        queueRight.push(root->right);
        while (!queueLeft.empty() && !queueRight.empty()) {
            TreeNode* left = queueLeft.front();
            TreeNode* right = queueRight.front();
            queueLeft.pop();
            queueRight.pop();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            queueLeft.push(left->left);
            queueLeft.push(left->right);
            queueRight.push(right->right);
            queueRight.push(right->left);
        }
        return queueLeft.empty() && queueRight.empty();
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    root.left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root.right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    std::cout << s.isSymmetric(&root);
    return 0;
}