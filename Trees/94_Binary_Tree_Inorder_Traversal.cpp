/*
LeetCode Question 94: Binary Tree Inorder Traversal

Problem Statement:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Inorder Traversal Rule:
LEFT → ROOT → RIGHT

Example:
Input:  root = [1,null,2,3]
Output: [1,3,2]

Constraints:
- The number of nodes in the tree is in the range [0, 100].
- Node values are between -100 and 100.
*/

/**
 * Definition for a binary tree node.
 */
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//using recursive
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

//using itrative approch
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            // go to leftmost node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val); // visit node

            curr = curr->right; // move to right subtree
        }

        return ans;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        inorder(root->left, ans);     // Left
        ans.push_back(root->val);     // Root
        inorder(root->right, ans);    // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
