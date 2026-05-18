#include <iostream>
using namespace std;

/*
    Definition of Binary Tree Node
*/
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* deleteNode(TreeNode* root, int key) {

    // base case
    if (!root) {
        return nullptr;
    }

    // node found
    if (root->val == key) {

        // CASE 1:
        // node has 0 or 1 child
        if (!root->left || !root->right) {

            // store existing child
            TreeNode* temp =
                (root->left)
                ? root->left
                : root->right;

            // delete current node
            delete root;

            return temp;
        }

        // CASE 2:
        // node has 2 children
        else {

            // find inorder successor
            // smallest node in right subtree
            TreeNode* temp = root->right;

            while (temp->left) {
                temp = temp->left;
            }

            // replace current node value
            root->val = temp->val;

            // delete duplicate successor node
            root->right =
                deleteNode(root->right, temp->val);
        }
    }

    // move to left subtree
    else if (root->val > key) {

        root->left =
            deleteNode(root->left, key);
    }

    // move to right subtree
    else {

        root->right =
            deleteNode(root->right, key);
    }

    return root;
}


