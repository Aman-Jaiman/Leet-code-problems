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
    bool helper(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        // If leaf node, check remaining sum
        if (!root->left && !root->right)
            return targetSum == root->val;

        return helper(root->left, targetSum - root->val) ||
               helper(root->right, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};