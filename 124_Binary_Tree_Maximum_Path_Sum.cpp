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
    int sum = INT_MIN;

    int helper(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        // Path that passes through current node (can take both sides)
        int currentPath = root->val + max(0, left) + max(0, right);

        // Update global maximum
        sum = max(sum, currentPath);

        // Return path to parent (only one side allowed)
        return root->val + max(0, max(left, right));
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return sum;
    }
};
