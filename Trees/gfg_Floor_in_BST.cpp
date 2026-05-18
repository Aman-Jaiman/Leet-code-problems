#include <iostream>
using namespace std;

/*
    Definition of BST Node
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
    Insert node into BST
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
    Find Floor in BST

    Floor = greatest value <= k
*/
int findFloor(Node* root, int k) {

    // stores answer
    int floor = -1;

    // start traversal from root
    Node* curr = root;

    while (curr != nullptr) {

        // exact value found
        if (curr->data == k) {
            return k;
        }

        // current value smaller than k
        // it can be a possible floor
        if (curr->data < k) {

            floor = curr->data;

            // try finding larger valid floor
            // in right subtree
            curr = curr->right;
        }

        // current value greater than k
        // move left
        else {
            curr = curr->left;
        }
    }

    return floor;
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

    int k;

    cout << "Enter value: ";
    cin >> k;

    int ans = findFloor(root, k);

    if (ans == -1) {
        cout << "Floor does not exist" << endl;
    }
    else {
        cout << "Floor of " << k << " is: " << ans << endl;
    }

    return 0;
}