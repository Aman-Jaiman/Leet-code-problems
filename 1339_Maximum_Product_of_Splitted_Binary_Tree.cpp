/*
Problem: Maximum Product of Splitted Binary Tree

Given the root of a binary tree, split the binary tree by removing
exactly one edge such that the product of the sums of the two
resulting subtrees is maximized.

Return the maximum product modulo 1e9 + 7.

LeetCode Problem: 1339
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    // Step 1: calculate total sum of tree
    long long getTotalSum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Step 2: postorder traversal to compute subtree sums
    long long helper(TreeNode* root) {
        if (root == nullptr) return 0;

        long long leftSum = helper(root->left);
        long long rightSum = helper(root->right);

        long long subTreeSum = leftSum + rightSum + root->val;

        // Calculate product by cutting above this subtree
        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root); // must be done first
        helper(root);
        return maxProd % MOD;
    }
};

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \
          4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Maximum Product: " << sol.maxProduct(root) << endl;

    return 0;
}
