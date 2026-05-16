#include <iostream>

using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    // Function to check Children Sum Property
    bool isSumProperty(Node *root) {

        // empty node or leaf node
        // always satisfies property
        if(!root || (!root->left && !root->right))
            return true;

        // get left child value
        long long left =
            (root->left) ? root->left->data : 0;

        // get right child value
        long long right =
            (root->right) ? root->right->data : 0;

        // current node must equal
        // sum of left + right child
        if(root->data != (int)(left + right))
            return false;

        // recursively check subtrees
        return isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};

int main() {

    /*
              10
             /  \
            8    2
           / \    
          3   5
    */

    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(5);

    Solution obj;

    bool ans = obj.isSumProperty(root);

    if(ans)
        cout << "Children Sum Property Satisfied";
    else
        cout << "Children Sum Property Not Satisfied";

    return 0;
}