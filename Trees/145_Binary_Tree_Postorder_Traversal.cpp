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
    vector<int> ans;

    // Helper function for postorder traversal
    void postOrder(TreeNode* root) {
        if (root == nullptr) return;

        postOrder(root->left);     // LEFT
        postOrder(root->right);    // RIGHT
        ans.push_back(root->val);  // ROOT
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
