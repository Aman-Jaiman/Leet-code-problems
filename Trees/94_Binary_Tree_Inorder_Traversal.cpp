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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

// Morris travesal or Threaded Binary tree traversal
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        // vector to store inorder traversal
        vector<int> inorder;

        // start traversal from root
        TreeNode* curr = root;

        // continue until all nodes are visited
        while (curr != nullptr) {

            // CASE 1:
            // If left child does not exist,
            // visit current node and move right
            if (curr->left == nullptr) {

                // inorder => Left Root Right
                // since left does not exist,
                // directly visit root
                inorder.push_back(curr->val);

                // move to right subtree
                curr = curr->right;
            }

            // CASE 2:
            // left child exists
            else {

                // find inorder predecessor
                // predecessor = rightmost node
                // in left subtree
                TreeNode* prev = curr->left;

                // move to rightmost node
                // stop if:
                // 1. right becomes NULL
                // 2. thread already points to curr
                while (prev->right != nullptr &&
                       prev->right != curr) {

                    prev = prev->right;
                }

                // SUBCASE A:
                // thread not created yet
                if (prev->right == nullptr) {

                    // create temporary thread
                    // so we can return back later
                    prev->right = curr;

                    // move to left subtree
                    curr = curr->left;
                }

                // SUBCASE B:
                // thread already exists
                else {

                    // remove temporary thread
                    // restore original tree
                    prev->right = nullptr;

                    // now visit current node
                    // because left subtree
                    // has already been processed
                    inorder.push_back(curr->val);

                    // move to right subtree
                    curr = curr->right;
                }
            }
        }

        // return inorder traversal
        return inorder;
    }
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

//using recursive
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
