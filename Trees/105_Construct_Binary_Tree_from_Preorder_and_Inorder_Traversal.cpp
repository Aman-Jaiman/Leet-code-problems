#include <iostream>
#include <vector>

using namespace std;

// Definition for Binary Tree Node
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        // base case
        if(preorder.empty() || inorder.empty())
            return nullptr;

        // first preorder element is root
        int ele = preorder[0];

        TreeNode* root = new TreeNode(ele);

        // find root index in inorder
        int idx = 0;

        while(inorder[idx] != ele) {
            idx++;
        }

        // left subtree inorder
        vector<int> leftIn(
            inorder.begin(),
            inorder.begin() + idx
        );

        // right subtree inorder
        vector<int> rightIn(
            inorder.begin() + idx + 1,
            inorder.end()
        );

        // left subtree preorder
        vector<int> leftPre(
            preorder.begin() + 1,
            preorder.begin() + 1 + idx
        );

        // right subtree preorder
        vector<int> rightPre(
            preorder.begin() + 1 + idx,
            preorder.end()
        );

        // build left subtree
        root->left = buildTree(leftPre, leftIn);

        // build right subtree
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};

// Inorder Traversal for checking
void inorderPrint(TreeNode* root) {

    if(!root)
        return;

    inorderPrint(root->left);

    cout << root->val << " ";

    inorderPrint(root->right);
}

int main() {

    /*
            3
           / \
          9  20
            /  \
           15   7
    */

    vector<int> preorder = {3,9,20,15,7};

    vector<int> inorder = {9,3,15,20,7};

    Solution obj;

    TreeNode* root =
        obj.buildTree(preorder, inorder);

    cout << "Inorder Traversal: ";

    inorderPrint(root);

    return 0;
}