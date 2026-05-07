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

//recusive approch
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

//itative approch using 2 stack --- stack1 to store root and stack2 store poped elemet from stack1 to maintain reverse order push Root in stack1 , pop root and push in stack2 and at same time push element in stack1 Left and Right of the Root   


// iterative approch using single stack --- same as 2 stack but insted of second stack we will use array reversing
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        stack<TreeNode*>st2;
        st.push(root);
        while(!st.empty()){
            TreeNode* node =st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
