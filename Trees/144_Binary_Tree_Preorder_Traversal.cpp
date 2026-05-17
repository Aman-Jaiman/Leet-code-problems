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

//Morris traversal 
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {

        // vector to store preorder traversal
        vector<int> preorder;

        // start traversal from root
        TreeNode* curr = root;

        // continue until all nodes are visited
        while (curr != nullptr) {

            // CASE 1:
            // if left child does not exist
            if (curr->left == nullptr) {

                // preorder = Root Left Right
                // so directly visit current node
                preorder.push_back(curr->val);

                // move to right subtree
                curr = curr->right;
            }

            // CASE 2:
            // left child exists
            else {

                // find inorder predecessor
                // (rightmost node in left subtree)
                TreeNode* prev = curr->left;

                // move to rightmost node
                // stop if:
                // 1. right becomes NULL
                // 2. thread already points to curr
                while (prev->right &&
                       prev->right != curr) {

                    prev = prev->right;
                }

                // SUBCASE A:
                // thread does not exist
                if (prev->right == nullptr) {

                    // preorder visits root BEFORE left subtree
                    preorder.push_back(curr->val);

                    // create temporary thread
                    // so we can come back later
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

                    // left subtree already processed
                    // now move to right subtree
                    curr = curr->right;
                }
            }
        }

        // return preorder traversal
        return preorder;
    }
};

//recursive approch
class Solution {
public:
    vector<int> ans;

    // Helper function (void because we are filling ans)
    void preorder(TreeNode* root) {
        if (root == nullptr) return;

        ans.push_back(root->val);   // ROOT
        preorder(root->left);       // LEFT
        preorder(root->right);      // RIGHT
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

//itrative approch
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
        }
        return ans;
    }
};