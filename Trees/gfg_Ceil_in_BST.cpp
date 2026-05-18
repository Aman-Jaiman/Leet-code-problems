#include <iostream>
using namespace std;

/*
    Definition of Binary Search Tree Node
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

/*
    Insert node in BST
*/
Node* insert(Node* root, int val) {

    // if tree is empty
    if (root == nullptr) {
        return new Node(val);
    }

    // insert in left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }

    // insert in right subtree
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

/*
    Find Ceil in BST
    Ceil = smallest value >= x
*/
int findCeil(Node* root, int x) {

    // stores answer
    int ceil = -1;

    // start traversal from root
    Node* curr = root;

    while (curr != nullptr) {

        // exact value found
        if (curr->data == x) {
            return curr->data;
        }

        // current node can be a ceil
        if (curr->data > x) {

            // store possible answer
            ceil = curr->data;

            // try to find smaller valid ceil
            curr = curr->left;
        }

        // move right if current value < x
        else {
            curr = curr->right;
        }
    }

    return ceil;
}

int main() {

    Node* root = nullptr;

    /*
            8
          /   \
         4     12
        / \    / \
       2   6  10 14
    */

    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);

    int x;

    cout << "Enter value: ";
    cin >> x;

    int ans = findCeil(root, x);

    if (ans == -1) {
        cout << "Ceil does not exist" << endl;
    }
    else {
        cout << "Ceil of " << x << " is: " << ans << endl;
    }

    return 0;
}