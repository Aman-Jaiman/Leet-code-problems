#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
        // Both null -> symmetric
        if (p == nullptr && q == nullptr) return true;

        // One null or values differ -> not symmetric
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        // Check mirror condition
        return helper(p->left, q->right) &&
               helper(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }
};
