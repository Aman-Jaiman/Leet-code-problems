#include <iostream>

using namespace std;

// Definition for binary tree node
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:

    // Search value in BST
    TreeNode* searchBST(TreeNode* root, int val) {

        // value not found
        if(!root)
            return nullptr;

        // value found
        if(val == root->val)
            return root;

        // search in left subtree
        else if(val < root->val)
            return searchBST(root->left, val);

        // search in right subtree
        return searchBST(root->right, val);
    }
};

int main() {

    /*
              4
            /   \
           2     7
          / \
         1   3
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int target = 2;

    TreeNode* ans = obj.searchBST(root, target);

    if(ans) {
        cout << "Value found: " << ans->val << endl;
    }
    else {
        cout << "Value not found" << endl;
    }

    return 0;
}