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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            std::swap(node->left, node->right);

            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
};