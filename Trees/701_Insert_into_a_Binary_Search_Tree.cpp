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

/*
    Insert a value into BST
*/
TreeNode* insertIntoBST(TreeNode* root, int val) {

    // create new node
    TreeNode* node = new TreeNode(val);

    // if tree is empty
    if (root == nullptr) {
        return node;
    }

    // start traversal from root
    TreeNode* curr = root;

    while (curr != nullptr) {

        // move to left subtree
        if (curr->val > val) {

            // if left child exists
            // continue traversal
            if (curr->left != nullptr) {
                curr = curr->left;
            }

            // insert here
            else {
                curr->left = node;
                break;
            }
        }

        // move to right subtree
        else {

            // if right child exists
            // continue traversal
            if (curr->right != nullptr) {
                curr = curr->right;
            }

            // insert here
            else {
                curr->right = node;
                break;
            }
        }
    }

    return root;
}

/*
    Inorder Traversal
    (prints BST in sorted order)
*/
void inorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

int main() {

    TreeNode* root = nullptr;

    /*
        Insert values into BST
    */

    root = insertIntoBST(root, 8);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 14);

    cout << "BST Inorder Traversal:" << endl;

    inorder(root);

    cout << endl;

    return 0;
}