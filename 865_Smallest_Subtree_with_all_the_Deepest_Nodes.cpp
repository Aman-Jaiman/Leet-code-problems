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
    // Function to calculate depth of a tree
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // If both sides have same depth, root is the answer
        if (leftDepth == rightDepth)
            return root;

        // Otherwise go to deeper subtree
        if (leftDepth > rightDepth)
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
};
