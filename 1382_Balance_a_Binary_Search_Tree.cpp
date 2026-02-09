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
    vector<TreeNode*> arr;

    // inorder traversal to store nodes in sorted order
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }

    // build balanced BST from sorted nodes
    TreeNode* build(int st, int end) {
        if (st > end) return nullptr;

        int mid = st + (end - st) / 2;
        TreeNode* curr = arr[mid];

        curr->left = build(st, mid - 1);
        curr->right = build(mid + 1, end);

        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);                       // fill arr
        return build(0, arr.size() - 1);     // build balanced BST
    }
};

